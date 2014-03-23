#ifndef USERQUERY_H
#define USERQUERY_H

#include <string>
#include "BaseQ.h"

using namespace std;

class UserQuery{
public:
    UserQuery();

	//functions to return ID based on name
	string getEmployeeID(string first, string last);

	//assign ID while creating new numbers
	void assignID(string first, string last, string password, string userRole);

	//returns the assigned ID for the passed in user role
	int getUserRoleID(string userRole);

	//verify permission of user's role
	bool verifyPermission(string id, string roleID);

	//returns the assigned ID for passed in username
	string getIDFromUsername(string username);

	//get username from first last name
	string getUsername(string fname, string lname);


	void displayEmployeesLogin(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);


	//**************Temp For troubleshooting****************
	void setID(string id);


private:
	string customQuery;
	string employeeID;//temp to be deleteed laters
	BaseQ baseQuery;

};

#endif
