#include <iostream>
#include <string>
#include "Kitchen.h"

Kitchen::Kitchen(){}
Kitchen::Kitchen(string uerName):uname(uerName){}
Kitchen::Kitchen(string first, string last, string password){
	 User::User(first,last,password, "2");
	 ID = User::getID(first, last);
}
string Kitchen::getID(){	
	return ID;
}
void Kitchen::displayPendingOrders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	order.showPendingOrder(ss, stream);
}

// display content
void Kitchen::displayOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream ){
	string orderid;
	
	//*ss << "Enter order id to list: "<<endl;
	//(*stream) << ss->str();

	*ss << "Enter order id to list: "<<endl;
	*ss  >> orderid;

	(*stream) << ss->str();
	cout <<"Order content to list: "<<orderid;
	//order.updateOrderStatus("RTS",orderid);
}

void Kitchen::updateOrder(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string orderid;

	*ss << "Enter ready to serve order ID: "<<endl;
	(*stream) << ss->str();
	(*stream) >> orderid;
	cout << "order Length" << orderid.length() <<endl;;
	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	order.updateOrderStatus(orderid, "RTS");
	*ss << "Order "<<orderid<<" have been updated"<<endl;
	(*stream) << ss->str();
}