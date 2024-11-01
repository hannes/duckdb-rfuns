#' is.na()
#'
#' @param x vector
#'
#' @export
rfuns_is.na <- function(x) {
  rfuns("is.na", tibble(x = x))
}

#' as.integer()
#'
#' @param x vector
#'
#' @export
rfuns_as.integer <- function(x) {
  rfuns("as.integer", tibble(x = x))
}

#' as.numeric()
#'
#' @param x vector
#'
#' @export
rfuns_as.numeric <- function(x) {
  rfuns("as.numeric", tibble(x = x))
}

#' as.character()
#'
#' @param x vector
#'
#' @export
rfuns_as.character <- function(x) {
  rfuns("as.character", tibble(x = x))
}


#' %in%
#'
#' @param x vector
#' @param y constant
#'
#' @export
rfuns_in <- function(x, y) {
  rfuns("%in%", tibble(x = x), list(y))
}
