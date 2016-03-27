/*
 * Message.h
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "json/json.h"
#include "User.h"

using namespace std;
using namespace Json;


class Message {
public:
	Message(User* sender, User* receptor, string data );
	virtual ~Message();

private:
	User* sender;
	User* receptor;
	string id;
	string date;
	string data;

};

#endif /* MESSAGE_H_ */
