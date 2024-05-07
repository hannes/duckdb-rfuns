test_that("rfuns.is.na() handles CONSTANT input", {
  withr::local_options(list(duckdb.materialize_message = FALSE))
  con <- local_duckdb_con()

  duckdb <- asNamespace("duckdb")
  experimental <- FALSE
  df1 <- data.frame(a = 42)

  is_na_constant <- function(value) {
    rel365 <- duckdb$rel_from_df(con, df1, experimental = experimental)
    rel366 <- duckdb$rel_project(
      rel365,
      list({
        tmp_expr <- duckdb$expr_constant(value)
        duckdb$expr_set_alias(tmp_expr, "d")
        tmp_expr
      })
    )
    rel367 <- duckdb$rel_project(
      rel366,
      list({
        tmp_expr <- duckdb$expr_function("r_base::is.na", list(duckdb$expr_reference("d")))
        duckdb$expr_set_alias(tmp_expr, "e")
        tmp_expr
      })
    )
    duckdb$rel_to_altrep(rel367)[, 1L][]
  }
  expect_true(is_na_constant(NA_real_))
  expect_true(is_na_constant(NaN))
  expect_true(is_na_constant(NA_integer_))
  expect_true(is_na_constant(NA_character_))

  expect_false(is_na_constant(42))
  expect_false(is_na_constant(42L))
  expect_false(is_na_constant(TRUE))
  expect_false(is_na_constant(FALSE))

  skip("I don't know why it returns NA: will investigate")
  expect_true(is_na_constant(NA))
})

test_that("rfuns_isna(<double>)", {
  x <- c(1, 2, NA, NaN)
  expect_equal(rfuns_is.na(x)         , is.na(x))

  x <- c(1, 2, 3)
  expect_equal(rfuns_is.na(x)         , is.na(x))

  expect_equal(rfuns_is.na(1)         , FALSE)
  expect_equal(rfuns_is.na(NA_real_)  , TRUE)
  expect_equal(rfuns_is.na(NaN)       , TRUE)
})

test_that("rfuns_isna(<int>)", {
  x <- c(1L, NA_integer_)
  expect_equal(rfuns_is.na(x)           , is.na(x))

  x <- c(1L, 2L, 3L)
  expect_equal(rfuns_is.na(x)           , is.na(x))

  expect_equal(rfuns_is.na(1L)          , FALSE)
  expect_equal(rfuns_is.na(NA_integer_) , TRUE)
})

test_that("rfuns_isna(<logical>)", {
  x <- c(TRUE, NA)
  expect_equal(rfuns_is.na(x)    , is.na(x))

  x <- c(TRUE, FALSE)
  expect_equal(rfuns_is.na(x)    , is.na(x))

  expect_equal(rfuns_is.na(TRUE) , FALSE)
  expect_equal(rfuns_is.na(NA)   , TRUE)
})

test_that("rfuns_isna(<string>)", {
  x <- c("", NA_character_)
  expect_equal(rfuns_is.na(x)             , is.na(x))

  x <- c("a", "b")
  expect_equal(rfuns_is.na(x)             , is.na(x))

  expect_equal(rfuns_is.na("NA")          , FALSE)
  expect_equal(rfuns_is.na(NA_character_) , TRUE)
})
