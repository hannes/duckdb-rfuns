#' Open a connection to duckdb with the rfuns extension loaded
#'
#' @return a duckdb connection
#' @rdname duckdb_con
con <- function() {
  con <- DBI::dbConnect(duckdb::duckdb(config=list('allow_unsigned_extensions' = 'true')))
  extension <- system.file("extension", "rfuns.duckdb_extension", package = "duckdbrfuns")
  DBI::dbExecute(con, paste0("LOAD '", extension, "'"))
  con
}
