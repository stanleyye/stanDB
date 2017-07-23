#include <Server/User.hpp>

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

void User::unserializeListOfUsers(vector<User*> listOfUsers) {
	User::_listOfUsers = listOfUsers;
}

void User::addUser(string id, string password) {
	User* newUser = new User(id, password);
	User::_listOfUsers.push_back(newUser);

	// Serialize and unserialize everytime we add a user to persist the users data
	ofstream userFileOfs("users.dat", ios::binary);
	boost::archive::binary_oarchive userFileOArchive(userFileOfs);
	userFileOArchive << newUser;

	userFileOfs.close();

	// TODO: use RAII
	delete newUser;

	ifstream userFileIfs("users.dat", ios::binary);
	boost::archive::binary_iarchive userFileIArchive{userFileIfs};
	User* user;
	userFileIArchive >> user;
	User::_listOfUsers = user->getListOfUsers();
	cout << "\nThe user '" << user->getId() << "' has been created.\n\n";

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

string User::getPassword() const {
	return _password;
}

std::ostream & operator<<(ostream &os, const User &user) {
	os << "The user's id is " << user.getId() << '\n';
	return os;
}
