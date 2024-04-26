# r_base::min+max(<VARCHAR>

    Code
      rfuns_min("HufflePuff", na.rm = TRUE)
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::min(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::min(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::min(INTEGER, BOOLEAN) -> INTEGER\n\tr_base::min(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::min(TIMESTAMP, BOOLEAN) -> TIMESTAMP\n","name":"r_base::min","candidates":"r_base::min(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::min(INTEGER, BOOLEAN) -> INTEGER,r_base::min(DOUBLE, BOOLEAN) -> DOUBLE,r_base::min(TIMESTAMP, BOOLEAN) -> TIMESTAMP","call":"r_base::min(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

---

    Code
      rfuns_max("HufflePuff", na.rm = TRUE)
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::max(VARCHAR, BOOLEAN)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::max(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::max(INTEGER, BOOLEAN) -> INTEGER\n\tr_base::max(DOUBLE, BOOLEAN) -> DOUBLE\n\tr_base::max(TIMESTAMP, BOOLEAN) -> TIMESTAMP\n","name":"r_base::max","candidates":"r_base::max(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::max(INTEGER, BOOLEAN) -> INTEGER,r_base::max(DOUBLE, BOOLEAN) -> DOUBLE,r_base::max(TIMESTAMP, BOOLEAN) -> TIMESTAMP","call":"r_base::max(VARCHAR, BOOLEAN)","error_subtype":"NO_MATCHING_FUNCTION"}

