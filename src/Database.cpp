/*
 * Database.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#include "Database.h"

Database::Database() {
	Options options;
	  // create the DB if it's not already present
	options.create_if_missing = true;
	  // open DB
	Status s = DB::Open(options, kDBPath, &database);
	 // std::cout << s.ToString() << std::endl;
	if(s.ok){
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "UsersTable", &this->usersTable);
		assert(s.ok());
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "messagesTable", &this->messagesTable);
		assert(s.ok());
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "conversationsTable", &this->conversationsTable);
		assert(s.ok());
	  }

	  assert(s.ok());

	  // Put key-value
	  s = database->Put(WriteOptions(), "key1", "value");
	  assert(s.ok());
	  std::string value;
	  // get value
	  s = database->Get(ReadOptions(), "key1", &value);
	  assert(s.ok());
	  assert(value == "value");

	  // atomically apply a set of updates
	  {
	    WriteBatch batch;
	    batch.Delete("key1");
	    batch.Put("key2", value);
	    s = database->Write(WriteOptions(), &batch);
	  }

	  s = database->Get(ReadOptions(), "key1", &value);
	  assert(s.IsNotFound());

	  database->Get(ReadOptions(), "key2", &value);
	  assert(value == "value");


}

Database::~Database() {
	  delete database;
}

bool Database::put(string key, string value){
	Status s = database->Put(WriteOptions(), key, value);
	return s.ok;
}

string Database::get(string key, string value){
	Status s = database->Get(ReadOptions(), key, &value);
	return s.ok;
}



bool Database::saveUser(User* user) {
	string username = user->getUsername();
	string json = user->toJsonString();
	return this->put(this->userCF,username,json);
}

Message* Database::getMessage(string key){

}



