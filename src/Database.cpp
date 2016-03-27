/*
 * Database.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#include "Database.h"

std::string DBpath = "./database";


Database::Database() {
	Options options;
	  // create the DB if it's not already present
	options.create_if_missing = true;
	  // open DB
	Status s = DB::Open(options, DBpath, &database);
	 // std::cout << s.ToString() << std::endl;
	if(s.ok()){
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "UsersTable", &this->usersTable);
		assert(s.ok());
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "messagesTable", &this->messagesTable);
		assert(s.ok());
		s = database->CreateColumnFamily(ColumnFamilyOptions(), "conversationsTable", &this->conversationsTable);
		assert(s.ok());
	  }

	  assert(s.ok());

	  /*
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

	*/
}

Database::~Database() {
	  delete database;
}

bool Database::put(string key, string value){
	Status s = database->Put(WriteOptions(), key, value);
	return s.ok();
}

string Database::get(string key, string value){
	Status s = database->Get(ReadOptions(), key, &value);
	return value;
}

bool Database::putInTable(ColumnFamilyHandle* tableHandler, string key, string value){
	Status s = database->Put(WriteOptions(), tableHandler, key, value);
	return s.ok();
}

string Database::getFromTable(ColumnFamilyHandle* tableHandler, string key){
	string value;
	Status s = database->Get(ReadOptions(), key, &value);
	return value;
}

bool Database::saveUser(User* user) {
	string username = user->getUsername();
	string json = user->getJsonString();
	return this->putInTable(this->usersTable,username,json);
	return true;
}
User* Database::getUser(string username) {
	string json = this->getFromTable(this->usersTable, username);
	Json::Value jsonValue = this->getJsonValue(json);
	User* user = new User(username);
	user->initWithJson(jsonValue);
	return user;
}

Message* Database::getMessage(string key){

}

Json::Value Database::getJsonValue(string str) {
	Json::Reader r = Json::Reader();
	Json::Value val = Json::Value();
	r.parse(str,val,false);
	return val;
}


