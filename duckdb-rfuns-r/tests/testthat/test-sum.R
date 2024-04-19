test_that("r_base::sum(<INTEGER>)", {
  expect_equal(rfuns_sum(1:10), 55)
  expect_equal(rfuns_sum(c(1:10, NA)), 55)

  expect_equal(rfuns_sum(c(1:10, NA), na.rm = TRUE), 55)

  # TODO: should be NA
  expect_equal(rfuns_sum(c(1:10, NA), na.rm = FALSE), 55)
})


test_that("r_base::sum(<DOUBLE>)", {
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3)), 6.6)
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA)), 6.6)

  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA), na.rm = TRUE), 6.6)

  # TODO: should be NA
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA), na.rm = FALSE), 6.6)
})

test_that("r_base::sum(<VARCHAR>", {
  expect_snapshot(error = TRUE, rfuns_sum("HufflePuff"))
})
