expect_rfuns_in <- function(x, y) {
  expect_equal(x %in% y, rfuns_in(x, y))
}

expect_error_rfuns_in <- function(x, y) {
  expect_snapshot(error = TRUE, rfuns_in(x, y))
}
