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
#include "User.h"


using namespace rocksdb;
using namespace std;


class Database {
public:
	Database();

	string get(string key);
	bool put(string key, string value);
	User* getUser(string key);
	bool saveUser(User* user);


	virtual ~Database();
};

#endif /* DATABASE_H_ */
