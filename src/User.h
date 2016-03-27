/*
 * User.h
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#ifndef USER_H_
#define USER_H_

using namespace std;

class User {
public:
	User(string username);
	virtual ~User();
	string getName();
	void setName(string name);
	string getPassword();
	void setName(string name);
	double getLocationX() const;
	void setLocationX(double locationX);
	double getLocationY() const;
	void setLocationY(double locationY);
	void setPassword(const string& password);
	const string& getPerfilImage() const;
	void setPerfilImage(const string& perfilImage);
	const string& getToken() const;
	void setToken(const string& token);
	const string& getUsername() const;
	void setUsername(const string& username);

private:
	string password;
	string username;
	double locationX;
	double locationY;
	string perfilImage;
	string token;

};

#endif /* USER_H_ */
