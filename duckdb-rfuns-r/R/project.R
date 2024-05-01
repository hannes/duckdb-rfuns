#' is.na()
#'
#' @param x vector
#'
#' @export
rfuns_is.na <- function(x) {
  rfuns("project", "is.na", tibble(x = x))
}
