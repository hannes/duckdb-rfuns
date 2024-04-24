test_that("r_base::sum(<INTEGER>)", {
  expect_equal(rfuns_sum(1:10), 55)
  expect_equal(rfuns_sum(c(1:10, NA)), 55)

  expect_equal(rfuns_sum(c(1:10, NA), na.rm = TRUE), 55)
  expect_equal(rfuns_sum(c(1:10, NA), na.rm = FALSE), NA_integer_)

  expect_equal(rfuns_sum(integer(), na.rm = FALSE), 0L)
  expect_equal(rfuns_sum(integer(), na.rm = TRUE), 0L)

  expect_equal(rfuns_sum(NA_integer_, na.rm = TRUE), 0L)
  expect_equal(rfuns_sum(NA_integer_, na.rm = FALSE), NA_integer_)
})

test_that("r_base::sum(<DOUBLE>)", {
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3)), 6.6)
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA)), 6.6)

  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA), na.rm = TRUE), 6.6)
  expect_equal(rfuns_sum(c(1.1, 2.2, 3.3, NA), na.rm = FALSE), NA_real_)

  expect_equal(rfuns_sum(double(), na.rm = FALSE), 0)
  expect_equal(rfuns_sum(double(), na.rm = TRUE), 0)

  expect_equal(rfuns_sum(NA_real_, na.rm = TRUE), 0L)
  expect_equal(rfuns_sum(NA_real_, na.rm = FALSE), NA_real_)
})

test_that("r_base::sum(<VARCHAR>", {
  expect_snapshot(error = TRUE, rfuns_sum("HufflePuff"))
})