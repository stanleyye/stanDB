/* The simplest usage of the library.
 */

#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;
using namespace boost;

void commandLoop() {
	typedef tokenizer< char_separator<char> > t_tokenizer;
	printf("Welcome to stanDB.\n");
	printf("For more options, enter --help\n");

	string input;
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "Lists all the available commands.")
		("exit", "Exit stanDB.")
		("quit", "Quits stanDB. Same as exit.");
	po::variables_map vm;

	// loop to keep the program running and accept commands
	while (1) {
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
				if (command == "exit" || command == "quit") {
					printf("Terminating...bye.\n");
					exit(EXIT_SUCCESS);
				}
				commands.push_back(*begin);
			}

			po::store(po::command_line_parser(commands).options(desc).run(), vm);
			po::notify(vm);

			if (vm.count("help")) {
				cout << desc << endl;
				vm.erase("help");
			}

			if (vm.count("exit") || vm.count("quit")) {
				if (vm.count("exit")) {
					vm.erase("exit");
				} else {
					vm.erase("quit");
				}

				printf("Terminating...bye.\n");
				exit(EXIT_SUCCESS);
			}
		} catch (std::exception& e) {
			printf("%s\n", e.what());
		}


	}
}

void createUsersDirectory() {
	fs::path dir("users");
	if(!(fs::exists(dir))){
		if (boost::filesystem::create_directory(dir)) {
			cout << "The directory " << dir << "has been successfully created" << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	createUsersDirectory();
    commandLoop();
    return 0;
}
