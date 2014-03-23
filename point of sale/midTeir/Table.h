#ifndef TABLE_H
#define TABLE_H


#include <string>
#include "CustomerBill.h"
#include "TableQuery.h"

using namespace std;

class Table{

public:
	Table();
	Table(string tableID);
	void createTable();
	string getID();
	void assignWaiterToTable(string waiterID);
	string myWaiter();
	void setTableBill();
	void calulateTableBill();

private:
	string myID;
	string waiterID;
	TableQuery tableQuery;
	CustomerBill billForTable;
};
#endif
