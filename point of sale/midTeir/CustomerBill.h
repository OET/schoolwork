#ifndef CUSTOMERBILL_H
#define CUSTOMERBILL_H


#include <string>
#include "CustomerBillQuery.h"
#include "Order.h"

using namespace std;

class CustomerBill{
public:
	void newBillForTable(string tableWaiter, string tableNumber, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void calculateBillTotal();
	void calculateBillEnterOrder(string orderID);
	string getBill_id(); //order ID
	void listOpenOrders(string waiterID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void listPendingOrders(string waiterID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void getBillTotal(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void getBillTotalEnterID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	Order order;
	string billID;
	CustomerBillQuery query;
};
#endif
