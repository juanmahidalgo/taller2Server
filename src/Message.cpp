/*
 * Message.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#include "Message.h"

Message::Message(User* sender, User* receptor, string data ) {
	// TODO Auto-generated constructor stub
	this->sender = sender;
	this->receptor = receptor;
	this->data = data;

}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

