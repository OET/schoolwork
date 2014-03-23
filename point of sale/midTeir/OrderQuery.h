#ifndef ORDERQUERY_H
#define ORDERQUERY_H


#include <string>
#include "BaseQ.h"

using namespace std;


class OrderQuery: public BaseQ{
public:

	int getOrderID(string tableID, string waiterID);
	string assignOrderID();
	void addToOrder(string orderNumber, string menuItemNum, string orderArrayPostion);
	void itemQuantity(string orderNumber, string numOfItem, string orderArrayPostion);
	void initializeOrder(string employeeID, string orderID);
	void updateStatus(string orderID, string status);
	//************************************************************************************************************************************
	string displayBillTotal(string orderID);
	void calcuateBillTotal(string orderID);
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	void displayPendingOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayOpenOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayClosedOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayRTSOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	//*************************************************************************************************************************************
	void displayClosedOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayRTSOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	string customQuery;	
};

#endif