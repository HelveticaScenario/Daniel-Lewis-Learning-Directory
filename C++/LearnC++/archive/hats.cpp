/*
 * hats.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: contrarian
 */
#include <iostream>
#include "hats.h"
using namespace std;
//namespace hats {

hats::hats() {
	// TODO Auto-generated constructor stub
	_quantity = 1;
}

hats::hats(string name, string type, int size, int quantity) : hat(name, type, size) {
	_quantity = quantity;
}

hats::hats(hat source, int quantity){
	_owner = source._owner;
	_type = source._type;
	_size = source._size;
	_quantity = quantity;
}

hats::~hats() {
	// TODO Auto-generated destructor stub
}

void hats::setQuantity(int quantity){
	_quantity = quantity;
}

int hats::getQuantity(){
	return _quantity;
}

//} /* namespace hats */
