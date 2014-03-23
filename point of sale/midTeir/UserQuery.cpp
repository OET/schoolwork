#include <iostream>
#include <string>
#include "UserQuery.h"


using namespace std;

  UserQuery::UserQuery(){}

//********************Temp function for troubleshooting
void UserQuery::setID(string id){
	employeeID = id;
}
//functions to return ID based on name
string UserQuery::getEmployeeID(string first, string last){

	string ID;

	customQuery="SELECT employeeid FROM employee WHERE fname='" +first+ "' AND lname='" +last+ "'";

	baseQuery.setQuery(customQuery, "employeeid");
	ID = baseQuery.getResultString();

	return ID;
}

//assign new user an ID and add user to db with account status being being set to active
void UserQuery::assignID(string first, string last,string password, string userRole){
	string temp;

    customQuery="INSERT INTO employee (employeeid, fname, lname, isactive, password ,usercategoryid) VALUES (nextval('employsq'),'"+first+"','"+last+"', true,'"+password+"','"+userRole+"'); SELECT currval('employsq');";

	baseQuery.setQuery(customQuery,"");
	temp= baseQuery.getResultString();

	customQuery="SELECT \"makeUsername\"('"+temp+"')";
	baseQuery.setQuery(customQuery,"");
}

//verifies whether user has permission for certain task
bool UserQuery::verifyPermission(string id, string roleID){
	string str("");

	customQuery="SELECT \"verifyPerm\"('"+id+"','"+roleID+"')";
	baseQuery.setQuery(customQuery,"");
	str = baseQuery.getResultString();

	if(str=="t"){
		return true;
	}

	return false;
}

//returns the assigned ID for the passed in user role
int UserQuery::getUserRoleID(string userRole){



}

//returns the assigned ID for passed in username
string UserQuery::getIDFromUsername(string username){

	string temp("");
	customQuery="SELECT employeeid FROM employee WHERE username='"+username+"'";
	baseQuery.setQuery(customQuery,"");
	temp = baseQuery.getResultString();

	return temp;
}

string UserQuery::getUsername(string fname, string lname){
	string temp("");
	customQuery="SELECT username FROM employee WHERE fname='"+fname+"'AND lname='"+lname+"'";
	baseQuery.setQuery(customQuery,"");
	temp = baseQuery.getResultString();

	return temp;
}

void UserQuery::displayEmployeesLogin(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	customQuery="SELECT uname FROM session WHERE onduty=TRUE";
	baseQuery.setQuery(customQuery,"uname");
	baseQuery.display(ss, stream);
}
