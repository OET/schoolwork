#include <iostream>
#include <string>
#include "CustomerBill.h"

using namespace std;

void CustomerBill::newBillForTable(string tableWaiter, string tableNumber, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	billID = order.myID();
	query.newBill(order.myID(),tableNumber, tableWaiter);
	order.getOrder(tableWaiter, ss, stream);
}
void CustomerBill::calculateBillTotal(){
	order.billTotal();
}
string CustomerBill::getBill_id(){
	return billID;
}
void CustomerBill::listOpenOrders(string waiterID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	order.showOpenOrdersWaiter(waiterID, ss, stream);
}
void CustomerBill::listPendingOrders(string waiterID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	order.showPendingOrderWaiter(waiterID, ss, stream);
}
void CustomerBill::calculateBillEnterOrder(string orderID){
	order.billTotalDifferentOrder(orderID);
}
//for calculate button in new order menu
void CustomerBill::getBillTotal(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string temp = order.getBillTotal(order.myID());
	*ss << "Bill Total for Order ID "+ order.myID()<< ": "<< temp <<endl;
	(*stream)<<ss->str();
	(*stream).clear();
    ss->str(string());

    *ss << "Bill Total calculation done."<<endl;
    (*stream)<<ss->str();

    (*stream).clear();
    ss->str(string());
}

//for independant menu option
void CustomerBill::getBillTotalEnterID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string total;
	string clientResponse;

	*ss << "Enter order ID to calculate:"<<endl;
	(*stream)<<ss->str();
	(*stream)>>clientResponse;

    (*stream).clear();
    ss->str(string());

    order.billTotalDifferentOrder(clientResponse);
	total = order.getBillTotal(clientResponse);

	*ss << "Bill Total for Order ID "+ clientResponse<< ": "<< total <<endl;
	(*stream)<<ss->str();
    (*stream).clear();
    ss->str(string());

    *ss << "Bill Total calculation done."<<endl;
    (*stream)<<ss->str();

    (*stream).clear();
    ss->str(string());




}
