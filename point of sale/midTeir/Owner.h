#ifndef OWNER_H
#define OWNER_H

#include <string>
#include "User.h"
#include "OwnerQuery.h"

using namespace std;


class Owner: public User{

public:

	Owner();
	Owner(string first, string last, string password);
	string getID();


private:
	string ID;
};

#endif