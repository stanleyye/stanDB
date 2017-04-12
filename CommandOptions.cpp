/*
 * CommandOptions.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: stanley
 */

#include <CommandOptions.hpp>

void CommandOptions::parseCommands(string command, string arg) {
	vector<string> titles;

	// TODO: Use enums to map strings to values. Switch doesn't work with
	// strings but does work with values (which is why we map it)
	if (command == "show") {
		if (arg == "users") {
			titles.clear();
			titles.push_back("User");
			titles.push_back("Password");
			printTable(titles);
		}
	} else {
		cout << "Command '" + command + "' is not recognized." << endl;
	}
}

// TODO: take in generic types
void printTable(vector<string>& titles) {
	unsigned int titleIndex, titleMaxLength, usernameLength, passwordLength;
	string horizontalTitleBar, titleStrings;
	map<string, int> mapOfTitles;
	vector<User*> listOfUsers;
	vector<string> asciiTable;

	for (auto titleName = titles.begin(); titleName != titles.end(); titleName++) {
		mapOfTitles[*titleName] = titleName->length();
	}

	listOfUsers = User::getListOfUsers();
	// first find longest username + password to format tables
	for (auto user = listOfUsers.begin(); user != listOfUsers.end(); user++) {
		usernameLength = (*user)->getId().length();
		passwordLength = (*user)->getPassword().length();

		if (mapOfTitles.count("User") > 0 && usernameLength > mapOfTitles["User"]) {
			mapOfTitles["Users"] = usernameLength;
		}

		if (mapOfTitles.count("Password") > 0 && usernameLength > mapOfTitles["Password"]) {
			mapOfTitles["Password"] = passwordLength;
		}
	}

	for (titleIndex = 0; titleIndex < titles.size(); titleIndex++) {
		titleMaxLength = mapOfTitles[titles[titleIndex]];
		if (titleIndex == 0) {
			horizontalTitleBar += "+";
			horizontalTitleBar += string(titleMaxLength + 2, '-');
			horizontalTitleBar += "+";

			titleStrings += ("| " + titles[titleIndex] + " |");
		} else {
			horizontalTitleBar += string(titleMaxLength + 2, '-');
			horizontalTitleBar += "+";

			titleStrings += (" " + titles[titleIndex] + " |");
		}
	}
	cout << horizontalTitleBar << endl;
	cout << titleStrings << endl;
	cout << horizontalTitleBar << endl;

	for (auto u = listOfUsers.begin(); u != listOfUsers.end(); u++) {
		cout << "| " + (*u)->getId() + " | " + (*u)->getPassword() + " |" << endl;
	}
}
