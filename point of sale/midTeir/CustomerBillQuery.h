#ifndef CUSTOMERBILLQUERY_H
#define CUSTOMERBILLQUERY_H

#include <string>
#include "BaseQ.h"

using namespace std;


class CustomerBillQuery: public BaseQ{
public:
	void newBill(string orderID, string tableID, string waiterID);

private:
	string customQuery;

};
#endif