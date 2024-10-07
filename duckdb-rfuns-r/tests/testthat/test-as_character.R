test_that("as.character(<BOOLEAN>", {
  expect_equal(rfuns_as.character(TRUE), "TRUE")
  expect_equal(rfuns_as.character(FALSE), "FALSE")
  expect_equal(rfuns_as.character(NA), NA_character_)
})
