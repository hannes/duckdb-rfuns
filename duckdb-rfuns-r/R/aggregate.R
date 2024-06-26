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
  rfuns("sum", tibble(x = x), ..., op = "aggregate")
}

#' @rdname aggregate
#' @export
rfuns_min <- function(x, ...) {
  rfuns("min", tibble(x = x), ..., op = "aggregate")
}

#' @rdname aggregate
#' @export
rfuns_max <- function(x, ...) {
  rfuns("max", tibble(x = x), ..., op = "aggregate")
}
