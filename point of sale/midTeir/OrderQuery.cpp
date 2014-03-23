 #include <iostream>
#include <string>
#include "OrderQuery.h"

using namespace std;


//order ID already assigned, just getting it using arguments
int OrderQuery::getOrderID(string tableID, string waiterID){
	int ID;
	customQuery ="SELECT orderid FROM customerbill WHERE tableid='"+tableID+ "' AND employeeid='"+waiterID+ "'";
	BaseQ::setQuery(customQuery, "customerbill");
	ID = BaseQ::getResult<int>();

	return ID;
}
//initial assignment of order ID
string OrderQuery::assignOrderID(){

	string temst;
	customQuery="INSERT INTO orders(\"orderid\") VALUES (nextval('ordersq')); SELECT currval('ordersq');";
	BaseQ::setQuery(customQuery,"");

	temst=BaseQ::getResultString();

	return temst;
}
void OrderQuery::addToOrder(string orderNumber, string menuItemNum, string orderArrayPostion){

	customQuery="";
	customQuery="UPDATE customerbill SET customer_order["+orderArrayPostion+"]="+menuItemNum+" WHERE orderid='"+orderNumber+"'";
	BaseQ::setQuery(customQuery,"");
}
void OrderQuery::itemQuantity(string orderNumber, string numOfItem, string orderArrayPostion){
	customQuery="";
	customQuery="UPDATE customerbill SET item_total["+orderArrayPostion+"]="+numOfItem+" WHERE orderid='"+orderNumber+"'";
	BaseQ::setQuery(customQuery,"");
}
void OrderQuery::initializeOrder(string employeeID, string orderID){
	customQuery="";

	customQuery="UPDATE orders SET user_id="+employeeID+", status='Pending' WHERE orderid='"+orderID+"'";
	BaseQ::setQuery(customQuery,"");

}
void OrderQuery::updateStatus(string orderID, string status){
	customQuery="";
	customQuery="SELECT \"updateOrderStatus\"('"+orderID+"','"+status+"')";
	BaseQ::setQuery(customQuery,"");
}
void OrderQuery::calcuateBillTotal(string orderID){
	customQuery="";
	customQuery="SELECT \"calBill\"(\'"+orderID+"\')";
	BaseQ::setQuery(customQuery,"");
}
string OrderQuery::displayBillTotal(string orderID){
	customQuery="";
	string temp;

	customQuery="SELECT \"getBillTotal\"('"+orderID+"')";
	BaseQ::setQuery(customQuery,"");
	temp = BaseQ::getResultString();

	return temp;
}
void OrderQuery::displayPendingOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display Pending OrderID
	customQuery="";
	customQuery="SELECT orderid FROM orders WHERE status='Pending' AND user_id='"+employeeID+"'";
	BaseQ::setQuery(customQuery,"orderid");
	BaseQ::display(ss, stream);
}
void  OrderQuery::displayOpenOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display open OrderID
	customQuery="";
	customQuery="SELECT orderid FROM orders WHERE status='open' AND user_id='"+employeeID+"'";
	BaseQ::setQuery(customQuery,"orderid");
	BaseQ::display(ss, stream);
}
void  OrderQuery::displayClosedOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display CLosed OrderID
	customQuery="";
	customQuery="SELECT orderid FROM orders WHERE status='closed' AND user_id='"+employeeID+"'";
	BaseQ::setQuery(customQuery,"orderid");
	BaseQ::display(ss, stream);

}
void OrderQuery::displayRTSOrdersWaiter(string employeeID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display RTS OrderID
	customQuery="";
	customQuery="SELECT orderid FROM orders WHERE status='RTS' AND user_id='"+employeeID+"'";
	BaseQ::setQuery(customQuery,"orderid");
	BaseQ::display(ss, stream);
}
void OrderQuery::displayOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display EmployeeID, openOrderID
	customQuery="";
	customQuery="SELECT user_id,orderid FROM orders WHERE status='open'";
	BaseQ::setQueryMulti(customQuery, "user_id", "orderid");
	BaseQ::displayMulti(ss, stream);

}
void OrderQuery::displayRTSOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	//display EmployeeID, RTS_Order
	customQuery="";
	customQuery="SELECT user_id, orderid FROM orders WHERE status='RTS'";
	BaseQ::setQueryMulti(customQuery, "user_id", "orderid");
	BaseQ::displayMulti(ss, stream);
}
void OrderQuery::displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	//display EmployeeID, Pending_Order
	customQuery="";
	customQuery="SELECT user_id, orderid FROM orders WHERE status='Pending'";
	BaseQ::setQueryMulti(customQuery, "user_id", "orderid");
	BaseQ::displayMulti(ss, stream);
}
void OrderQuery::displayClosedOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	//display EmployeeID, closed_Order
	customQuery="";
	customQuery="SELECT user_id, orderid FROM orders WHERE status='closed'";
	BaseQ::setQueryMulti(customQuery, "user_id", "orderid");
	BaseQ::displayMulti(ss, stream);

}


