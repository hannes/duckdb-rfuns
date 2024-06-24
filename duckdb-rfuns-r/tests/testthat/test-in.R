test_that("%in%", {
  # <dbl> %in% <dbl>
  expect_rfuns_in(c(1, 2), c(2, 5))
  expect_rfuns_in(c(1, 2, NA_real_), c(2, 5))
  expect_rfuns_in(c(1, 2), c(2, 5, NA_real_))
  expect_rfuns_in(c(NA_real_), c(NA_real_))

  # <lgl> %in% <lgl>
  expect_rfuns_in(c(TRUE, FALSE), c(TRUE))
  expect_rfuns_in(c(TRUE, FALSE), c(NA))
  expect_rfuns_in(c(NA, TRUE), c(FALSE))
  expect_rfuns_in(c(NA), c(NA))

  # <lgl> %in% <int>
  expect_rfuns_in(c(TRUE, FALSE), c(1L))
  expect_rfuns_in(c(TRUE, FALSE), c(NA_integer_))
  expect_rfuns_in(c(NA, TRUE), c(42L))
  expect_rfuns_in(c(NA), c(NA_integer_))

  # <int> %in% <lgl>
  expect_rfuns_in(c(1L, 3L), c(TRUE))
  expect_rfuns_in(c(1L, 0L), c(NA))
  expect_rfuns_in(c(NA_integer_, 0L, 32L), c(FALSE))
  expect_rfuns_in(c(NA_integer_), c(NA))

  # <int> %in% <int>
  expect_rfuns_in(c(1L, 2L), c(2L, 5L))
  expect_rfuns_in(c(1L, 2L, NA_integer_), c(2L, 5L))
  expect_rfuns_in(c(1L, 2L), c(2L, 5L, NA_integer_))
  expect_rfuns_in(c(NA_integer_), c(NA_integer_))

  # <dbl> %in% <int>
  expect_rfuns_in(c(1, 2), c(2L, 5L))
  expect_rfuns_in(c(1, 2, NA_real_), c(2L, 5L))
  expect_rfuns_in(c(1, 2), c(2L, 5L, NA_integer_))
  expect_rfuns_in(c(NA_real_), c(NA_integer_))

  # <dbl> %in% <lgl>
  expect_rfuns_in(c(1, 3), c(TRUE))
  expect_rfuns_in(c(1, 0), c(NA))
  expect_rfuns_in(c(NA_real_, 0, 1, 34), c(FALSE))
  expect_rfuns_in(c(NA_real_), c(NA))

  # <lgl> %in% <dbl>
  expect_rfuns_in(c(TRUE, FALSE), c(1))
  expect_rfuns_in(c(TRUE, FALSE), c(NA_real_))
  expect_rfuns_in(c(NA, TRUE), c(42))
  expect_rfuns_in(c(NA), c(NA_real_))
})

test_that("%in% with <str>", {
  # <str> %in% <int>
  expect_rfuns_in(c("1", "abc"), c(1L))
  expect_rfuns_in(c("1", NA_character_), c(NA_integer_))
  expect_rfuns_in(c(NA_character_, "42", "abc"), c(42L))
  expect_rfuns_in(c(NA_character_), c(NA_integer_))

  # <str> %in% <dbl>
  expect_rfuns_in(c("1", "abc", "1.2"), c(1, 1.2))
  expect_rfuns_in(c("1", NA_character_), c(NA_real_))
  expect_rfuns_in(c(NA_character_), c(NA_real_))
  expect_rfuns_in(c(NA_character_, "42.3", "abc"), c(42.3))

  # <str> %in% <lgl>
  expect_rfuns_in(c("TRUE", "true", "false", "FALSE"), c(TRUE))
  expect_rfuns_in(c("TRUE", NA_character_), c(NA))
  expect_rfuns_in(c(NA_character_), c(NA))

  # <int> %in% <str>
  expect_rfuns_in(c(1L, 2L), c("2", "5", "abc"))
  expect_rfuns_in(c(1L, 2L, NA_integer_), c("2", "5", "abc"))
  expect_rfuns_in(c(1L, 2L), c("2", "5", "", NA_character_))
  expect_rfuns_in(c(NA_integer_), c(NA_character_))

  # <dbl> %in% <str>
  expect_rfuns_in(c(1, 2), c("2", "5", "abc"))
  expect_rfuns_in(c(1, 2, NA_real_), c("2", "5", "abc"))
  expect_rfuns_in(c(1, 2), c("2", "5", "", NA_character_))
  expect_rfuns_in(c(NA_real_), c(NA_character_))

  # <lgl> %in% <str>
  expect_rfuns_in(c(FALSE), c("FALSE", "abc"))
  expect_rfuns_in(c(FALSE, TRUE, NA), c("TRUE", "5", "abc"))
  expect_rfuns_in(c(FALSE), c("TRUE", NA_character_))
  expect_rfuns_in(c(NA), c(NA_character_))

  # <str> %in% <str>
  expect_rfuns_in(c("abc"), c(NA_character_))
  expect_rfuns_in(c("abc", NA_character_), c(NA_character_))
  expect_rfuns_in(c("abc", NA_character_), c("abc", "def"))
  expect_rfuns_in(c(NA_character_), c(NA_character_))
})


test_that("%in% skipped", {
  skip("Value::LIST without providing a child-type requires a non-empty list of values")

  expect_rfuns_in(c(NA_real_), numeric())
})
