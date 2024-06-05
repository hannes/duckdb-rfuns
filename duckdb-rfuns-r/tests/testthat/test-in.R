test_that("%in%", {
  x <- c(1, 2, 3)
  y <- c(2, 5)

  expect_equal(x %in% y, rfuns_in(x, y))
})
