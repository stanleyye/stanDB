/* The simplest usage of the library.
 */

#include <boost/program_options.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/tokenizer.hpp>
namespace po = boost::program_options;

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;
using namespace boost;

void commandLoop() {
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
			tokenizer<> tok(input);
			for (tokenizer<>::iterator begin = tok.begin(); begin != tok.end(); begin++) {
				commands.push_back("--" + *begin);
			}

			po::store(po::command_line_parser(commands).options(desc).run(), vm);
			po::notify(vm);

			if (vm.count("help")) {
				cout << desc << endl;
			}

			if (vm.count("exit") || vm.count("quit")) {
				printf("Terminating...bye");
				exit(EXIT_SUCCESS);
			}
		} catch (std::exception& e) {
			printf("%s\n", e.what());
		}


	}

}

int main(int argc, char* argv[]) {
    commandLoop();
    return 0;
}
