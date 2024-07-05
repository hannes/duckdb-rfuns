expect_spaceship <- function(x, y) {

  ok_rfuns <- ok_r <- TRUE

  rfuns <- tryCatch(
    spaceship_rfuns(x, y, keep.data = FALSE),
    error = function(err) {
      ok_rfuns <<- FALSE
    }
  )

  r <- tryCatch(
    spaceship_r(x, y, keep.data = FALSE),
    error = function(err) {
      ok_r <<- FALSE
    }
  )

  expect_equal(ok_r, ok_rfuns, info = "<=> should either pass for both or fail for both")

  if (ok_r && ok_rfuns) {
    expect_equal(rfuns, r)
  }

}

expect_spaceship_error <- function(x, y) {
  expect_snapshot(error = TRUE, spaceship_rfuns(x, y, keep.data = FALSE))
}
