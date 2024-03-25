test_that("date <=> time", {
  time <- as.POSIXct(Sys.Date(), tz = "UTC")
  date <- Sys.Date()

  spaceship_equal  <- spaceship_rfuns(1, 1)[, -c(1, 2)]
  expect_equal(
    spaceship_rfuns(time, date)[, -c(1, 2)],
    spaceship_equal
  )
  expect_equal(
    spaceship_rfuns(date, time)[, -c(1, 2)],
    spaceship_equal
  )

  spaceship_bigger <- spaceship_rfuns(2, 1)[, -c(1, 2)]
  expect_equal(
    spaceship_rfuns(time + 1, date)[, -c(1, 2)],
    spaceship_bigger
  )
  expect_equal(
    spaceship_rfuns(date + 1, time)[, -c(1, 2)],
    spaceship_bigger
  )

})
