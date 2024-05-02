test_that("as.numeric(<INTEGER>", {
  expect_equal(rfuns_as.numeric(42L), 42)
  expect_equal(rfuns_as.numeric(NA_integer_), NA_real_)
})

test_that("as.numeric(<DOUBLE>", {
  expect_equal(rfuns_as.numeric(42), 42)

  expect_equal(rfuns_as.numeric(42.5), 42.5)
  expect_equal(rfuns_as.numeric(NA_real_), NA_real_)
  expect_equal(rfuns_as.numeric(NaN), NaN)
})

test_that("as.numeric(<BOOLEAN>", {
  expect_equal(rfuns_as.numeric(TRUE), 1)
  expect_equal(rfuns_as.numeric(FALSE), 0)
  expect_equal(rfuns_as.numeric(NA), NA_real_)
})

test_that("as.numeric(<VARCHAR>", {
  expect_equal(rfuns_as.numeric("42"), 42)
  expect_equal(rfuns_as.numeric("42.5"), 42.5)
  expect_equal(rfuns_as.numeric("x"), NA_real_)
  expect_equal(rfuns_as.numeric(NA_character_), NA_real_)
})

test_that("as.numeric(<DATE>", {
  date <- Sys.Date()
  expect_equal(rfuns_as.numeric(date), as.numeric(date))

  date[] <- NA
  expect_equal(rfuns_as.numeric(date), as.numeric(date))
})

test_that("as.numeric(<TIMESTAMP>", {
  now <- Sys.time()
  expect_equal(rfuns_as.numeric(now), as.numeric(now))

  now[] <- NA
  expect_equal(rfuns_as.numeric(now), as.numeric(now))
})
