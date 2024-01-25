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

### Build the duckdbrfuns R package

The `duckdbrfuns` package in the `r/` directory has some tools to facilitate 
working with the extension. 

One you've `make` the extension, you can develop the :package: normally, i.e. open the `r/duckdbrfuns.Rproj`
in RStudio and use `load_all()`, `document()` ... 

You can also use the `pkg` target

```sh
make pkg
```

## Running the extension in R

One you have the extension built and the R package installed, you can use the 
user defined functions: 

```r
library(duckdb)
con <- duckdbrfuns:::con()
```

```r
> dbGetQuery(con, 'SELECT "r_base::+"(1, 2)')
  r_base::+(1, 2)
1               3
```

## Running the extension outside of R

The extension may also be used outside of R, via the `./build/release/duckdb` executable: 

```duckdb
D select "r_base::+"(1, 2);
┌─────────────────┐
│ r_base::+(1, 2) │
│      int32      │
├─────────────────┤
│               3 │
└─────────────────┘
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
