# r_base::sum(<?>, na.rm = <VARCHAR>)

    Code
      rfuns_sum(c(TRUE, FALSE), na.rm = "hello")
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(BOOLEAN, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(BOOLEAN, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_sum(1:10, na.rm = "hello")
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_sum(c(1, 2, 3), na.rm = "hello")
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# r_base::sum(<VARCHAR>

    Code
      rfuns_sum("HufflePuff")
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_sum("HufflePuff", na.rm = TRUE)
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_sum("HufflePuff", na.rm = FALSE)
    Condition
      Error in `rfuns_sum()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::sum(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::sum(BOOLEAN, BOOLEAN) -> INTEGER\n\tr_base::sum(BOOLEAN) -> INTEGER\n\tr_base::sum(INTEGER, BOOLEAN) -> DOUBLE\n\tr_base::sum(INTEGER) -> DOUBLE\n\tr_base::sum(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::sum(DOUBLE) -> DOUBLE\n","name":"r_base::sum","candidates":"r_base::sum(BOOLEAN, BOOLEAN) -> INTEGER,r_base::sum(BOOLEAN) -> INTEGER,r_base::sum(INTEGER, BOOLEAN) -> DOUBLE,r_base::sum(INTEGER) -> DOUBLE,r_base::sum(DOUBLE, BOOLEAN) -> DOUBLE,r_base::sum(DOUBLE) -> DOUBLE","call":"r_base::sum(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

