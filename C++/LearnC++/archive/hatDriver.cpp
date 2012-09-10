/*
 * hatDriver.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: contrarian
 */
#include <iostream>
#include <string>
using namespace std;
#include "hatClass.cpp"
#include "hats.cpp"

int main(){
	//hat fedora;
	string name;
	string type;
	int size;
	int quantity;
	cout << "Enter Name: ";
	getline(cin, name);
	cout << "Enter Type: ";
	getline(cin, type);
	cout << "Enter Size: ";
	cin >> size;
	cout << "Enter Quantity: ";
	cin >> quantity;
	hat fedora(name, type, size);
	hats order();
	order.setOwner(name);
	order.setType(type);
	order.setSize(size);
	order.setQuantity(quantity);
	cout << "This " << order.getType() << " belongs to " << order.getOwner() << endl;
	cout << "It is a size " << order.getSize() << endl;
	cout << "There are " << order.getQuantity() << " in the order" << endl;
	return 0;
}





