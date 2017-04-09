/*
 * CommandOptions.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: stanley
 */

#include <CommandOptions.hpp>

void CommandOptions::parseCommands(string command, string arg) {
	switch (command) {
		vector<string> titles;
		case "show":
			if (arg == 'users') {
				titles.clear();
				titles.push_back("User");
				titles.push_back("Password");
				printTable(titles);
			}
			break;
		default:
			cout << "Command '" + command + "' is not recognized." << endl;
			break;
	}
}

// TODO: take in generic types
void printTable(vector<string>& titles) {
	int titleIndex, titleMaxLength;
	string horizontalTitleBar, usernameLength, passwordLength;
	map<string, int> mapOfTitles;
	vector<User*> listOfUsers;

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
		} else {
			horizontalTitleBar += string(titleMaxLength + 2, '-');
			horizontalTitleBar += "+";
		}
	}
	cout << horizontalTitleBar << endl;
}
