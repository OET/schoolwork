#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

Table::Table(){
}
Table::Table(string tableID){
	myID=tableID;
}
void Table::createTable(){
	unsigned tableNum(0);

	cout<<"How many tables to create? ";
	cin>>tableNum;

	tableQuery.addTable(tableNum);
}
string Table::getID(){
	return myID;
}
void Table::assignWaiterToTable(string waiterNumber){
	char answer;

	if(tableQuery.tableAssignedCheck(myID) == true){
		cout<<"WARNING: Table is already assigned, replace previous assignment? [y] OR [n]: ";
		cin >> answer;

		if(answer== 'y' || answer== 'Y'){
			tableQuery.assignTable(waiterNumber, myID);
			waiterID=waiterNumber;
		}else{
			cout <<"No table assigned."<<endl;
		}

	}else{
		tableQuery.assignTable(waiterNumber, myID);
		waiterID=waiterNumber;
	}
}
string Table::myWaiter(){
	return waiterID;
}
void Table::setTableBill(){
//	billForTable.newBillForTable(waiterID, myID);
}
void Table::calulateTableBill(){
	billForTable.calculateBillTotal();
	tableQuery.deactivateTable(myID);
}