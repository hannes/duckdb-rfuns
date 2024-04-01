test_that("time <=> date", {
  con <- local_duckdb_con()

  time <- as.POSIXct(Sys.Date(), tz = "UTC")
  date <- Sys.Date()

  in_df <- tibble::tibble(x1 = time, x2 = date)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::==",
      list(
        duckdb:::expr_reference("x1"),
        duckdb:::expr_reference("x2")
      )
    ))
  )
  expect_snapshot(error = TRUE, duckdb:::rel_to_altrep(out_rel))
})

test_that("time <=> date", {
  con <- local_duckdb_con()

  time <- as.POSIXct(Sys.Date(), tz = "UTC")
  date <- Sys.Date()

  in_df <- tibble::tibble(x1 = date, x2 = time)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::==",
      list(
        duckdb:::expr_reference("x1"),
        duckdb:::expr_reference("x2")
      )
    ))
  )
  expect_snapshot(error = TRUE, duckdb:::rel_to_altrep(out_rel))
})
