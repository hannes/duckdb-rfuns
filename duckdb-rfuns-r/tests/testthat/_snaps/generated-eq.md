# <int> == <int> :: 0L == 0L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <int> :: 1L == 0L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <int> :: 1L == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <int> :: NA_integer_ == 2L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <int> :: NA_integer_ == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <lgl> :: TRUE == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <lgl> :: TRUE == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <lgl> :: FALSE == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <lgl> :: FALSE == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <lgl> :: NA == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <lgl> :: NA == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <lgl> :: TRUE == NA

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <lgl> :: FALSE == NA

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <lgl> :: 1 == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <lgl> :: 1 == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <lgl> :: 2 == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <lgl> :: 2 == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <lgl> :: 0 == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <lgl> :: 0 == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <lgl> :: NA_integer_ == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <lgl> :: NA_integer_ == NA

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <lgl> :: 42 == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <int> :: TRUE == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <int> :: FALSE == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <int> :: TRUE == 2

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <int> :: FALSE == 2

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <int> :: TRUE == 0

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <int> :: FALSE == 0

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <int> :: TRUE == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <int> :: NA == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <int> :: NA == 42

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <dbl> :: 1.5 == 2

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <dbl> == <dbl> :: 1.5 == 1.5

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <dbl> == <dbl> :: 1.5 == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <dbl> :: NA_real_ == 2.5

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <int | lgl> :: 2 == 2L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <dbl> == <int | lgl> :: 3.5 == 2L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <dbl> == <int | lgl> :: 3.5 == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <int | lgl> :: 1 == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <dbl> == <int | lgl> :: 1 == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <dbl> == <int | lgl> :: 0 == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <dbl> == <int | lgl> :: 0 == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <dbl> == <int | lgl> :: 2 == NA

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <int | lgl> :: NA_real_ == 42L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <int | lgl> :: NA_real_ == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <dbl> == <int | lgl> :: NA_real_ == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int | lgl> == <dbl> :: 2L == 2

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int | lgl> == <dbl> :: 2L == 3.5

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int | lgl> == <dbl> :: NA_integer_ == 3.5

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int | lgl> == <dbl> :: TRUE == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int | lgl> == <dbl> :: FALSE == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int | lgl> == <dbl> :: FALSE == 0

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int | lgl> == <dbl> :: TRUE == 0

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int | lgl> == <dbl> :: NA == 0

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int | lgl> == <dbl> :: 42L == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int | lgl> == <dbl> :: TRUE == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int | lgl> == <dbl> :: FALSE == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str> == <str> :: "a" == "b"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str> == <str> :: "a" == "a"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <str> == <str> :: "a" == NA_character_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str> == <str> :: NA_character_ == "a"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str>        == <lgl> :: "TRUE" == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <str>        == <lgl> :: "TRUE" == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str>        == <lgl> :: "TRUE" == NA

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str>        == <lgl> :: NA_character_ == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str>        == <lgl> :: NA_character_ == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str>        == <lgl> :: "FALSE" == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str>        == <lgl> :: "FALSE" == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <str>        == <lgl> :: "tRue" == TRUE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str>        == <lgl> :: "fAlse" == FALSE

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <str> :: TRUE == "TRUE"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <str> :: FALSE == "TRUE"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <str> :: NA == "TRUE"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <str> :: TRUE == NA_character_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <str> :: FALSE == NA_character_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <lgl> == <str> :: TRUE == "FALSE"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <str> :: FALSE == "FALSE"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <lgl> == <str> :: TRUE == "tRue"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <lgl> == <str> :: FALSE == "fAlse"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str> == <dbl> :: "2" == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str> == <dbl> :: "1" == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <str> == <dbl> :: "1" == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str> == <dbl> :: NA_character_ == 3

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str> == <dbl> :: 1 == "2"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <str> == <dbl> :: 1 == "1"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <str> == <dbl> :: NA_real_ == "2"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <str> == <dbl> :: 3 == NA_character_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <str> :: NA_integer_ == "string"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <str> :: 1L == "1"

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <str> :: "string" == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <str> :: "1" == 1L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <dbl> :: 2L == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <dbl> :: 1L == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <dbl> :: NA_integer_ == 1

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <dbl> :: 3L == NA_real_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <dbl> :: 1 == 2L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1              FALSE

# <int> == <dbl> :: 1 == 1L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1               TRUE

# <int> == <dbl> :: 1 == NA_integer_

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

# <int> == <dbl> :: NA_real_ == 3L

    Code
      out_df
    Output
        r_base::==(x1, x2)
      1                 NA

