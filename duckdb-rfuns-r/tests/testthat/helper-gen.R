gen_dir <- file.path("tests", "testthat", "gen")
gen_files <- list.files(gen_dir, pattern = "[.][rR]$")

for (f in gen_files) {
  test_file <- file.path("tests", "testthat", paste0("test-generated-", f))

  expressions <- parse(file.path(gen_dir, f))

}
