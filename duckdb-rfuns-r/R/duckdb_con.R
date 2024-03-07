#' Open a connection to duckdb with the rfuns extension loaded
#'
#' @return a duckdb connection
#' @rdname duckdb_con
duckdb_con <- function() {
  con <- DBI::dbConnect(duckdb::duckdb(config=list('allow_unsigned_extensions' = 'true')))
  extension <- system.file("extension", "rfuns.duckdb_extension", package = "duckdbrfuns")
  DBI::dbExecute(con, paste0("LOAD '", extension, "'"))
  con
}

local_duckdb_con <- function(envir = parent.frame()) {
  con <- duckdb_con()
  withr::defer(dbDisconnect(con, shutdown=TRUE), envir = envir)
  con
}

auto_duckdb_con <- function() {
  con <- duckdb_con()
  env <- new.env()
  env$con <- con
  attr(con, ".env") <- env

  reg.finalizer(env, function(e) {
    dbDisconnect(e$con, shutdown=TRUE)
  })

  con
}
