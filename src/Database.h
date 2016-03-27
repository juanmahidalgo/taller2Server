/*
 * Database.h
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

#include "Message.h"


using namespace rocksdb;
using namespace std;


class Database {
public:
	Database();

	string get(string key, string value);
	string getFromTable(ColumnFamilyHandle* tableHandler, string key);
	bool put(string key, string value);
	User* getUser(string key);
	bool saveUser(User* user);
	Message* getMessage(string key);
	bool saveMessage(Message* message);
	virtual ~Database();
	bool putInTable(ColumnFamilyHandle* tableHandler, string key, string value);
	Json::Value getJsonValue(string str);



private:
	DB* database;
	ColumnFamilyHandle* usersTable;
	ColumnFamilyHandle* conversationsTable;
	ColumnFamilyHandle* messagesTable;

};

#endif /* DATABASE_H_ */
