// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.

#include <cstdio>
#include <string>
#include <iostream>
#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"
#include "mongoose.h"

using namespace rocksdb;
using namespace std;

std::string kDBPath = "rocksdb_simple_example";

int main() {

  DB* db;
  Options options;
  // create the DB if it's not already present
  options.create_if_missing = true;

  // open DB
  Status s = DB::Open(options, kDBPath, &db);
 // std::cout << s.ToString() << std::endl;

  assert(s.ok());

  // Put key-value
  s = db->Put(WriteOptions(), "key1", "value");
  assert(s.ok());
  std::string value;
  // get value
  s = db->Get(ReadOptions(), "key1", &value);
  assert(s.ok());
  assert(value == "value");

  // atomically apply a set of updates
  {
    WriteBatch batch;
    batch.Delete("key1");
    batch.Put("key2", value);
    s = db->Write(WriteOptions(), &batch);
  }

  s = db->Get(ReadOptions(), "key1", &value);
  assert(s.IsNotFound());

  db->Get(ReadOptions(), "key2", &value);
  assert(value == "value");

  delete db;

  return 0;
}
