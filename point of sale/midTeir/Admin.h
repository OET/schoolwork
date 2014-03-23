#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "User.h"
#include "AdminQuery.h"


using namespace std;


class Admin: public User{

public:

	Admin();
	Admin(string userName);
	Admin(string first, string last, string password);
	string getID();
	void addNewUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void generateEmployeeCategoryID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void generateEmployeeID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void generateTableID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void generateOrderID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void activateUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void deactivateUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayEmployeeList(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	string ID;
	AdminQuery adminquery;
	string uname;
};
#endif