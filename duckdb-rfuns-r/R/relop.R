binary_project <- function(x, y, fun, con) {
  experimental <- FALSE
  df1 <- data.frame(a = x, b = y)

  rel1 <- duckdb$rel_from_df(con, df1, experimental = experimental)
  duckdb$rel_project(
    rel1,
    list(
      {
        tmp_expr <- duckdb$expr_reference("a")
        duckdb$expr_set_alias(tmp_expr, "a")
        tmp_expr
      },
      {
        tmp_expr <- duckdb$expr_reference("b")
        duckdb$expr_set_alias(tmp_expr, "b")
        tmp_expr
      },
      {
        tmp_expr <- duckdb$expr_function(fun, list(duckdb$expr_reference("a"), duckdb$expr_reference("b")))
        # duckdb$expr_set_alias(tmp_expr, alias)
        tmp_expr
      }
    )
  )
}

binary_altrep <- function(x, y, fun, con) {
  project <- binary_project(x, y, fun, con = con)
  df <- duckdb$rel_to_altrep(project)
  df
}

binary_dispatch <- function(x, y, fun = "", con = local_duckdb_con()) {
  binary_altrep(x, y, glue("dispatch(r_base::{fun})"), con = con)[, 3][]
}

spaceship_r <- function(x, y, ops = c("==", "!=", "<", "<=", ">", ">="), keep.data = FALSE) {
  df1 <- tibble(x, y)

  spaceship <- suppressWarnings(as_tibble(list2(
    !!!map(set_names(ops), \(op) {
      rlang::expr(!!get(op)(x, y))
    })
  )))

  if (keep.data) {
    spaceship <- append(list(x = x, y = y), spaceship)
  }

  spaceship
}

spaceship_rfuns <- function(x, y, ops = c("==", "!=", "<", "<=", ">", ">="), keep.data = FALSE, error_call = current_env()) {
  con <- local_duckdb_con()

  experimental <- FALSE
  df1 <- tibble(x, y)
  rel1 <- duckdb$rel_from_df(con, df1, experimental = experimental)

  exprs <- list2(
    duckdb$expr_reference("x"),
    duckdb$expr_reference("y"),
    !!!map(ops, \(op) {
      tmp_expr <- duckdb$expr_function(glue("r_base::{op}"), list(duckdb$expr_reference("x"), duckdb$expr_reference("y")))
      duckdb$expr_set_alias(tmp_expr, op)
      tmp_expr
    })
  )

  proj <- withCallingHandlers(
    duckdb$rel_project(rel1, exprs),
    error = function(err) {
      cli_abort("binding error", call = error_call, parent = err)
    }
  )

  spaceship <- withCallingHandlers(
    as_tibble(
      map(duckdb$rel_to_altrep(proj), \(col) col[])
    ),
    error = function(err) {
      cli_abort("runtime error", call = error_call, parent = err)
    }
  )

  if (!keep.data) {
    spaceship <- spaceship[, -c(1, 2)]
  }
  spaceship
}

spaceship <- function(x, y, ops = c("==", "!=", "<", "<=", ">", ">=")) {
  df <- as.data.frame(rbind(
    spaceship_r(x, y, ops, keep.data = TRUE),
    spaceship_rfuns(x, y, ops, keep.data = TRUE)
  ))
  row.names(df) <- c("r", "rfuns")
  df
}
