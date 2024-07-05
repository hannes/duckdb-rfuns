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

test_that("<lgl> %in% <str>", {
  # <str> %in% <lgl>
  expect_rfuns_in(c("TRUE", "true", "false", "FALSE"), c(TRUE))
  expect_rfuns_in(c("TRUE", NA_character_), c(NA))
  expect_rfuns_in(c(NA_character_), c(NA))

  # <lgl> %in% <str>
  expect_rfuns_in(c(FALSE), c("FALSE", "abc"))
  expect_rfuns_in(c(FALSE, TRUE, NA), c("TRUE", "5", "abc"))
  expect_rfuns_in(c(FALSE), c("TRUE", NA_character_))
  expect_rfuns_in(c(NA), c(NA_character_))
})

test_that("<str> %in% <str>", {
  expect_rfuns_in(c("abc"), c(NA_character_))
  expect_rfuns_in(c("abc", NA_character_), c(NA_character_))
  expect_rfuns_in(c("abc", NA_character_), c("abc", "def"))
  expect_rfuns_in(c(NA_character_), c(NA_character_))
})

test_that("numbers %in% <str>", {
  # <str> %in% <int>
  expect_error_rfuns_in(c("1", "abc"), c(1L))
  expect_error_rfuns_in(c("1", NA_character_), c(NA_integer_))
  expect_error_rfuns_in(c(NA_character_, "42", "abc"), c(42L))
  expect_error_rfuns_in(c(NA_character_), c(NA_integer_))

  # <str> %in% <dbl>
  expect_error_rfuns_in(c("1", "abc", "1.2"), c(1, 1.2))
  expect_error_rfuns_in(c("1", NA_character_), c(NA_real_))
  expect_error_rfuns_in(c(NA_character_), c(NA_real_))
  expect_error_rfuns_in(c(NA_character_, "42.3", "abc"), c(42.3))

  # <int> %in% <str>
  expect_error_rfuns_in(c(1L, 2L), c("2", "5", "abc"))
  expect_error_rfuns_in(c(1L, 2L, NA_integer_), c("2", "5", "abc"))
  expect_error_rfuns_in(c(1L, 2L), c("2", "5", "", NA_character_))
  expect_error_rfuns_in(c(NA_integer_), c(NA_character_))

  # <dbl> %in% <str>
  expect_error_rfuns_in(c(1, 2), c("2", "5", "abc"))
  expect_error_rfuns_in(c(1, 2, NA_real_), c("2", "5", "abc"))
  expect_error_rfuns_in(c(1, 2), c("2", "5", "", NA_character_))
  expect_error_rfuns_in(c(NA_real_), c(NA_character_))
})

test_that(" <timestamp> %in% <timestamp>", {
  now <- Sys.time()
  na_time <- as.POSIXct(NA)
  expect_rfuns_in(c(now, now + 1), now)
  expect_rfuns_in(c(now, now + 1), na_time)
  expect_rfuns_in(c(now, now + 1), c(now, na_time))

  times <- c(now, NA)
  expect_rfuns_in(c(times), now)
  expect_rfuns_in(c(times), na_time)
  expect_rfuns_in(c(times), c(now, na_time))
})

test_that("<timestamp> %in% <str>", {
  now <- as.POSIXct("2024-06-24 15:24:00 UTC")
  now_chr <- format(now, "%Y-%m-%d %H:%M:%S %Z")
  na_time <- as.POSIXct(NA)

  expect_equal(rfuns_in(c(now), now_chr)                           , TRUE)
  expect_equal(rfuns_in(c(now, now + 1), NA_character_)            , c(FALSE, FALSE))
  expect_equal(rfuns_in(c(now, now + 1), c(now_chr, NA_character_)), c(TRUE, FALSE))
  expect_equal(rfuns_in(c(na_time), c(now_chr, NA_character_))     , TRUE)
})

test_that("<str> %in% <timestamp>", {
  now <- as.POSIXct("2024-06-24 15:24:00 UTC")
  na_time <- as.POSIXct(NA)

  now_chr <- format(now, "%Y-%m-%d %H:%M:%S %Z")
  expect_equal(rfuns_in(c(now_chr), now)                , TRUE)
  expect_equal(rfuns_in(c(now_chr), na_time)            , FALSE)

  expect_equal(rfuns_in(c(now_chr, "hello"), c(now, NA)), c(TRUE, FALSE))
})

test_that(" <date> %in% <date>", {
  today <- Sys.Date()
  na_date <- as.Date(NA)
  expect_rfuns_in(c(today), today)
  expect_rfuns_in(c(today, today + 1), na_date)
  expect_rfuns_in(c(today, today + 1), c(today, na_date))
})

test_that(" <date> %in% <string>", {
  today <- Sys.Date()
  today_chr <- as.character(today)
  na_date <- as.Date(NA)

  expect_rfuns_in(c(today), today_chr)
  expect_rfuns_in(c(today, today + 1), NA_character_)
  expect_rfuns_in(c(today, today + 1), c(today_chr, NA_character_))
})

test_that(" <string> %in% <date>", {
  today <- Sys.Date()
  today_chr <- as.character(today)
  na_date <- as.Date(NA)

  expect_rfuns_in(c(today_chr), today)
  expect_rfuns_in(c(today_chr, "hello"), na_date)
  expect_rfuns_in(c(today_chr, "hello"), c(today, na_date))
})

test_that("%in% skipped", {
  skip("until https://github.com/duckdb/duckdb-r/pull/186")

  expect_rfuns_in(c(NA_real_), numeric())
})
