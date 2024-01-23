# Quack

This repository is based on https://github.com/duckdb/extension-template, check it out if you want to build and ship your own DuckDB extension.

---

This extension, Quack, allow you to ... <extension_goal>.

## Building

### Getting started

First step is to clone this repo and make sure you pull in 
DuckDB by using `--recurse-submodules`: 

```shell
git clone --recurse-submodules https://github.com/krlmlr/duckdb-rfuns.git
```

### Build steps
Now to build the extension, run:
```sh
make
```
The main binaries that will be built are:
```sh
./build/release/duckdb
./build/release/test/unittest
./build/release/extension/rfuns/rfuns.duckdb_extension
```
- `duckdb` is the binary for the duckdb shell with the extension code automatically loaded.
- `unittest` is the test runner of duckdb. Again, the extension is already linked into the binary.
- `rfuns.duckdb_extension` is the loadable binary as it would be distributed.

## Running the extension

To `LOAD` the extension, `duckdb` should be initialized with the `allow_unsigned_extensions` option set to true. 

```r
library(duckdb)
con <- DBI::dbConnect(duckdb(config=list('allow_unsigned_extensions' = 'true')))
dbExecute(con, "LOAD '{{path to duckdb-rfuns}}/build/release/extension/rfuns/rfuns.duckdb_extension'")
```

Then, the extension can be used: 

```r
> dbGetQuery(con, "select rfuns('Jane')")
  rfuns('Jane')
1 Rfuns Jane 🐥
> dbGetQuery(con, 'SELECT "r_base::+"(1, 2)')
  r_base::+(1, 2)
1               3
```

The extension may also be used outside of R, via the `./build/release/duckdb` executable: 

```
D select rfuns('Jane') as result;
┌───────────────┐
│    result     │
│    varchar    │
├───────────────┤
│ rfuns Jane 🐥 │
└───────────────┘
```

## Running the tests

Different tests can be created for DuckDB extensions. The primary way of testing DuckDB extensions should be the SQL tests in `./test/sql`. These SQL tests can be run using:

```sh
make test
```

### Installing the deployed binaries

To install your extension binaries from S3, `duckdb` should also be launched with the `allow_unsigned_extensions` option set to true.

Secondly, you will need to set the repository endpoint in DuckDB to the HTTP url of your bucket + version of the extension
you want to install. To do this run the following SQL query in DuckDB:

```sql
SET custom_extension_repository='bucket.s3.eu-west-1.amazonaws.com/<your_extension_name>/latest';
```

Note that the `/latest` path will allow you to install the latest extension version available for your current version of
DuckDB. To specify a specific version, you can pass the version instead.

After running these steps, you can install and load your extension using the regular INSTALL/LOAD commands in DuckDB:

```sql
INSTALL rfuns
LOAD rfuns
```
