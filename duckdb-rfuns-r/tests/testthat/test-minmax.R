
test_that("r_base::min+max(<INTEGER>)", {
  expect_equal(rfuns_min(1:10), 1)
  expect_equal(rfuns_min(c(1:10, NA)), 1)

  expect_equal(rfuns_min(c(1:10, NA), na.rm = TRUE), 1L)
  expect_equal(rfuns_min(c(1:10, NA), na.rm = FALSE), NA_integer_)

  expect_equal(rfuns_min(integer(), na.rm = FALSE), NA_integer_)
  expect_equal(rfuns_min(integer(), na.rm = TRUE), NA_integer_)

  expect_equal(rfuns_min(NA_integer_, na.rm = TRUE), NA_integer_)
  expect_equal(rfuns_min(NA_integer_, na.rm = FALSE), NA_integer_)

  expect_equal(rfuns_max(1:10), 10L)
  expect_equal(rfuns_max(c(1:10, NA)), 10L)

  expect_equal(rfuns_max(c(1:10, NA), na.rm = TRUE), 10L)
  expect_equal(rfuns_max(c(1:10, NA), na.rm = FALSE), NA_integer_)

  expect_equal(rfuns_max(integer(), na.rm = FALSE), NA_integer_)
  expect_equal(rfuns_max(integer(), na.rm = TRUE), NA_integer_)

  expect_equal(rfuns_max(NA_integer_, na.rm = TRUE), NA_integer_)
  expect_equal(rfuns_max(NA_integer_, na.rm = FALSE), NA_integer_)

})

test_that("r_base::min+max(<DOUBLE>)", {
  expect_equal(rfuns_min(c(1, 2, 3)), 1)
  expect_equal(rfuns_min(c(1, 2, 3, NA)), 1)

  expect_equal(rfuns_min(c(1, 2, 3, NA), na.rm = TRUE), 1)
  expect_equal(rfuns_min(c(1, 2, 3, NA), na.rm = FALSE), NA_real_)

  expect_equal(rfuns_min(double(), na.rm = FALSE), NA_real_)
  expect_equal(rfuns_min(double(), na.rm = TRUE), NA_real_)

  expect_equal(rfuns_min(NA_real_, na.rm = TRUE), NA_real_)
  expect_equal(rfuns_min(NA_real_, na.rm = FALSE), NA_real_)

  expect_equal(rfuns_max(c(1, 2, 3)), 3)
  expect_equal(rfuns_max(c(1, 2, 3, NA)), 3)

  expect_equal(rfuns_max(c(1, 2, 3, NA), na.rm = TRUE), 3)
  expect_equal(rfuns_max(c(1, 2, 3, NA), na.rm = FALSE), NA_real_)

  expect_equal(rfuns_max(double(), na.rm = FALSE), NA_real_)
  expect_equal(rfuns_max(double(), na.rm = TRUE), NA_real_)

  expect_equal(rfuns_max(NA_real_, na.rm = TRUE), NA_real_)
  expect_equal(rfuns_max(NA_real_, na.rm = FALSE), NA_real_)

})

test_that("r_base::min+max(<VARCHAR>", {
  expect_snapshot(error = TRUE, rfuns_sum("HufflePuff"))
})
