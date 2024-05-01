test_that("as.integer(<INTEGER>", {
  expect_equal(rfuns_as.integer(42L), 42L)
  expect_equal(rfuns_as.integer(NA_integer_), NA_integer_)
})

test_that("as.integer(<DOUBLE>", {
  expect_equal(rfuns_as.integer(42), 42L)

  expect_equal(rfuns_as.integer(42.5), 42L)
  expect_equal(rfuns_as.integer(42.4), 42L)
  expect_equal(rfuns_as.integer(42.6), 42L)

  expect_equal(rfuns_as.integer(43.5), 43L)
  expect_equal(rfuns_as.integer(43.4), 43L)
  expect_equal(rfuns_as.integer(43.6), 43L)

  expect_equal(rfuns_as.integer(NA_real_), NA_integer_)
  expect_equal(rfuns_as.integer(NaN), NA_integer_)

  expect_equal(rfuns_as.integer(2^31), NA_integer_)
  expect_equal(rfuns_as.integer(2^31 - 1), as.integer(2^31-1))

  expect_equal(rfuns_as.integer(-2^31), NA_integer_)
  expect_equal(rfuns_as.integer(-2^31 + 1), as.integer(-2^31 + 1))
})

test_that("as.integer(<BOOLEAN>", {
  expect_equal(rfuns_as.integer(TRUE), 1L)
  expect_equal(rfuns_as.integer(FALSE), 0L)
  expect_equal(rfuns_as.integer(NA), NA_integer_)
})

test_that("as.integer(<VARCHAR>", {
  expect_equal(rfuns_as.integer("42"), 42L)
  expect_equal(rfuns_as.integer("42.5"), 42L)
  expect_equal(rfuns_as.integer("x"), NA_integer_)
  expect_equal(rfuns_as.integer(NA_character_), NA_integer_)
})
