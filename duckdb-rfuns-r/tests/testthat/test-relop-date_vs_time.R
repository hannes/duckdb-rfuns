test_that("date <=> time", {
  con <- local_duckdb_con()

  time <- as.POSIXct(Sys.Date(), tz = "UTC")
  date <- Sys.Date()

  expect_snapshot(error = TRUE,
    binary_altrep(time, date, "r_base::==", con = con)
  )
  expect_snapshot(error = TRUE,
    binary_altrep(date, time, "r_base::==", con = con)
  )
})
