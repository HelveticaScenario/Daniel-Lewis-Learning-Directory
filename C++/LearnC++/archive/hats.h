/*
 * hats.h
 *
 *  Created on: Aug 18, 2012
 *      Author: contrarian
 */

#ifndef HATS_H_
#define HATS_H_

#include "hatClass.h"

//namespace hats {

class hats: public hat {
protected:
	int _quantity;
public:
	hats();
	hats(string, string, int, int);
	hats(hat, int);
	virtual ~hats();

	void setQuantity(int);
	int getQuantity();
};

//} /* namespace hats */
#endif /* HATS_H_ */
