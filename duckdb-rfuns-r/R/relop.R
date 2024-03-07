#' @importFrom rlang caller_env arg_match current_env
relop_project <- function(x, y, op = c("<", "<=", ">", ">=", "==", "!="), error_call = current_env(), con = local_duckdb_con()) {
  op <- arg_match(op, error_call = error_call)
  fun <- glue::glue("r_base::{op}")
  alias <- glue::glue("a {op} b")

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
        duckdb$expr_set_alias(tmp_expr, alias)
        tmp_expr
      }
    )
  )
}

relop_altrep <- function(x, y, op = c("<", "<=", ">", ">=", "==", "!="), error_call = current_env(), con = duckdb_con()) {
  project <- relop_project(x, y, op, error_call = error_call, con = con)
  df <- duckdb$rel_to_altrep(project)
  attr(df, "con") <- con
  df
}

relop_sql <- function(x, y, op = c("<", "<=", ">", ">=", "==", "!="), error_call = current_env(), con = local_duckdb_con()) {
  project <- relop_project(x, y, op, error_call = error_call, con = con)
  duckdb$rel_to_sql(project)
}
