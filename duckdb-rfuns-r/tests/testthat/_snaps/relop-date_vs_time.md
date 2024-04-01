# date <=> time

    Code
      binary_altrep(time, date, "r_base::==", con = con)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: Comparing times and dates is not supported : TIMESTAMP <=> DATE

---

    Code
      binary_altrep(date, time, "r_base::==", con = con)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: Comparing dates and times is not supported : DATE <=> TIMESTAMP

