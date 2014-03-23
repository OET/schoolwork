#ifndef WAITER_H
#define WAITER_H

#include <string>
#include "User.h"
#include "WaiterQuery.h"
#include "Table.h"
#include "CustomerBill.h"


using namespace std;

class Waiter: public User{

public:
	Waiter();
	Waiter(string waiterUsername);
	//Waiter(string waiterID);
	Waiter(string first, string last, string password);
	string getID();

	void newOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);  //0

	void listAllOrderStatus(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);//1

    void displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //2
	//void displayOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //2

	void calculateTotal(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //3
	void calculateTotalEnterOrderID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //4

private:
	Table currentTable;
	WaiterQuery waiterQuery;
	CustomerBill bill;
	string ID;
};

#endif
