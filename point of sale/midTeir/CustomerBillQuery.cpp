#include <iostream>
#include <string>
#include "CustomerBillQuery.h"

using namespace std;

void CustomerBillQuery::newBill(string orderID, string tableID,  string waiterID){
	customQuery="INSERT INTO customerbill(orderid, tableid, employeeid) VALUES('"+orderID+"','"+tableID+"','"+waiterID+"')";
	BaseQ::setQuery(customQuery,"");	
}




