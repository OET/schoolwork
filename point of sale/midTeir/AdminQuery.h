#ifndef ADMINQUERY_H
#define ADMINQUERY_H


#include <string>
#include "BaseQ.h"
#include "User.h"
#include "Table.h"

class AdminQuery: public BaseQ{
public:
	void displayResults();
	void activateUserAccount(string id);
	void deactivateUserAccount(string id);
	void genEmployID(string rangeBeg);
	void genTableID(string rangeBeg);
	void genOrderID(string rangeBeg);
	void displayEmployeeList(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	BaseQ bq;
	string customQuery;	
	string rangeBeg;
	string query;
	User newUser;
	Table table;

};


#endif