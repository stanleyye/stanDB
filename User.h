/*
 * User.h
 *
 *  Created on: Apr 1, 2017
 *      Author: stanley
 */

#ifndef USER_H_
#define USER_H_

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <ctime>
#include <string>

using namespace std;

class User {
public:
	User(string id, string password);
	virtual ~User();
	friend ostream & operator<<(ostream &os, const User &user);
	friend class boost::serialization::access;

private:
	string _id; // username
	string _password;
	struct tm* _dateCreated;
	struct tm* _lastLoggedIn;
};

#endif /* USER_H_ */
