#' aggregate functions
#'
#' @param x vector
#' @param na.rm should the missing values be removed
#'
#' @examples
#' rfuns_sum(1:10)
#' rfuns_min(1:10)
#' rfuns_max(1:10)
#'
#' @rdname aggregate
#' @export
rfuns_sum <- function(x, na.rm = TRUE) {
  rfuns_aggregate("sum", tibble(x = x), na.rm = na.rm)
}

#' @rdname aggregate
#' @export
rfuns_min <- function(x, na.rm = TRUE) {
  rfuns_aggregate("min", tibble(x = x), na.rm = na.rm)
}

#' @rdname aggregate
#' @export
rfuns_max <- function(x, na.rm = TRUE) {
  rfuns_aggregate("max", tibble(x = x), na.rm = na.rm)
}

rfuns_aggregate <- function(fun, data, ...) {
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

  agg <- duckdb:::rel_aggregate(in_rel, list(), exprs)

  withr::with_options(list(duckdb.materialize_message = FALSE), {
    duckdb:::rel_to_altrep(agg)[, 1][]
  })
}

