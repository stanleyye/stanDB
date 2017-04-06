#include "User.h"

vector<User*> User::_listOfUsers;

User::User(string id, string password) {
	// TODO: hash + salt the password
	boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
	string currentTime = boost::posix_time::to_iso_extended_string(now);

	_id = id;
	_password = password;
	_dateCreated = currentTime;
	_lastLoggedIn = currentTime;

	cout << "User '" << _id << "' created on " << _dateCreated << endl;
}

vector<User*> User::getListOfUsers() {
	return User::_listOfUsers;
}

void User::addUser(User* user) {
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
