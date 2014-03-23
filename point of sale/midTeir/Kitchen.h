#ifndef KITCHEN_H
#define KITCHEN_H

#include <string>
#include "User.h"
#include "Order.h"
//#include "KitchenQuery.h"

using namespace std;


class Kitchen: public User{

public:

	Kitchen();
	Kitchen(string uerName);
	Kitchen(string first, string last, string password);
	string getID();

	//pending to RTS
	void updateOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);//0

	//display pending orders
	void displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //1

	//list content of order
	void displayOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream ); //2


private:
	string ID;
	Order order;
	string uname;
};

#endif
