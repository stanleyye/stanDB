/*
 * User.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: stanley
 */

#include "User.h"

vector<User> User::_listOfUsers;

User::User(string id, string password) {
	// TODO: hash + salt the password
	_id = id;
	_password = password;
	time_t currentTime = time(0);
	_dateCreated = localtime(&currentTime);
	_lastLoggedIn = localtime(&currentTime);
}

vector<User> User::getListOfUsers() {
	return User::_listOfUsers;
}

void User::addUser(User user) {
	User::_listOfUsers.push_back(user);
}

void User::deleteUser(string userId) {
	// TODO: delete based on user id
}

void User::findUser(string userId) {
	// TODO: find user and compare authentication details
}

string User::getId() const {
	return _id;
}

std::ostream & operator<<(ostream &os, const User &user) {
	os << "The user's id is " << user.getId() << '\n';
	return os;
}

User::~User() {
}

