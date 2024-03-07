# silence R CMD check
# TODO: some of these are testthat only dependencies
#' @importFrom tibble tibble
#' @importFrom constructive construct
#' @importFrom withr defer_parent
#' @importFrom DBI dbConnect dbDisconnect dbGetQuery
#' @importFrom rlang run_on_load on_load
NULL

.onLoad <- function(lib, pkg) {
  run_on_load()
}

duckdb <- NULL
on_load(
  duckdb <- asNamespace("duckdb")
)

