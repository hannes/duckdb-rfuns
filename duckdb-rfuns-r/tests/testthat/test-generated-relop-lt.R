# Generated by helper-gen.R: do not edit by hand
test_that(r"(<date> < <date> :: date < date)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = as.Date("2024-02-21"), x2 = as.Date("2024-02-21"))
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<date> < <date> :: date < date + 1)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = as.Date("2024-02-21"), x2 = as.Date("2024-02-22"))
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<date> < <date> :: NA_date < date)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = as.Date(NA_character_), x2 = as.Date("2024-02-21"))
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<date> < <date> :: date < NA_date)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = as.Date("2024-02-21"), x2 = as.Date(NA_character_))
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<time> < <time> :: time < time)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(
  x1 = as.POSIXct("2024-02-21 14:00:00", tz = "UTC"),
  x2 = as.POSIXct("2024-02-21 14:00:00", tz = "UTC"),
)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<time> < <time> :: time < time + 1)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(
  x1 = as.POSIXct("2024-02-21 14:00:00", tz = "UTC"),
  x2 = as.POSIXct("2024-02-21 14:00:01", tz = "UTC"),
)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<time> < <time> :: time < NA_time)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(
  x1 = as.POSIXct("2024-02-21 14:00:00", tz = "UTC"),
  x2 = as.POSIXct(NA_character_),
)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<time> < <time> :: NA_time < time)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(
  x1 = as.POSIXct(NA_character_),
  x2 = as.POSIXct("2024-02-21 14:00:00", tz = "UTC"),
)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <int> :: 0L < 0L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 0L, x2 = 0L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <int> :: 1L < 0L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1L, x2 = 0L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <int> :: 1L < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1L, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <int> :: NA_integer_ < 2L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_integer_, x2 = 2L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <int> :: NA_integer_ < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_integer_, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <lgl> :: TRUE < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <lgl> :: TRUE < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <lgl> :: FALSE < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<lgl> < <lgl> :: FALSE < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <lgl> :: NA < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <lgl> :: NA < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <lgl> :: TRUE < NA)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = NA)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <lgl> :: FALSE < NA)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = NA)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <lgl> :: 1L < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1L, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <lgl> :: 1L < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1L, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <lgl> :: 2L < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2L, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <lgl> :: 2L < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2L, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <lgl> :: 0L < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 0L, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<int> < <lgl> :: 0L < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 0L, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int> < <lgl> :: NA_integer_ < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_integer_, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <lgl> :: NA_integer_ < NA)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_integer_, x2 = NA)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int> < <lgl> :: 42L < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 42L, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <int> :: TRUE < 1L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = 1L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <int> :: FALSE < 1L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = 1L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<lgl> < <int> :: TRUE < 2L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = 2L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<lgl> < <int> :: FALSE < 2L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = 2L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<lgl> < <int> :: TRUE < 0L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = 0L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <int> :: FALSE < 0L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = 0L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<lgl> < <int> :: TRUE < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <int> :: NA < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<lgl> < <int> :: NA < 42L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA, x2 = 42L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <dbl> :: 1.5 < 2)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1.5, x2 = 2)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<dbl> < <dbl> :: 1.5 < 1.5)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1.5, x2 = 1.5)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <dbl> :: 1.5 < NA_real_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1.5, x2 = NA_real_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <dbl> :: NA_real_ < 2.5)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_real_, x2 = 2.5)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <int | lgl> :: 2 < 2L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2, x2 = 2L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <int | lgl> :: 3.5 < 2L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 3.5, x2 = 2L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <int | lgl> :: 3.5 < NA_integer_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 3.5, x2 = NA_integer_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <int | lgl> :: 1 < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <int | lgl> :: 1 < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 1, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <int | lgl> :: 0 < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 0, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<dbl> < <int | lgl> :: 0 < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 0, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<dbl> < <int | lgl> :: 2 < NA)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2, x2 = NA)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <int | lgl> :: NA_real_ < 42L)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_real_, x2 = 42L)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <int | lgl> :: NA_real_ < TRUE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_real_, x2 = TRUE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<dbl> < <int | lgl> :: NA_real_ < FALSE)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_real_, x2 = FALSE)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int | lgl> < <dbl> :: 2L < 2)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2L, x2 = 2)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int | lgl> < <dbl> :: 2L < 3.5)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 2L, x2 = 3.5)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<int | lgl> < <dbl> :: NA_integer_ < 3.5)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_integer_, x2 = 3.5)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int | lgl> < <dbl> :: TRUE < 1)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = 1)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int | lgl> < <dbl> :: FALSE < 1)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = 1)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<int | lgl> < <dbl> :: FALSE < 0)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = 0)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int | lgl> < <dbl> :: TRUE < 0)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = 0)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<int | lgl> < <dbl> :: NA < 0)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA, x2 = 0)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int | lgl> < <dbl> :: 42L < NA_real_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = 42L, x2 = NA_real_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int | lgl> < <dbl> :: TRUE < NA_real_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = TRUE, x2 = NA_real_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<int | lgl> < <dbl> :: FALSE < NA_real_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = FALSE, x2 = NA_real_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<str> < <str> :: "a" < "b")", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = "a", x2 = "b")
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], TRUE)
})

test_that(r"(<str> < <str> :: "a" < "a")", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = "a", x2 = "a")
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], FALSE)
})

test_that(r"(<str> < <str> :: "a" < NA_character_)", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = "a", x2 = NA_character_)
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

test_that(r"(<str> < <str> :: NA_character_ < "a")", {
  con <- local_duckdb_con()
  in_df <- tibble::tibble(x1 = NA_character_, x2 = "a")
  in_rel <- duckdb:::rel_from_df(con, in_df)
  out_rel <- duckdb:::rel_project(
    in_rel,
    list(duckdb:::expr_function(
      "r_base::<",
      list(
        duckdb:::expr_reference("x1"), 
        duckdb:::expr_reference("x2")
      )
    ))
  )
  out_df <- duckdb:::rel_to_altrep(out_rel)

  expect_identical(out_df[, 1], NA)
})

