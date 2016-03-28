/*
 * Conversation.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: juanma
 */

#include "Conversation.h"

Conversation::Conversation() {
	// TODO Auto-generated constructor stub

}

Conversation::~Conversation() {
	// TODO Auto-generated destructor stub
}

const string& Conversation::getId() const {
	return id;
}

void Conversation::setId(const string& id) {
	this->id = id;
}

int Conversation::getNumberMessages() const {
	return numberMessages;
}

void Conversation::setNumberMessages(int numberMessages) {
	this->numberMessages = numberMessages;
}

const User*& Conversation::getUser1() const {
	return user1;
}

void Conversation::setUser1(const User*& user1) {
	this->user1 = user1;
}

const User*& Conversation::getUser2() const {
	return user2;
}

void Conversation::setUser2(const User*& user2) {
	this->user2 = user2;
}
