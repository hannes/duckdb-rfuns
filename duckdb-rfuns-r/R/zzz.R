# silence R CMD check
# TODO: some of these are testthat only dependencies
#' @importFrom tibble tibble
#' @importFrom constructive construct
#' @importFrom withr defer_parent
#' @importFrom DBI dbConnect dbDisconnect dbGetQuery
NULL

duckdb <- asNamespace("duckdb")
