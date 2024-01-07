var duckdb = require('../../duckdb/tools/nodejs');
var assert = require('assert');

describe(`rfuns extension`, () => {
    let db;
    let conn;
    before((done) => {
        db = new duckdb.Database(':memory:', {"allow_unsigned_extensions":"true"});
        conn = new duckdb.Connection(db);
        conn.exec(`LOAD '${process.env.RFUNS_EXTENSION_BINARY_PATH}';`, function (err) {
            if (err) throw err;
            done();
        });
    });

    it('rfuns function should return expected string', function (done) {
        db.all("SELECT rfuns('Sam') as value;", function (err, res) {
            if (err) throw err;
            assert.deepEqual(res, [{value: "Rfuns Sam 🐥"}]);
            done();
        });
    });

    it('rfuns_openssl_version function should return expected string', function (done) {
        db.all("SELECT rfuns_openssl_version('Michael') as value;", function (err, res) {
            if (err) throw err;
            assert(res[0].value.startsWith('Rfuns Michael, my linked OpenSSL version is OpenSSL'));
            done();
        });
    });
});