test_that("rfuns_isna(<double>)", {
  expect_equal(rfuns_is.na(c(1, 2, NA, NaN)), c(FALSE, FALSE, TRUE, TRUE))
  expect_equal(rfuns_is.na(1)               , FALSE)
  expect_equal(rfuns_is.na(NA_real_)        , TRUE)
  expect_equal(rfuns_is.na(NaN)             , TRUE)
})

test_that("rfuns_isna(<int>)", {
  expect_equal(rfuns_is.na(c(1L, NA_integer_)), c(FALSE, TRUE))
  expect_equal(rfuns_is.na(1L)                , FALSE)
  expect_equal(rfuns_is.na(NA_integer_)       , TRUE)
})

test_that("rfuns_isna(<logical>)", {
  expect_equal(rfuns_is.na(c(TRUE, NA)) , c(FALSE, TRUE))
  expect_equal(rfuns_is.na(TRUE)        , FALSE)
  expect_equal(rfuns_is.na(NA)          , TRUE)
})

test_that("rfuns_isna(<string>)", {
  expect_equal(rfuns_is.na(c("", NA_character_)), c(FALSE, TRUE))
  expect_equal(rfuns_is.na("NA")                , FALSE)
  expect_equal(rfuns_is.na(NA_character_)       , TRUE)
})
