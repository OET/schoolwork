#ifndef MENUQUERY_H
#define MENUQUERY_H

#include <string>
#include "BaseQ.h"

using namespace std;

class MenuQuery: public BaseQ{
public:
	void searchMenu(string item);
	void displayMenuCategory(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayCategoryItems(string category,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayAllItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void activateItem(string itemNumber);
	void displayActiveMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayInactiveMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void deactivateItem(string itemNumber);
	string getMenuCategory(string categoryID);
	string getItemPrice(string itemID);
	bool existInMenu(string itemID);
	bool existInMenuCategory(string itemID);
	void enterMenuItems(string food, string price, string category);

private:
	string customQuery;	
};
#endif