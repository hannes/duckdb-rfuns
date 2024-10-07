# <str> < <dbl> :: "2" < 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "42.3" < 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "42.4" < 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "42.299999999" < 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "1" < 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "1" < NA_real_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: NA_character_ < 3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <dbl> :: "a" < 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DOUBLE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DOUBLE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <dbl> < <str> :: 1 < "2"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <dbl> < <str> :: 1 < "1"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <dbl> < <str> :: NA_real_ < "2"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <dbl> < <str> :: 3 < NA_character_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <dbl> < <str> :: 1 < "a"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DOUBLE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DOUBLE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <int> < <str> :: NA_integer_ < "string"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <int> < <str> :: 1L < "1"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <int> < <str> :: 1L < NA_character_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <int> < <str> :: 1L < "a"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(INTEGER, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(INTEGER, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <int> :: "string" < NA_integer_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <int> :: "1" < 1L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <int> :: NA_character_ < 2L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

# <str> < <int> :: "a" < 1L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, INTEGER)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, INTEGER)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: time < "2024-02-21 14:00:00"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(TIMESTAMP, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(TIMESTAMP, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: time < "2024-02-21 13:00:00"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(TIMESTAMP, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(TIMESTAMP, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: time < "2024-02-21 15:00:00"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(TIMESTAMP, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(TIMESTAMP, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: "2024-02-21 14:00:00" < time

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, TIMESTAMP)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, TIMESTAMP)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: "2024-02-21 13:00:00" < time

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, TIMESTAMP)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, TIMESTAMP)","error_subtype":"NO_MATCHING_FUNCTION"}

# <time> < <string> :: "2024-02-21 15:00:00" < time

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, TIMESTAMP)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, TIMESTAMP)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: date < "2024-02-21"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DATE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DATE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: date < "2024-02-22"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DATE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DATE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: date < "2024-02-20"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DATE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DATE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: date < "2024-03-21 and then some"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(DATE, VARCHAR)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(DATE, VARCHAR)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: "2024-02-21" < date

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DATE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DATE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: "2024-02-22" < date

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DATE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DATE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: "2024-02-20" < date

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DATE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DATE)","error_subtype":"NO_MATCHING_FUNCTION"}

# <date> < <string> :: "2024-03-21 and then some" < date

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::<", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Binder","exception_message":"No function matches the given name and argument types 'r_base::<(VARCHAR, DATE)'. You might need to add explicit type casts.\n\tCandidate functions:\n\tr_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, BOOLEAN) -> BOOLEAN\n\tr_base::<(INTEGER, INTEGER) -> BOOLEAN\n\tr_base::<(DOUBLE, INTEGER) -> BOOLEAN\n\tr_base::<(INTEGER, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, BOOLEAN) -> BOOLEAN\n\tr_base::<(BOOLEAN, DOUBLE) -> BOOLEAN\n\tr_base::<(DOUBLE, DOUBLE) -> BOOLEAN\n\tr_base::<(VARCHAR, VARCHAR) -> BOOLEAN\n\tr_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN\n\tr_base::<(DATE, DATE) -> BOOLEAN\n\tr_base::<(TIMESTAMP, DATE) -> BOOLEAN\n\tr_base::<(DATE, TIMESTAMP) -> BOOLEAN\n","name":"r_base::<","candidates":"r_base::<(BOOLEAN, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, INTEGER) -> BOOLEAN,r_base::<(INTEGER, BOOLEAN) -> BOOLEAN,r_base::<(INTEGER, INTEGER) -> BOOLEAN,r_base::<(DOUBLE, INTEGER) -> BOOLEAN,r_base::<(INTEGER, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, BOOLEAN) -> BOOLEAN,r_base::<(BOOLEAN, DOUBLE) -> BOOLEAN,r_base::<(DOUBLE, DOUBLE) -> BOOLEAN,r_base::<(VARCHAR, VARCHAR) -> BOOLEAN,r_base::<(TIMESTAMP, TIMESTAMP) -> BOOLEAN,r_base::<(DATE, DATE) -> BOOLEAN,r_base::<(TIMESTAMP, DATE) -> BOOLEAN,r_base::<(DATE, TIMESTAMP) -> BOOLEAN","call":"r_base::<(VARCHAR, DATE)","error_subtype":"NO_MATCHING_FUNCTION"}

