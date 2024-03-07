relop_project <- function(x, y, op = c("<", "<=", ">", ">=", "==", "!=")) {
  op <- rlang::arg_match(op)
  fun <- glue::glue("r_base::{op}")

  experimental <- FALSE
  con <- duckdbrfuns:::con()
  withr::defer(dbDisconnect(con, shutdown=TRUE))

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
        duckdb$expr_set_alias(tmp_expr, "a < b")
        tmp_expr
      }
    )
  )
}
