#ifndef MANAGERQUERY_H
#define MANAGERQUERY_H


#include <string>
#include "BaseQ.h"

class ManagerQuery: public BaseQ{
public:
	void displayResults();
	void activateUserAccount(string id);
	void deactivateUserAccount(string id);
	void genMenuItemID();
	

private:
	BaseQ baseQuery;
	string customQuery;	
	struct Category{
		string ID;
		string name;
	}catList;

};


#endif