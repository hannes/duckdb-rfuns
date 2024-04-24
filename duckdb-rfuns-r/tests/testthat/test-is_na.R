test_that("rfuns_isna()", {
  expect_equal(rfuns_is.na(c(1, 2, NA, NaN)), c(FALSE, FALSE, TRUE, TRUE))
  expect_equal(rfuns_is.na(1)               , FALSE)
  expect_equal(rfuns_is.na(NA_real_)        , TRUE)
  expect_equal(rfuns_is.na(NaN)             , TRUE)
})
