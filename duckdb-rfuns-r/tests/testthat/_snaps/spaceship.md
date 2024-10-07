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
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DATE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DATE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DATE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DATE)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<time> <=> <string>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(TIMESTAMP, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(TIMESTAMP, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, TIMESTAMP)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, TIMESTAMP)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<str> <=> <lgl>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<lgl> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<str> <=> <dbl>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<dbl> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<int> <=> <str>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# spaceship(<str> <=> <int>)

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      spaceship_rfuns(x, y, keep.data = FALSE)
    Condition
      Error in `spaceship_rfuns()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::==(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::==(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::==(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::==(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::==(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::==(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::==(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::==(DATE, DATE) -> BOOLEAN\n\tr_base::==(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::==(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::==","candidates":"r_base::==(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, INTEGER) -> BOOLEAN,r_base::==(INTEGER, BOOLEAN) -> BOOLEAN,r_base::==(INTEGER, INTEGER) -> BOOLEAN,r_base::==(DOUBLE, INTEGER) -> BOOLEAN,r_base::==(INTEGER, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::==(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::==(DOUBLE, DOUBLE) -> BOOLEAN,r_base::==(VARCHAR, VARCHAR) -> BOOLEAN,r_base::==(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::==(DATE, DATE) -> BOOLEAN,r_base::==(TIMESTAMP, DATE) -> BOOLEAN,r_base::==(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::==(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

