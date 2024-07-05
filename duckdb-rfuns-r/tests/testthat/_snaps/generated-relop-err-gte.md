# <str> >= <dbl> :: "2" >= 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "42.3" >= 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "42.4" >= 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "42.299999999" >= 42.3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "1" >= 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "1" >= NA_real_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: NA_character_ >= 3

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <str> >= <dbl> :: "a" >= 1

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : VARCHAR <=> DOUBLE"}

# <dbl> >= <str> :: 1 >= "2"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# <dbl> >= <str> :: 1 >= "1"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# <dbl> >= <str> :: NA_real_ >= "2"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# <dbl> >= <str> :: 3 >= NA_character_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# <dbl> >= <str> :: 1 >= "a"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and doubles is not supported : DOUBLE <=> VARCHAR"}

# <int> >= <str> :: NA_integer_ >= "string"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

# <int> >= <str> :: 1L >= "1"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

# <int> >= <str> :: 1L >= NA_character_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

# <int> >= <str> :: 1L >= "a"

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : INTEGER <=> VARCHAR"}

# <str> >= <int> :: "string" >= NA_integer_

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

# <str> >= <int> :: "1" >= 1L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

# <str> >= <int> :: NA_character_ >= 2L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

# <str> >= <int> :: "a" >= 1L

    Code
      duckdb:::rel_project(in_rel, list(duckdb:::expr_function("r_base::>=", list(
        duckdb:::expr_reference("x1"), duckdb:::expr_reference("x2")))))
    Condition
      Error:
      ! {"exception_type":"Invalid Input","exception_message":"Comparing strings and integers is not supported : VARCHAR <=> INTEGER"}

