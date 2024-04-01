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

# spaceship(<time> <=> <string>)

    Code
      spaceship_rfuns(time, time_chr_gibberish, "==")
    Condition
      Error in `map()`:
      i In index: 1.
      i With name: x.
      Caused by error:
      ! Error evaluating duckdb query: Conversion Error: timestamp field value "2024-02-21 14:00:00 gibberish" has a timestamp that is not UTC.
      Use the TIMESTAMPTZ type with the ICU extension loaded to handle non-UTC timestamps.

---

    Code
      spaceship_rfuns(as.POSIXct(strptime("2024-02-21 14:00:00", format = "%Y-%m-%d %H:%M:%S")),
      "not a time", "==")
    Condition
      Error in `map()`:
      i In index: 1.
      i With name: x.
      Caused by error:
      ! Error evaluating duckdb query: Conversion Error: timestamp field value out of range: "not a time", expected format is (YYYY-MM-DD HH:MM:SS[.US][±HH:MM| ZONE])

---

    Code
      spaceship_r(as.POSIXct(strptime("2024-02-21 14:00:00", format = "%Y-%m-%d %H:%M:%S")),
      "not a time", "==")
    Condition
      Error in `map()`:
      i In index: 1.
      i With name: ==.
      Caused by error in `as.POSIXlt.character()`:
      ! character string is not in a standard unambiguous format

