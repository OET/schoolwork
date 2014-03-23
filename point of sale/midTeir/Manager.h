#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "User.h"
#include "ManagerQuery.h"
#include "Menu.h"
#include "Order.h"

using namespace std;


class Manager: public User{

public:

	Manager();
	Manager(string waiterUsername);
	Manager(string first, string last, string password);
	string getID();
	void activateMenuItem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void deactivateMenuItem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void genMenuItemID(string userID);
	void addToMenu(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayUsersLogin(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayOpenorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayRTSorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayPendingorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayClosedorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayMenuItems (boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);

private:
	string ID;
	ManagerQuery query;
	Menu menu;
	Order order;
	string uname;

};

#endif
