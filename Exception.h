/*****************************************
** File:    Exceptions.h
** Project: project 2
** Author: benjamin Ramon
** Date: 02/05/2020
** Section:518
** E-mail:bramon24@tamu.edu
**
**  Exceptions to be thrown
**
*******************************************/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <string>

// same method for all of these

// have a throw fnuction, and a private variable msg that gets called whenever a error is
// throw in our function calls
class ItemNotFound : public exception {
public:
	explicit ItemNotFound(const std::string& m) {
		msg = "Item Not Found Exception: " + m + "\n";
	}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
private:
	string msg;
};

class CommandNotFound : public exception {
public:
	explicit CommandNotFound(const std::string& m) {
		msg = "Invalid Command Exception: " + m + " is not a valid arguement\n";
	}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
private:
	string msg;
};

class InvalidArgumentException : public exception {
public:
	explicit InvalidArgumentException(const std::string& m) {
		msg = "Invalid Arguement Exception: " + m + "\n";
	}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
private:
	string msg;
};

class NodeNotFound : public exception {
public:
	explicit NodeNotFound(const std::string& m) {
		msg = "Node Not Found Exception: " + m + "\n";
	}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
private:
	string msg;
};

class NULLArguemntException : public exception {
public:
	explicit NULLArguemntException(const std::string& m) {
		msg = "NULL Argument Exception: " + m + "\n";
	}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
private:
	string msg;
};



#endif
