#ifndef USER_H
#define USER_H

//#include <string>
#include "UserQuery.h"


//using namespace std;

class User{
public:
	User();
	User(string first, string last, string password, string userRole);
	string getID(string first, string last);
	string getIDUsingUsername(string username);
	bool taskPermission(string id, string roleID);
	string getUsername(string first, string last);
	void displayUsersLogOntoSystem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	UserQuery query;
	string myID;

};







#endif