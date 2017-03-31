/* The simplest usage of the library.
 */

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void commandLoop() {
	printf("Welcome to stanDB. For more options, enter --help\n\n");
	string input;
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("testing",	"testing123123123");
	po::variables_map vm;

	while (1) {
		printf("stanDB> ");
		// User input must end with a ';'
		getline(cin, input, ';');

		if (input.length() > 0) {
			input.pop_back();
		}
		cout << input << endl;

//		try {
//
//			cout << desc << endl;
//		} catch (exception& e) {
//			cout << e.what() << "\n";
//			return;
//		}
	}

}

int main(int argc, char* argv[]) {
    commandLoop();
    return 0;
}
