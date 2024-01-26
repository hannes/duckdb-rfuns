udf_eval <- function(con, fun, ...) {
  names <- paste(gsub('"', "'", names(rlang::quos(..., .named = TRUE))), collapse = ", ")

  dbGetQuery(con, glue::glue(r"[
    SELECT "{fun}"({names})
  ]"))[, 1]
}
