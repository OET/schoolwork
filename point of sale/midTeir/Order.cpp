#include <string>
#include <iostream>
#include "Order.h"


using namespace std;

Order::Order(){

}
string Order::getOrderID(string tableID, string waiterID){
	int tempID;

	tempID=orderQuery.getOrderID(tableID, waiterID);
	ID=to_string(tempID);

	return ID;
}
void Order::assignID(){
	ID=orderQuery.assignOrderID();
}
string Order::myID(){
	return ID;
}
void Order::getOrder(string waiterID,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	bool orderNotConfirm(true), choiceCorrect(true), dataEnteredCleared(true);
	char choice;
	unsigned dbArrayposition(1), quantity(0);
	string itemNumber(""), arrayPosition(""), arrayQuantity("");
	int itemNum(0), pos(0);

    assignID();
	orderQuery.initializeOrder(waiterID,ID);


	while(orderNotConfirm){
		(*stream)<<endl;
		(*stream)<<endl;

		menu.displayCategory(ss,stream);
		menu.displayCategoryItems(ss,stream);


		while (dataEnteredCleared) {
			(*stream)<<"Enter ID number of item to add to order? "<<endl;
			(*stream)>> itemNumber;

			pos=itemNumber.find_first_not_of("0123456789");
			if( pos == string::npos){
				if(menu.isItemInMenu(itemNumber) == true){
					dataEnteredCleared=false;
				}
			}else{
				(*stream).clear();
				(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				(*stream)<<"ERROR: Unknown entry, try again "<<endl;
				(*stream)<<endl;
			}
		}


		(*stream)<<"How many items?"<<endl;
		(*stream)>>quantity;

		arrayPosition= to_string(dbArrayposition);
		arrayQuantity= to_string(quantity);

		orderQuery.addToOrder(ID, itemNumber,arrayPosition);
		orderQuery.itemQuantity(ID, arrayQuantity,arrayPosition);

		(*stream)<<"Add more items to order? (y) or (n): "<<endl;
		(*stream)>>choice;

		if(choice=='y' || choice=='Y'){
			dbArrayposition++;
			quantity=0;
			itemNumber="";
			arrayPosition="";
			arrayQuantity="";
			dataEnteredCleared=true;
			//system("cls");


		}else if(choice=='n' || choice=='N'){

			orderQuery.updateStatus(ID, PENDING);
			orderNotConfirm=false;
			(*stream)<<"Order number: "<< ID<<" is now pending."<<endl;
		}

	}//parent while

	dataEnteredCleared=false;
}
void Order::billTotal(){
	orderQuery.calcuateBillTotal(ID);
	cout<<"Bill Total calculation done."<<endl;
}

void Order::billTotalDifferentOrder(string orderID){
	orderQuery.calcuateBillTotal(orderID);

}

string Order::getBillTotal(string orderID){
	return (orderQuery.displayBillTotal(orderID));
}

void Order::updateOrderStatus(string orderID, string status){

	orderQuery.updateStatus(orderID, status);
}

void Order::showOpenOrdersWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Open Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayOpenOrdersWaiter(employeeID, ss, stream);

}
void Order::showRTSOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Ready To Serve Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayRTSOrdersWaiter(employeeID, ss, stream);

}
void Order::showPendingOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){


	(*ss)<<"_______________________Pending Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayPendingOrdersWaiter(employeeID, ss, stream);

}
void Order::showClosedOrderWaiter(string employeeID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Closed Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayClosedOrdersWaiter(employeeID, ss, stream);

}
//****************************************************************************************************************************************
void  Order::showOpenOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Open Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayOpenOrders(ss,stream);

}
void  Order::showRTSOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Ready To Serve Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayRTSOrders(ss,stream);
}
void  Order::showPendingOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Pending Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayPendingOrders(ss,stream);

}
void  Order::showClosedOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"_______________________Closed Orders______________________"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	orderQuery.displayClosedOrders(ss,stream);
}
