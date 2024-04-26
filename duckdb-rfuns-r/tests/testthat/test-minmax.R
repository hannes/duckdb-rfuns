test_that("r_base::min+max(<TIMESTAMP>)", {
  x <- c(Sys.time(), Sys.time() + 1, NA)

  expect_equal(rfuns_min(x, na.rm = FALSE), min(x, na.rm = FALSE), ignore_attr = TRUE)
  expect_equal(rfuns_min(x, na.rm = TRUE) , min(x, na.rm = TRUE) , ignore_attr = TRUE)
  expect_equal(rfuns_max(x, na.rm = FALSE), max(x, na.rm = FALSE), ignore_attr = TRUE)
  expect_equal(rfuns_max(x, na.rm = TRUE) , max(x, na.rm = TRUE) , ignore_attr = TRUE)
})

test_that("r_base::min+max(<BOOLEAN>)", {
  x <- c(TRUE, FALSE, NA)

  expect_equal(rfuns_min(x, na.rm = FALSE), as.logical(min(x, na.rm = FALSE)))
  expect_equal(rfuns_min(x, na.rm = TRUE) , as.logical(min(x, na.rm = TRUE) ))
  expect_equal(rfuns_max(x, na.rm = FALSE), as.logical(max(x, na.rm = FALSE)))
  expect_equal(rfuns_max(x, na.rm = TRUE) , as.logical(max(x, na.rm = TRUE) ))
})

test_that("r_base::min+max(<INTEGER>)", {
  x <- c(1:10, NA)
  expect_equal(rfuns_min(x, na.rm = FALSE), min(x, na.rm = FALSE))
  expect_equal(rfuns_min(x, na.rm = TRUE) , min(x, na.rm = TRUE) )
  expect_equal(rfuns_max(x, na.rm = FALSE), max(x, na.rm = FALSE))
  expect_equal(rfuns_max(x, na.rm = TRUE) , max(x, na.rm = TRUE) )
})

test_that("r_base::min+max(<DOUBLE>)", {
  x <- c(1.1, 2.2, 3.3, NA)
  expect_equal(rfuns_min(x, na.rm = FALSE), min(x, na.rm = FALSE))
  expect_equal(rfuns_min(x, na.rm = TRUE) , min(x, na.rm = TRUE) )
  expect_equal(rfuns_max(x, na.rm = FALSE), max(x, na.rm = FALSE))
  expect_equal(rfuns_max(x, na.rm = TRUE) , max(x, na.rm = TRUE) )
})

test_that("r_base::min+max(<VARCHAR>", {
  expect_snapshot(error = TRUE, rfuns_min("HufflePuff", na.rm = TRUE))
  expect_snapshot(error = TRUE, rfuns_max("HufflePuff", na.rm = TRUE))
})
