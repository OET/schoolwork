#ifndef OWNERQUERY_H
#define OWNERQUERY_H

#include <string>
#include "BaseQ.h"

class OwnerQuery: public BaseQ{
public:
	void displayResults();
	//reports display
	//calculation of profit


private:
	BaseQ baseQuery;
	string customQuery;	

};
#endif