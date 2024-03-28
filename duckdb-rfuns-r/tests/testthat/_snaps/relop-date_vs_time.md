# date <=> time

    Code
      binary_altrep(time, date, "r_base::==", con = con)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: TIMESTAMP <=> DATE

---

    Code
      binary_altrep(date, time, "r_base::==", con = con)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: DATE <=> TIMESTAMP

