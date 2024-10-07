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

# spaceship(<str> <=> <lgl>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<lgl> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<str> <=> <dbl>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<dbl> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<int> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<str> <=> <int>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(DATE, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN\n\tr_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(DATE, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, VARCHAR) -> BOOLEAN,r_base::==(VARCHAR, TIMESTAMP) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

