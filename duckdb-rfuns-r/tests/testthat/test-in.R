test_that("%in%", {
  # <dbl> %in% <dbl>
  expect_rfuns_in(c(1, 2), c(2, 5))
  expect_rfuns_in(c(1, 2, NA_real_), c(2, 5))
  expect_rfuns_in(c(1, 2), c(2, 5, NA_real_))
  expect_rfuns_in(c(NA_real_), c(NA_real_))

  # <int> %in% <int>
  expect_rfuns_in(c(1L, 2L), c(2L, 5L))
  expect_rfuns_in(c(1L, 2L, NA_integer_), c(2L, 5L))
  expect_rfuns_in(c(1L, 2L), c(2L, 5L, NA_integer_))
  expect_rfuns_in(c(NA_integer_), c(NA_integer_))
})

test_that("%in% skipped", {
  skip("Value::LIST without providing a child-type requires a non-empty list of values")

  expect_rfuns_in(c(NA_real_), numeric())
})
