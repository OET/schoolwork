#include <iostream>
#include <string>
#include "Owner.h"


Owner::Owner(){}
Owner::Owner(string first, string last, string password){
	User::User(first,last,password, "5");
	ID = User::getID(first, last);
}

string Owner::getID(){	
	return ID;
}