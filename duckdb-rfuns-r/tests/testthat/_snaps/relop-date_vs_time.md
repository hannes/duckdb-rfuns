# time <=> date

    Code
      duckdb:::rel_to_altrep(out_rel)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: Comparing times and dates is not supported : TIMESTAMP <=> DATE

---

    Code
      duckdb:::rel_to_altrep(out_rel)
    Condition
      Error:
      ! Error evaluating duckdb query: Not implemented Error: Comparing dates and times is not supported : DATE <=> TIMESTAMP

