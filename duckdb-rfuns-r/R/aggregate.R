rfuns_sum <- function(x, na.rm = TRUE) {
  con <- local_duckdb_con()

  in_df <- tibble::tibble(x = x)
  in_rel <- duckdb:::rel_from_df(con, in_df)

  exprs <- list(
    duckdb:::expr_function(
      "r_base::sum",
      list(
        duckdb:::expr_reference("x"),
        duckdb:::expr_constant(TRUE)
      )
    )
  )

  agg <- duckdb:::rel_aggregate(in_rel, list(), exprs)

  withr::with_options(list(duckdb.materialize_message = FALSE), {
    duckdb:::rel_to_altrep(agg)[, 1][]
  })
}
