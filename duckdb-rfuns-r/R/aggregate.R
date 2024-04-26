#' aggregate functions
#'
#' @param x vector
#' @param ... passed down, e.g. na.rm
#'
#' @examples
#' rfuns_sum(1:10, na.rm = FALSE)
#' rfuns_min(1:10, na.rm = FALSE)
#' rfuns_max(1:10, na.rm = FALSE)
#'
#' @rdname aggregate
#' @export
rfuns_sum <- function(x, ...) {
  rfuns_aggregate("sum", tibble(x = x), ...)
}

#' @rdname aggregate
#' @export
rfuns_min <- function(x, ...) {
  rfuns_aggregate("min", tibble(x = x), ...)
}

#' @rdname aggregate
#' @export
rfuns_max <- function(x, ...) {
  rfuns_aggregate("max", tibble(x = x), ...)
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

