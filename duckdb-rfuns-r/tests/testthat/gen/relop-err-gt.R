# Generated by helper-gen.R + relop-err.txt: do not edit by hand
"<str> > <dbl>"
'2' > 1.0
'42.3' > 42.3
'42.4' > 42.3
'42.299999999' > 42.3
'1' > 1.0
'1' > NA_real_
NA_character_ > 3.0
"a" > 1.0

"<dbl> > <str>"
1.0 > '2'
1.0 > '1'
NA_real_ > "2"
3.0 > NA_character_
1.0 > "a"

"<int> > <str>"
NA_integer_ > "string"
1L > "1"
1L > NA_character_
1L > "a"

"<str> > <int>"
"string" > NA_integer_
"1" > 1L
NA_character_ > 2L
"a" > 1L

"<time> > <string>"
time > "2024-02-21 14:00:00"
time > "2024-02-21 13:00:00"
time > "2024-02-21 15:00:00"
"2024-02-21 14:00:00" > time
"2024-02-21 13:00:00" > time
"2024-02-21 15:00:00" > time

"<date> > <string>"
date > "2024-02-21"
date > "2024-02-22"
date > "2024-02-20"
date > "2024-03-21 and then some"
"2024-02-21" > date
"2024-02-22" > date
"2024-02-20" > date
"2024-03-21 and then some" > date
