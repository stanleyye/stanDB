#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

#include <User.h>
#include <boost/algorithm/string.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/tokenizer.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

using namespace std;
using namespace boost;

void commandLoop() {
	typedef tokenizer< char_separator<char> > t_tokenizer;
	string input;
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "Lists all the available commands.")
		("exit", "Exit stanDB.")
		("quit", "Quits stanDB. Same as exit.");

	cout << "Welcome to stanDB." << endl;
	cout << "For more options, enter --help" << endl << endl;

	// loop to keep the program running and accept commands
	while (true) {
		po::variables_map vm;
		vector<string> commands;

		cout << "stanDB> ";
		// NOTE: User input must end with a ';'
		getline(cin, input, ';');

		try {
			// The shell does not support whitespace inside quotes, as whitespace
			// is used as the delimiter
			char_separator<char> separator(" ");
			t_tokenizer tok(input, separator);
			for (auto begin = tok.begin(); begin != tok.end(); begin++) {
				string command = *begin;
				boost::trim(command);
				cout << "command : " << command << endl;
				if (command == "exit" || command == "quit") {
					cout << "Terminating...bye." << endl;
					exit(EXIT_SUCCESS);
				}
				commands.push_back(*begin);
			}

			po::store(po::command_line_parser(commands).options(desc).run(), vm);
			po::notify(vm);

			if (vm.count("exit") || vm.count("quit")) {
				cout << "Terminating...bye." << endl;
				exit(EXIT_SUCCESS);
			}

			if (vm.count("help")) {
				cout << desc << endl;
			}
		} catch (std::exception& e) {
			cout << e.what() << endl;
		}
		// Clear junk left in stream, removing this makes parser not work
		cin.ignore();
	}
}

void adminLogin() {
	// By default, when the program is started, the default user is the admin user.
	// TODO: eventually add a login instead of setting default as admin
	fs::path dir("users");
	if(!(fs::exists(dir))){
		if (fs::create_directory(dir)) {
			cout << "The directory " << dir << " has been successfully created." << endl;

			// create the default user 'root'
			User* root = new User("root", "");
			User::addUser(root);

			// serialize root user data to users.dat
			ofstream userFileOfs("users.dat", ios::binary);
			boost::archive::binary_oarchive userFileOArchive(userFileOfs);
			userFileOArchive << root;

			userFileOfs.close();

			// TODO: use RAII
			delete root;

			ifstream userFileIfs("users.dat", ios::binary);
			boost::archive::binary_iarchive userFileIArchive{userFileIfs};
			User* u;
			userFileIArchive >> u;
			cout << "\nYou are now logged in as: " << u->getId() << "\n\n";
		}
	}
}

int main(int argc, char* argv[]) {
	adminLogin();
    commandLoop();
    return 0;
}
