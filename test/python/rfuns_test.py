import duckdb
import os
import pytest

# Get a fresh connection to DuckDB with the rfuns extension binary loaded
@pytest.fixture
def duckdb_conn():
    extension_binary = os.getenv('RFUNS_EXTENSION_BINARY_PATH')
    if (extension_binary == ''):
        raise Exception('Please make sure the `RFUNS_EXTENSION_BINARY_PATH` is set to run the python tests')
    conn = duckdb.connect('', config={'allow_unsigned_extensions': 'true'})
    conn.execute(f"load '{extension_binary}'")
    return conn
