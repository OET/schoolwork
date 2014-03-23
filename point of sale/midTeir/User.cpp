#include <iostream>
#include <string>
#include "User.h"

using namespace std;
User::User(){}

User::User(string first, string last, string password,string userRole){

	query.assignID(first,last,password,userRole);
}
string User::getID(string first, string last){

	myID = query.getEmployeeID(first,last);

	return myID;
}
string User::getIDUsingUsername(string username){
	myID = query.getIDFromUsername(username);
	return myID;
}
bool User::taskPermission(string userID, string roleID){
	bool temp;
	temp = query.verifyPermission(userID, roleID);

	return temp;

}
string User::getUsername(string first, string last){
	string uname("");

	uname = query.getUsername(first, last);
	return uname;

}

void User::displayUsersLogOntoSystem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	query.displayEmployeesLogin(ss,stream);
}



