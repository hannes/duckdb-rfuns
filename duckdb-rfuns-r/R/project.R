#' @export
rfuns_is.na <- function(x) {
  rfuns_project("is.na", tibble(x = x))
}

rfuns_project <- function(fun, data, ..., error_call = caller_env()) {
  con <- local_duckdb_con()

  names(data) <- paste("x", seq_len(ncol(data)), sep = "")
  in_df <- as_tibble(data)
  in_rel <- duckdb:::rel_from_df(con, in_df)

  refs <- map(names(data), duckdb:::expr_reference)
  constants <- map(list2(...), duckdb:::expr_constant)

  exprs <- list(
    duckdb:::expr_function(
      paste0("r_base::", fun),
      list2(!!!refs, !!!constants)
    )
  )

  proj <- withCallingHandlers(
    duckdb:::rel_project(in_rel, exprs),
    error = function(err) {
      cli_abort("binding error", call = error_call, parent = err)
    }
  )

  withr::with_options(list(duckdb.materialize_message = FALSE), {
    withCallingHandlers(
      duckdb:::rel_to_altrep(proj)[, 1][],
      error = function(err) {
        cli_abort("runtime error", call = error_call, parent = err)
      }
    )
  })

}
