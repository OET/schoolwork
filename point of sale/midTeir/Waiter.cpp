#include <iostream>
#include <string>
#include "Waiter.h"
#include "Table.h"

using namespace std;
Waiter::Waiter(){}
Waiter::Waiter(string waiterUsername){
	ID = User::getIDUsingUsername(waiterUsername);
}
//Waiter::Waiter(string waiterID){ID = waiterID;}
Waiter::Waiter(string first, string last, string password){
	 User::User(first,last,password, "1");
	 ID = User::getID(first, last);
}
string Waiter::getID(){
	return ID;
}
void Waiter::listAllOrderStatus(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	waiterQuery.displyOrderStatus(ID, ss,stream);
}
/*
void Waiter::displayOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	bill.listOpenOrders(ID, ss, stream);
}*/
void Waiter::displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
    bill.listPendingOrders(ID, ss, stream);
}
void Waiter::newOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	bill.newBillForTable(ID,currentTable.getID(), ss, stream);
}
void Waiter::calculateTotal(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	bill.getBillTotal(ss,stream);
}
//enter which table and which bill
void Waiter::calculateTotalEnterOrderID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	bill.getBillTotalEnterID(ss, stream);
}

