local_con <- function() {
  con <- con()
  withr::defer_parent(dbDisconnect(con, shutdown=TRUE))
  con
}
