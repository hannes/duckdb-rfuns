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

binary_sql <- function(x, y, fun, con) {
  project <- binary_project(x, y, op, con = con)
  duckdb$rel_to_sql(project)
}
