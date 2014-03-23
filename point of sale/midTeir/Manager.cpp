#include <iostream>
#include <string>
#include "Manager.h"

Manager::Manager(){}
Manager::Manager(string managerUsername): uname (managerUsername){}
Manager::Manager(string first, string last, string password){
	 User::User(first,last,password, "3");
	  ID = User::getID(first, last);
}
string Manager::getID(){
	return ID;
}
void Manager::activateMenuItem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	menu.activateItems(ss,stream);
}
void Manager::deactivateMenuItem(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	menu.deactivateItems(ss,stream);

}
void Manager::genMenuItemID(string foodID){
    query.genMenuItemID();
}
void Manager::addToMenu(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	menu.addMenuItems(ss, stream);
}
void Manager::displayUsersLogin(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	User::displayUsersLogOntoSystem(ss,stream);
}
void Manager::displayRTSorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	order.showRTSOrder(ss,stream);
}
void Manager::displayPendingorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	order.showPendingOrder(ss,stream);
}
void Manager::displayClosedorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	order.showClosedOrder(ss,stream);
}
void Manager::displayOpenorders(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	order.showOpenOrders(ss,stream);
}
void Manager::displayMenuItems (boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	menu.listMenuItems(ss,stream);
}
