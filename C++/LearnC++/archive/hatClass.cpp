/*
 * hatClass.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: contrarian
 */
#include <iostream>
#include <string>
#include "hatClass.h"

//using namespace std;

hat :: hat() {}

hat :: hat(string owner, string type, int size) {
	_owner = owner;
	_type = type;
	_size = size;
}



void hat::setOwner(string name) {
	_owner = name;
}

string hat::getOwner() {
	return _owner;
}

void hat::setType(string type) {
	_type = type;
}

string hat::getType() {
	return _type;
}

void hat::setSize(int size) {
	_size = size;
}

int hat::getSize() {
	return _size;
}
