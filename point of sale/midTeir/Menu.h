#ifndef MENU_H
#define MENU_H

#include <string>
#include "MenuQuery.h"

using namespace std;

class Menu{
public:
	void displayCategory(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayCategoryItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	bool isItemInMenu(string itemID);
	bool isCategoryNumInMenu(string itemID);
	void addMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void activateItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void deactivateItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void listAllItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void listMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);


private:
	MenuQuery menuQuery;
	string categoryNumber;
};
#endif