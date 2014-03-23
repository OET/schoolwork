#ifndef WAITERQUERY_H
#define WAITERQUERY_H

#include <string>
#include "BaseQ.h"


using namespace std;

class WaiterQuery: public BaseQ{
public:
	void displayResults(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displyOrderStatus(string waiterID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	string customQuery;	

};


#endif