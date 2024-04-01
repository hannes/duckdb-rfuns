test_that("spaceship(<date> <=> <date>)", {
  date <- as.Date("2024-03-21")
  expect_spaceship(date, "2024-03-21")
  expect_spaceship(date, "2024-03-20")
  expect_spaceship(date, "2024-03-20")

  expect_spaceship("2024-03-21", date)
  expect_spaceship("2024-03-20", date)
  expect_spaceship("2024-03-20", date)

  # ok because both R and Date::FromString(strict = false)
  # are forgiving about extra stuff after YYYY-MM-DD format
  expect_spaceship(date, "2024-03-21 and then some")
  expect_spaceship(date, "2024-03-20 and then some")
  expect_spaceship("2024-03-21 and then some", date)
  expect_spaceship("2024-03-20 and then some", date)

  # ok because they fail in both cases
  expect_spaceship(date, "not a date")
  expect_spaceship("not a date", date)
})

test_that("spaceship(<date> <=> <date>)", {
  date <- as.Date("2024-02-21")
  NA_date <- as.Date(NA)

  expect_spaceship(date, date)
  expect_spaceship(date, date + 1)
  expect_spaceship(NA_date, date)
  expect_spaceship(date, NA_date)
})

test_that("spaceship(<time> <=> <time>)", {
  time <- as.POSIXct(strptime('2024-02-21 14:00:00', format = '%Y-%m-%d %H:%M:%S', tz = 'UTC'))
  NA_time <- as.POSIXct(NA)

  expect_spaceship(time, time)
  expect_spaceship(time, time + 1)
  expect_spaceship(time, NA_time)
  expect_spaceship(NA_time, time)
})

test_that("spaceship(<int> <=> <int>)", {
  expect_spaceship(0L , 0L)
  expect_spaceship(1L , 0L)
  expect_spaceship(1L , NA_integer_)
  expect_spaceship(NA_integer_ , 2L)
  expect_spaceship(NA_integer_ , NA_integer_)
})

test_that("spaceship(<lgl> <=> <lgl>)", {
  expect_spaceship(TRUE  , TRUE)
  expect_spaceship(TRUE  , FALSE)
  expect_spaceship(FALSE , TRUE)
  expect_spaceship(FALSE , FALSE)
  expect_spaceship(NA    , FALSE)
  expect_spaceship(NA    , TRUE)
  expect_spaceship(TRUE  , NA)
  expect_spaceship(FALSE , NA)
})

test_that("spaceship(<int> <=> <lgl>)", {
  expect_spaceship(1L          , TRUE)
  expect_spaceship(1L          , FALSE)
  expect_spaceship(2L          , TRUE)
  expect_spaceship(2L          , FALSE)
  expect_spaceship(0L          , TRUE)
  expect_spaceship(0L          , FALSE)
  expect_spaceship(NA_integer_ , TRUE)
  expect_spaceship(NA_integer_ , NA)
  expect_spaceship(42L         , NA_integer_)
})

test_that("spaceship(<int> <=> <lgl>)", {
  expect_spaceship(TRUE  , 1L)
  expect_spaceship(FALSE , 1L)
  expect_spaceship(TRUE  , 2L)
  expect_spaceship(FALSE , 2L)
  expect_spaceship(TRUE  , 0L)
  expect_spaceship(FALSE , 0L)
  expect_spaceship(TRUE  , NA_integer_)
  expect_spaceship(NA    , NA_integer_)
  expect_spaceship(NA    , 42L)
})

test_that("spaceship(<dbl> <=> <dbl>)", {
  expect_spaceship(1.5    , 2)
  expect_spaceship(1.5    , 1.5)
  expect_spaceship(1.5    , NA_real_)
  expect_spaceship(NA_real_, 2.5)
})

test_that("spaceship(<dbl> <=> <int | lgl>)", {
  expect_spaceship(2.0      , 2L)
  expect_spaceship(3.5      , 2L)
  expect_spaceship(3.5      , NA_integer_)
  expect_spaceship(1.0      , TRUE)
  expect_spaceship(1.0      , FALSE)
  expect_spaceship(0.0      , FALSE)
  expect_spaceship(0.0      , TRUE)
  expect_spaceship(2.0      , NA)
  expect_spaceship(NA_real_ , 42L)
  expect_spaceship(NA_real_ , TRUE)
  expect_spaceship(NA_real_ , FALSE)
})

test_that("spaceship(<int | lgl> <=> <dbl>)", {
  expect_spaceship(2L    , 2.0)
  expect_spaceship(2L    , 3.5)
  expect_spaceship(NA_integer_ , 3.5)
  expect_spaceship(TRUE  , 1.0)
  expect_spaceship(FALSE , 1.0)
  expect_spaceship(FALSE , 0.0)
  expect_spaceship(TRUE  , 0.0)
  expect_spaceship(NA    , 0.0)
  expect_spaceship(42L   , NA_real_)
  expect_spaceship(TRUE  , NA_real_)
  expect_spaceship(FALSE , NA_real_)
})

test_that("spaceship(<str> <=> <str>)", {
  expect_spaceship('a' , 'b')
  expect_spaceship('a' , 'a')
  expect_spaceship('a' , NA_character_)
  expect_spaceship(NA_character_, 'a')
})

test_that("spaceship(<str> <=> <lgl>)", {
  expect_spaceship('TRUE'        , TRUE)
  expect_spaceship('TRUE'        , FALSE)
  expect_spaceship('TRUE'        , NA)
  expect_spaceship(NA_character_ , TRUE)
  expect_spaceship(NA_character_ , FALSE)
  expect_spaceship('FALSE'       , TRUE)
  expect_spaceship('FALSE'       , FALSE)
  expect_spaceship('tRue'        , TRUE)
  expect_spaceship('fAlse'       , FALSE)
})

test_that("spaceship(<lgl> <=> <str>)", {
  expect_spaceship(TRUE  , 'TRUE')
  expect_spaceship(FALSE , 'TRUE')
  expect_spaceship(NA    , 'TRUE')
  expect_spaceship(TRUE  , NA_character_)
  expect_spaceship(FALSE , NA_character_)
  expect_spaceship(TRUE  , 'FALSE')
  expect_spaceship(FALSE , 'FALSE')
  expect_spaceship(TRUE  , 'tRue')
  expect_spaceship(FALSE , 'fAlse')
})

test_that("spaceship(<str> <=> <dbl>)", {
  expect_spaceship('2' , 1.0)
  expect_spaceship('1' , 1.0)
  expect_spaceship('1' , NA_real_)
  expect_spaceship(NA_character_, 3.0)
  expect_spaceship("a", 1.0)
})

test_that("spaceship(<dbl> <=> <str>)", {
  expect_spaceship(1.0 ,'2')
  expect_spaceship(1.0 , '1')
  expect_spaceship(NA_real_ , "2")
  expect_spaceship(3.0 , NA_character_)
  expect_spaceship(1.0 , "a")
})

test_that("spaceship(<int> <=> <str>)", {
  expect_spaceship(NA_integer_, "string")
  expect_spaceship(1L , "1")
  expect_spaceship(1L , NA_character_)
  expect_spaceship(1L , "a")
})

test_that("spaceship(<str> <=> <int>)", {
  expect_spaceship("string", NA_integer_)
  expect_spaceship("1", 1L)
  expect_spaceship(NA_character_ , 2L)
  expect_spaceship("a", 1L)
})
