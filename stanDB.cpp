#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>

#include <User.h>

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

	printf("Welcome to stanDB.\n");
	printf("For more options, enter --help\n");

	// loop to keep the program running and accept commands
	while (true) {
		po::variables_map vm;
		vector<string> commands;

		printf("stanDB> ");
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
					printf("Terminating...bye.\n");
					exit(EXIT_SUCCESS);
				}
				commands.push_back(*begin);
			}

			po::store(po::command_line_parser(commands).options(desc).run(), vm);
			po::notify(vm);

			if (vm.count("exit") || vm.count("quit")) {
				printf("Terminating...bye.\n");
				exit(EXIT_SUCCESS);
			}

			if (vm.count("help")) {
				cout << desc << endl;
			}

			// Clear junk left in stream, removing this makes parser not work
			cin.ignore();
		} catch (std::exception& e) {
			printf("%s\n", e.what());
			// Clear junk left in stream, removing this makes parser not work
			cin.ignore();
		}


	}
}

void adminLogin() {
	// By default, when the program is started, the default user is the admin user.
	// TODO: eventually add a login instead of setting default as admin
	fs::path dir("users");
	if(!(fs::exists(dir))){
		if (fs::create_directory(dir)) {
			cout << "The directory " << dir << " has been successfully created" << endl;
			ofstream ofs("users.dat");

			User* root = new User("root", "");
			User::addUser(*root);

			// testing purposes
			vector<User> listOfUsers = User::getListOfUsers();
			for (vector<User>::iterator i = listOfUsers.begin(); i != listOfUsers.end(); i++) {
				cout << "testing: " << *i << endl;
			}

			// TODO: serialize the list of users into users.dat file
		}
	}
}

int main(int argc, char* argv[]) {
	adminLogin();
    commandLoop();
    return 0;
}
