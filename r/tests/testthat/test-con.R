test_that("con() load the extension", {
  con <- local_con()

  expect_equal(dbGetQuery(con, 'SELECT "r_base::+"(1, 2)')[,1], 3)
})
