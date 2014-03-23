#ifndef SESSIONQUERY_H
#define SESSIONQUERY_H

#include <string>
#include "BaseQ.h"

using namespace std;

class SessionQuery: public BaseQ{
public:
	int getUserRole(string username);

	//check username & password
	bool authenticate(string username, string password);
	
	//actve=true; onduty=true
	void login(string username); 

	//actve=false; onduty=true
	void logout(string username);

	//actve=false; onduty=false
	void exit(string username);


private:
	string customQuery;	
	string employeeID;//temp to be deleteed laters
};

#endif