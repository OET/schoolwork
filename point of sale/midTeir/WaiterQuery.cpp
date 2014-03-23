#include "WaiterQuery.h"


void WaiterQuery::displayResults(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	BaseQ::display(ss, stream);
}
void WaiterQuery::displyOrderStatus(string waiterID, boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	customQuery ="SELECT orderid,status FROM orders WHERE user_id='"+waiterID+"'";
	BaseQ::setQueryMulti(customQuery,"orderid","status");
	BaseQ::displayMulti(ss, stream);
}