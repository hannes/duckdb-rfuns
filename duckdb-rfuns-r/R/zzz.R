# silence R CMD check
# TODO: some of these are testthat only dependencies
#' @importFrom tibble tibble as_tibble
#' @importFrom constructive construct
#' @importFrom withr defer_parent
#' @importFrom purrr map
#' @importFrom glue glue
#' @import DBI
#' @import rlang
NULL

.onLoad <- function(lib, pkg) {
  run_on_load()
}

duckdb <- NULL
on_load(
  duckdb <- asNamespace("duckdb")
)

