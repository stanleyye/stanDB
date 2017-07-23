/*
 * command_options.h
 *
 *  Created on: Apr 8, 2017
 *      Author: stanley
 */

#ifndef COMMAND_OPTIONS_H_
#define COMMAND_OPTIONS_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <access/user.h>

using namespace std;

// TODO: instead of this global function, use a lambda instead
void printTable(vector<string>& titles);

class CommandOptions {
public:
    CommandOptions() {}
    virtual ~CommandOptions() {}
	static void parseCommands(string command, string arg);
};

#endif /* COMMAND_OPTIONS_H_ */
