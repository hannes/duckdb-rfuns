test_that("r_base::sum(<BOOLEAN>)", {
  x <- c(TRUE, TRUE, FALSE, NA)
  empty <- logical()

  expect_equal(rfuns_sum(x, na.rm = TRUE) , sum(x, na.rm = TRUE))
  expect_equal(rfuns_sum(x, na.rm = FALSE), sum(x, na.rm = FALSE))

  expect_equal(rfuns_sum(empty, na.rm = FALSE), sum(empty, na.rm = TRUE))
  expect_equal(rfuns_sum(empty, na.rm = TRUE) , sum(empty, na.rm = FALSE))
})

test_that("r_base::sum(<INTEGER>)", {
  x <- c(1L, 2L, 3L, NA)
  empty <- integer()

  expect_equal(rfuns_sum(x, na.rm = TRUE) , sum(x, na.rm = TRUE))
  expect_equal(rfuns_sum(x, na.rm = FALSE), sum(x, na.rm = FALSE))

  expect_equal(rfuns_sum(empty, na.rm = FALSE), sum(empty, na.rm = TRUE))
  expect_equal(rfuns_sum(empty, na.rm = TRUE) , sum(empty, na.rm = FALSE))
})

test_that("r_base::sum(<DOUBLE>)", {
  x <- c(1, 2, 3, NA)
  empty <- double()

  expect_equal(rfuns_sum(x, na.rm = TRUE) , sum(x, na.rm = TRUE))
  expect_equal(rfuns_sum(x, na.rm = FALSE), sum(x, na.rm = FALSE))

  expect_equal(rfuns_sum(empty, na.rm = FALSE), sum(empty, na.rm = TRUE))
  expect_equal(rfuns_sum(empty, na.rm = TRUE) , sum(empty, na.rm = FALSE))

})

test_that("r_base::sum(<?>, na.rm = <VARCHAR>)", {
  expect_snapshot(error = TRUE, rfuns_sum(c(TRUE, FALSE), na.rm = "hello"))
  expect_snapshot(error = TRUE, rfuns_sum(1:10, na.rm = "hello"))
  expect_snapshot(error = TRUE, rfuns_sum(c(1, 2, 3), na.rm = "hello"))
})

test_that("r_base::sum(<VARCHAR>", {
  expect_snapshot(error = TRUE, rfuns_sum("HufflePuff"))
})
