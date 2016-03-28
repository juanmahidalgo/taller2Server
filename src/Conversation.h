/*
 * Conversation.h
 *
 *  Created on: Mar 27, 2016
 *      Author: juanma
 */

#ifndef CONVERSATION_H_
#define CONVERSATION_H_

using namespace std;

class Conversation {
public:
	Conversation();
	virtual ~Conversation();
	const string& getId() const;
	void setId(const string& id);
	int getNumberMessages() const;
	void setNumberMessages(int numberMessages);
	const User*& getUser1() const;
	void setUser1(const User*& user1);
	const User*& getUser2() const;
	void setUser2(const User*& user2);

private:
	string id;
	User* user1;
	User* user2;
	int numberMessages;
};

#endif /* CONVERSATION_H_ */
