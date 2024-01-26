test_that("eq", {
  con <- local_con()
  expect_snapshot(udf_eval(con, "r_base::==", 1, 2))
})
