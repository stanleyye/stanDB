/*
 * User.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: stanley
 */

#include "User.h"

User::User(string id, string password) {
	_id = id;
	_password = password;
	time_t currentTime = time(0);
	_dateCreated = localtime(&currentTime);
	_lastLoggedIn = localtime(&currentTime);
}

User::~User() {
}

