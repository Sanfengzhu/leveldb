#include <cassert>
#include <iostream>
#include <string>

#include "leveldb/db.h"

using std::cout;
using std::endl;
using std::string;

using leveldb::DB;
using leveldb::Options;
using leveldb::ReadOptions;
using leveldb::Status;
using leveldb::WriteOptions;

int main() {
    DB *db;
    Options options;
    options.create_if_missing = true;
    Status status = DB::Open(options, "test_db", &db);
    assert(status.ok());

    status = db->Put(WriteOptions(), "test_key", "test_value");
    assert(status.ok());

    string res;
    status = db->Get(ReadOptions(), "test_key", &res);
    assert(status.ok());
    cout << res << endl;

    delete db;
    return 0;
}
