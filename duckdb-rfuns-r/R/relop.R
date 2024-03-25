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

binary_sql <- function(x, y, fun, con) {
  project <- binary_project(x, y, op, con = con)
  duckdb$rel_to_sql(project)
}

spaceship <- function(x, y, ops = c("==", "!=", "<", "<=", ">", ">=")) {
  con <- local_duckdb_con()

  experimental <- FALSE
  df1 <- tibble(x, y)
  rel1 <- duckdb$rel_from_df(con, df1, experimental = experimental)

  proj <- duckdb$rel_project(rel1, list2(
    duckdb$expr_reference("x"),
    duckdb$expr_reference("y"),
    !!!map(ops, \(op) {
      tmp_expr <- duckdb$expr_function(glue("r_base::{op}"), list(duckdb$expr_reference("x"), duckdb$expr_reference("y")))
      duckdb$expr_set_alias(tmp_expr, op)
      tmp_expr
    })
  ))
  duck <- as_tibble(
    map(duckdb$rel_to_altrep(proj), \(col) col[])
  )

  r <- suppressWarnings(as_tibble(list2(
    x = x,
    y = y,
    !!!map(set_names(ops), \(op) {
      rlang::expr(!!get(op)(x, y))
    })
  )))

  out <- as.data.frame(rbind(duck, r))
  row.names(out) <- c("rfuns", "r")
  out
}
