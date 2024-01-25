test_that("con() load the extension", {
  con <- con(); on.exit(dbDisconnect(con, shutdown=TRUE))

  expect_equal(dbGetQuery(con, 'SELECT "r_base::+"(1, 2)')[,1], 3)
})
