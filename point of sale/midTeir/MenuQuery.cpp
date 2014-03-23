#include <string>
#include <iostream>
#include "MenuQuery.h"

using namespace std;


void MenuQuery::searchMenu(string item){}
//display all the categories on the menu
void MenuQuery::displayMenuCategory(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	customQuery ="SELECT category,id FROM menu_cat";
	BaseQ::setQueryMulti(customQuery,"category","id");
	BaseQ::displayMulti(ss, stream);
}
//returns name of menu category by number entered
string MenuQuery::getMenuCategory(string categoryID){
	string temp;
	int num;
	customQuery ="SELECT category FROM menu_cat WHERE id='"+categoryID+"'";
	BaseQ::setQuery(customQuery,"category");
	temp=BaseQ::getResultString();
	return temp;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//display all active items in menu that is in the menuCategory argument
void MenuQuery::displayCategoryItems(string menuCategory,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	customQuery="";
	customQuery ="SELECT short_des,itemid FROM menu WHERE isactive=true AND category='"+menuCategory+"'";
	BaseQ::setQueryMulti(customQuery,"short_des","itemid");
	BaseQ::displayMulti(ss, stream);
}

void  MenuQuery::displayAllItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	customQuery="";
	customQuery ="SELECT short_des,itemid, isactive FROM menu";
	BaseQ::setQueryThree(customQuery,"short_des","itemid","isactive");
	BaseQ::displayMultiThree(ss,stream);
}

void MenuQuery::displayActiveMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	customQuery="";
	customQuery ="SELECT short_des,itemid FROM menu WHERE isactive=true";
	BaseQ::setQueryMulti(customQuery,"short_des","itemid");
	BaseQ::displayMulti(ss, stream);
}
void MenuQuery::displayInactiveMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	customQuery="";
	customQuery ="SELECT short_des,itemid FROM menu WHERE isactive=false";
	BaseQ::setQueryMulti(customQuery,"short_des","itemid");
	BaseQ::displayMulti(ss, stream);

}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void MenuQuery::activateItem(string itemNumber){
	customQuery="";
	customQuery ="UPDATE \"menu\" SET isactive=True WHERE itemid='"+itemNumber+"'";
	BaseQ::setQuery(customQuery,"");
}
void MenuQuery::deactivateItem(string itemNumber){
	customQuery="";
	customQuery ="UPDATE \"menu\" SET isactive=False WHERE itemid='"+itemNumber+"'";
	BaseQ::setQuery(customQuery,"");
}
string MenuQuery::getItemPrice(string itemID){
	string price;
	double tempPrice;

	customQuery="";
	customQuery ="SELECT itemprice FROM menu WHERE itemid='"+itemID+"'";
	BaseQ::setQuery(customQuery,"itemprice");
	tempPrice=BaseQ::getResult<int>();
	price=to_string(tempPrice);

	return price;

}
bool MenuQuery::existInMenu(string itemID)
{
	bool result(true);
	string str("");

	customQuery="";
	customQuery ="SELECT \"existInMenu\"(\'"+itemID+"\')";
	BaseQ::setQuery(customQuery,"");
	str = BaseQ::getResultString();

	if(str=="t"){
		return true;
	}else{
		return false;
	}
}
bool MenuQuery::existInMenuCategory(string itemID)
{
	bool result(true);
	string str("");

	customQuery="";
	customQuery ="SELECT \"existInMenuCat\"(\'"+itemID+"\')";
	BaseQ::setQuery(customQuery,"");
	str = BaseQ::getResultString();

	if(str=="t"){
		return true;
	}else{
		return false;
	}
}
void MenuQuery::enterMenuItems(string food, string price, string category){
	string temp("");
	temp = getMenuCategory(category);
	customQuery="INSERT INTO \"menu\"(\"short_des\",\"itemprice\",\"category\",\"itemid\",\"isactive\") VALUES ('"+food+"',"+price+",'"+temp+"',nextval('menusq'), 'true')";
	BaseQ::setQuery(customQuery,"");
}
