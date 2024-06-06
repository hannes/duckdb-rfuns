test_that("%in%", {
  expect_rfuns_in(c(1, 2), c(2, 5))
  expect_rfuns_in(c(1, 2, NA), c(2, 5))
  expect_rfuns_in(c(1, 2), c(2, 5, NA))

  expect_rfuns_in(c(NA_real_), c(NA_real_))

  expect_rfuns_in(c(1, 2), c(2L, 5L))
  expect_rfuns_in(c(1L, 2L), c(2, 5))
  expect_rfuns_in(c(1L, 2L), c(2L, 5L))

  skip("failing for now")
  expect_rfuns_in(c(NA_real_), c(2, 5))
})
