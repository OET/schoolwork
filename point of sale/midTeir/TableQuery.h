#ifndef TABLEQUERY_H
#define TABLEQUERY_H

#include <string>
#include "BaseQ.h"

using namespace std;

class Waiter;

class TableQuery: public BaseQ{
public:
	//create ID in db as you assign
	void assignID();
	//assign table with user prompt
	void idAssignment();
	void addTable(int tableNum);
	void assignTable(string waiterID, string tableID);
	string getID();
	void deactivateTable(string idTable);
	bool tableAssignedCheck(string idTable);

private:
	string query;
	string tableID;
};

#endif