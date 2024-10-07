test_that("as.character(<BOOLEAN>", {
  expect_equal(rfuns_as.character(TRUE), "TRUE")
  expect_equal(rfuns_as.character(FALSE), "FALSE")
  expect_equal(rfuns_as.character(NA), NA_character_)
})

test_that("as.character(<INTEGER>", {
  expect_equal(rfuns_as.character(3L), "3")
  expect_equal(rfuns_as.character(NA_integer_), NA_character_)
})

test_that("as.character(<DOUBLE>", {
  dbl <- 35.123
  str <- rfuns_as.character(dbl)
  expect_true(is.character(str))
  expect_equal(as.numeric(str), dbl)

  expect_equal(rfuns_as.character(NA_real_), NA_character_)
})

test_that("as.character(<VARCHAR>", {
  expect_equal(rfuns_as.character("hello"), "hello")
})

test_that("as.character(<TIMESTAMP>", {
  time <- as.POSIXct(strptime('2024-02-21 14:00:00', format = '%Y-%m-%d %H:%M:%S', tz = 'UTC'))
  expect_equal(rfuns_as.character(time), "2024-02-21 14:00:00")
})

test_that("as.character(<DATE>", {
  today <- Sys.Date()
  expect_equal(rfuns_as.character(today), as.character(today))
})
