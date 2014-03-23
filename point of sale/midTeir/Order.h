#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "OrderQuery.h"
#include "Menu.h"

using namespace std;
const string PENDING("Pending");


class Order{

public:
	Order();
	string getOrderID(string tableID, string waiterID);
	void assignID();
	string myID();
	void getOrder(string waiterID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void billTotal();
	void billTotalDifferentOrder(string orderID);
	string getBillTotal(string orderID);
	void updateOrderStatus(string orderID, string status);
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	void showOpenOrdersWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showRTSOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showPendingOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showClosedOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	//*********************************************************************************************************************************
	void showOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showRTSOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showPendingOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void showClosedOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	OrderQuery orderQuery;
	string ID;
	string idTable;
	Menu menu;
 
};

#endif