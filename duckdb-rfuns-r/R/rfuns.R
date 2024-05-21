rfuns <- function(fun, data, ..., error_call = caller_env()) {
  withr::local_options(list(duckdb.materialize_message = FALSE))
  con <- local_duckdb_con()

  in_rel <- duckdb:::rel_from_df(con, as_tibble(data))
  refs      <- map(names(data), duckdb:::expr_reference)
  constants <- map(list2(...), duckdb:::expr_constant)

  exprs <- list(
    duckdb:::expr_function(
      paste0("r_base::", fun),
      list2(!!!refs, !!!constants)
    )
  )

  op <- if (grepl("aggregate::", fun)) {
    "aggregate"
  } else {
    "project"
  }

  result <- switch(op,
    "project"   = duckdb:::rel_project(in_rel, exprs),
    "aggregate" = duckdb:::rel_aggregate(in_rel, list(), exprs)
  )                                      %!% "binding error"
  duckdb:::rel_to_altrep(result)[, 1][]  %!% "runtime error"
}
