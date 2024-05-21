# r_base::min+max(<VARCHAR>

    Code
      rfuns_min("HufflePuff", na.rm = TRUE)
    Condition
      Error in `rfuns_min()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::aggregate::min(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::aggregate::min(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::aggregate::min(BOOLEAN) -> BOOLEAN\n\tr_base::aggregate::min(INTEGER, BOOLEAN) -> INTEGER\n\tr_base::aggregate::min(INTEGER) -> INTEGER\n\tr_base::aggregate::min(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::aggregate::min(DOUBLE) -> DOUBLE\n\tr_base::aggregate::min(TIMESTAMP, BOOLEAN) -> TIMESTAMP\n\tr_base::aggregate::min(TIMESTAMP) -> TIMESTAMP\n\tr_base::aggregate::min(DATE, BOOLEAN) -> DATE\n\tr_base::aggregate::min(DATE) -> DATE\n","name":"r_base::aggregate::min","candidates":"r_base::aggregate::min(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::aggregate::min(BOOLEAN) -> BOOLEAN,r_base::aggregate::min(INTEGER, BOOLEAN) -> INTEGER,r_base::aggregate::min(INTEGER) -> INTEGER,r_base::aggregate::min(DOUBLE, BOOLEAN) -> DOUBLE,r_base::aggregate::min(DOUBLE) -> DOUBLE,r_base::aggregate::min(TIMESTAMP, BOOLEAN) -> TIMESTAMP,r_base::aggregate::min(TIMESTAMP) -> TIMESTAMP,r_base::aggregate::min(DATE, BOOLEAN) -> DATE,r_base::aggregate::min(DATE) -> DATE","call":"r_base::aggregate::min(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_max("HufflePuff", na.rm = TRUE)
    Condition
      Error in `rfuns_max()`:
      ! binding error
      Caused by error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::aggregate::max(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::aggregate::max(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::aggregate::max(BOOLEAN) -> BOOLEAN\n\tr_base::aggregate::max(INTEGER, BOOLEAN) -> INTEGER\n\tr_base::aggregate::max(INTEGER) -> INTEGER\n\tr_base::aggregate::max(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::aggregate::max(DOUBLE) -> DOUBLE\n\tr_base::aggregate::max(TIMESTAMP, BOOLEAN) -> TIMESTAMP\n\tr_base::aggregate::max(TIMESTAMP) -> TIMESTAMP\n\tr_base::aggregate::max(DATE, BOOLEAN) -> DATE\n\tr_base::aggregate::max(DATE) -> DATE\n","name":"r_base::aggregate::max","candidates":"r_base::aggregate::max(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::aggregate::max(BOOLEAN) -> BOOLEAN,r_base::aggregate::max(INTEGER, BOOLEAN) -> INTEGER,r_base::aggregate::max(INTEGER) -> INTEGER,r_base::aggregate::max(DOUBLE, BOOLEAN) -> DOUBLE,r_base::aggregate::max(DOUBLE) -> DOUBLE,r_base::aggregate::max(TIMESTAMP, BOOLEAN) -> TIMESTAMP,r_base::aggregate::max(TIMESTAMP) -> TIMESTAMP,r_base::aggregate::max(DATE, BOOLEAN) -> DATE,r_base::aggregate::max(DATE) -> DATE","call":"r_base::aggregate::max(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

