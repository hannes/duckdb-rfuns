expect_spaceship <- function(x, y) {
  expect_equal(
    spaceship_rfuns(x, y, keep.data = FALSE),
    spaceship_r(x, y, keep.data = FALSE)
  )
}

