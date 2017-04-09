/*
 * CommandOptions.h
 *
 *  Created on: Apr 8, 2017
 *      Author: stanley
 */

#ifndef COMMANDOPTIONS_HPP_
#define COMMANDOPTIONS_HPP_

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <User.hpp>

using namespace std;

class CommandOptions {
public:
	CommandOptions() {};
	virtual ~CommandOptions() {};
	static void parseCommands(string command, string arg);
};

#endif /* COMMANDOPTIONS_HPP_ */
