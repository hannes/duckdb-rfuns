# time <=> date

    Code
      spaceship_rfuns(time, date)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing times and dates is not supported : TIMESTAMP <=> DATE"}

---

    Code
      spaceship_rfuns(date, time)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing dates and times is not supported : DATE <=> TIMESTAMP"}

# spaceship(<date> <=> <string>)

    Code
      spaceship_rfuns(as.Date("2024-03-21"), "not a date", "==")
    Condition
      Error in `spaceship_rfuns()`:
      ! runtime error
      Caused by error in `map()`:
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
      Error in `spaceship_rfuns()`:
      ! runtime error
      Caused by error in `map()`:
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
      Error in `spaceship_rfuns()`:
      ! runtime error
      Caused by error in `map()`:
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

# spaceship(<str> <=> <dbl>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# spaceship(<dbl> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# spaceship(<int> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

# spaceship(<str> <=> <int>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

