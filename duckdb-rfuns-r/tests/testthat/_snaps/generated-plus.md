# <dbl> + <dbl> :: 1 + 1

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                 2

# <dbl> + <dbl> :: 1e+06 + 2e+06

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1             3e+06

# <dbl> + <dbl> :: 1e+09 + 2e+09

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1             3e+09

# <dbl> + <dbl> :: 1 + NA_real_

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

# <dbl> + <dbl> :: NA_real_ + 2

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

# <int> + <int> :: 1 + 2

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                 3

# <int> + <int> :: NaN + 2

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

# <int> + <int> :: NA_real_ + 2

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

# <int> + <int> :: 1 + NA_real_

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

# <int> + <int> :: 1 + NaN

    Code
      out_df
    Output
        r_base::+(x1, x2)
      1                NA

