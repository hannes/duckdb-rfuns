test_that("rfuns_isna(<double>)", {
  x <- c(1, 2, NA, NaN)
  expect_equal(rfuns_is.na(x)         , is.na(x))

  x <- c(1, 2, 3)
  expect_equal(rfuns_is.na(x)         , is.na(x))

  expect_equal(rfuns_is.na(1)         , FALSE)
  expect_equal(rfuns_is.na(NA_real_)  , TRUE)
  expect_equal(rfuns_is.na(NaN)       , TRUE)
})

test_that("rfuns_isna(<int>)", {
  x <- c(1L, NA_integer_)
  expect_equal(rfuns_is.na(x)           , is.na(x))

  x <- c(1L, 2L, 3L)
  expect_equal(rfuns_is.na(x)           , is.na(x))

  expect_equal(rfuns_is.na(1L)          , FALSE)
  expect_equal(rfuns_is.na(NA_integer_) , TRUE)
})

test_that("rfuns_isna(<logical>)", {
  x <- c(TRUE, NA)
  expect_equal(rfuns_is.na(x)    , is.na(x))

  x <- c(TRUE, FALSE)
  expect_equal(rfuns_is.na(x)    , is.na(x))

  expect_equal(rfuns_is.na(TRUE) , FALSE)
  expect_equal(rfuns_is.na(NA)   , TRUE)
})

test_that("rfuns_isna(<string>)", {
  x <- c("", NA_character_)
  expect_equal(rfuns_is.na(x)             , is.na(x))

  x <- c("a", "b")
  expect_equal(rfuns_is.na(x)             , is.na(x))

  expect_equal(rfuns_is.na("NA")          , FALSE)
  expect_equal(rfuns_is.na(NA_character_) , TRUE)
})
