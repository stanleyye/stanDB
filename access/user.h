#ifndef USER_H_
#define USER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/date_time.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

class User {
public:
	User() {}
	User(string id, string password);
	virtual ~User() {}

	static vector<User*> getListOfUsers();
	static void unserializeListOfUsers(vector<User*> listOfUsers);
	static void addUser(string id, string password);
	static void deleteUser(string userId);
	// TODO: change return value of findUser
	static void findUser(string userId);

	string getId() const;
	string getPassword() const;

	friend ostream & operator<<(ostream &os, const User &user);
private:
	string _id; // username
	string _password;
	string _dateCreated;
	string _lastLoggedIn;

	// TODO: use reference_wrapper (functional library) and push_back(ref(User))?
	static vector<User*> _listOfUsers;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & _listOfUsers;
		ar & _id;
		ar & _password;
		ar & _dateCreated;
		ar & _lastLoggedIn;
	}
};

#endif /* USER_H_ */
