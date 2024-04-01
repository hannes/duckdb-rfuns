# spaceship(<date> <=> <string>)

    Code
      spaceship_rfuns(as.Date("2024-03-21"), "not a date", "==")
    Condition
      Error in `map()`:
      i In index: 1.
      i With name: x.
      Caused by error:
      ! Error evaluating duckdb query: Conversion Error: date field value out of range: "not a date", expected format is (YYYY-MM-DD)

---

    Code
      spaceship_r(as.Date("2024-03-21"), "not a date", "==")
    Condition
      Error in `map()`:
      i In index: 1.
      i With name: ==.
      Caused by error in `charToDate()`:
      ! character string is not in a standard unambiguous format

