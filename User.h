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
#include <vector>
#include <iostream>

using namespace std;

class User {
public:
	User(string id, string password);
	virtual ~User();
	static vector<User> getListOfUsers();
	static void addUser(User user);
	static void deleteUser(string userId);
	// TODO: change return value later
	static void findUser(string userId);
	friend ostream & operator<<(ostream &os, const User &user);
	friend class boost::serialization::access;

	string getId() const;

private:
	string _id; // username
	string _password;
	struct tm* _dateCreated;
	struct tm* _lastLoggedIn;
	// currently only stores copies of User.
	// TODO: use reference_wrapper (functional library) and push_back(ref(User)) later
	static vector<User> _listOfUsers;
};

#endif /* USER_H_ */
