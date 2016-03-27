/*
 * User.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#include "User.h"

User::User(string name) {
	this->username = name;
	this->locationX = 0;
	this->locationY = 0;
	this->token = "";
	this->password = "";

}

User::~User() {
	// TODO Auto-generated destructor stub
}

double User::getLocationX() const {
	return locationX;
}

void User::setLocationX(double locationX) {
	this->locationX = locationX;
}

double User::getLocationY() const {
	return locationY;
}

void User::setLocationY(double locationY) {
	this->locationY = locationY;
}

void User::setPassword(const string& password) {
	this->password = password;
}

const string& User::getPerfilImage() const {
	return perfilImage;
}

void User::setPerfilImage(const string& perfilImage) {
	this->perfilImage = perfilImage;
}

const string& User::getToken() const {
	return token;
}

void User::setToken(const string& token) {
	this->token = token;
}

const string& User::getUsername() const {
	return username;
}

void User::setUsername(const string& username) {
	this->username = username;
}
