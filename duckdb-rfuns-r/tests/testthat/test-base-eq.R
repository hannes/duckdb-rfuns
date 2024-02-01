# To be generated from test.R

test_that("int + int", {
  con <- local_con()

  in_df <- data.frame(a = 0L, b = 0L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <-
    duckdb:::rel_project(
      in_rel,
      list(duckdb:::expr_function(
        "r_base::==",
        list(
          duckdb:::expr_reference("a"),
          duckdb:::expr_reference("b")
        )
      ))
    )
  out_df <- duckdb:::rel_to_altrep(out_rel)
  expect_identical(out_df[[1]], TRUE)
})
