/*
 * hatClass.h
 *
 *  Created on: Aug 18, 2012
 *      Author: contrarian
 */

#ifndef HATCLASS_H_
#define HATCLASS_H_
#include <iostream>
//#include <string>
//namespace hat{
using namespace std;

class hat{
protected:
	string _owner;
	string _type;
	int _size;
public:
	hat();
	hat(string, string, int);
	void setOwner(string);
	void setType(string);
	void setSize(int);

	string getOwner();
	string getType();
	int getSize();
};

//}


#endif /* HATCLASS_H_ */
