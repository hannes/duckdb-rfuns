test_that("date <=> time", {
  time <- as.POSIXct(Sys.Date(), tz = "UTC")
  date <- Sys.Date()

  expect_equal(
    spaceship_rfuns(time, date),
    spaceship_rfuns(1, 1)
  )
  expect_equal(
    spaceship_rfuns(date, time),
    spaceship_rfuns(1, 1)
  )

  expect_equal(
    spaceship_rfuns(time + 1, date),
    spaceship_rfuns(2, 1)
  )
  expect_equal(
    spaceship_rfuns(date + 1, time),
    spaceship_rfuns(2, 1)
  )

})
