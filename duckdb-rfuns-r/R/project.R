#' is.na()
#'
#' @param x vector
#'
#' @export
rfuns_is.na <- function(x) {
  rfuns("project", "is.na", tibble(x = x))
}

#' as.integer()
#'
#' @param x vector
#'
#' @export
rfuns_as.integer <- function(x) {
  rfuns("project", "as.integer", tibble(x = x))
}
