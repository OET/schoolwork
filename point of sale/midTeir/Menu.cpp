#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::displayCategory(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	(*stream)<<"**************Menu Category***************"<<endl;
	menuQuery.displayMenuCategory(ss, stream);

}
void Menu::displayCategoryItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string temp(""), userEntry("");
	int categoryID(0), pos(0);
	bool enteredDataNotCleared(true), do_not_display_items(true);
	categoryNumber="";

	while(do_not_display_items){

		while (enteredDataNotCleared) {
			(*stream)<<"Select Menu category number to list:"<<endl;
			(*stream)>> categoryNumber;

			pos=categoryNumber.find_first_not_of("0123456789");
			if( pos == string::npos){
				if(menuQuery.existInMenuCategory(categoryNumber) == true){

					temp = menuQuery.getMenuCategory(categoryNumber);
					(*stream)<<"---------------------Items listed under "+temp+"--------------"<<endl;

					menuQuery.displayCategoryItems(temp, ss, stream);

					(*stream)<<"---------------------------------------------------------------"<<endl;

					do_not_display_items=false;
					enteredDataNotCleared=false;
				}
			}else{
				(*stream).clear();
				(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				(*stream)<<"Unrecognized entry number: Try Again"<<endl;
				(*stream)<<endl;

			}
		}

	}//parent while
    (*stream).clear();
    ss->str(string());
}
bool Menu::isItemInMenu(string itemID){
	bool result;
	result = menuQuery.existInMenu(itemID);
	return result;
}
bool Menu::isCategoryNumInMenu(string itemID){
	bool result;
	result = menuQuery.existInMenuCategory(itemID);
	return result;
}
void Menu::addMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string food, price, category;
	bool stillEntering(true), dataEnteredCleared(true);
	int pos(0);
	char choice;

	(*stream) <<"The following will add items to the menu"<<endl;

	while(stillEntering){

		displayCategory(ss,stream);

		//cout <<"return from displayCatergory: "<<endl;
        //cout <<"bool result to enter menu: "<< dataEnteredCleared <<endl;
		while (dataEnteredCleared) {

			(*stream)<<"Enter Category Number: "<<endl;
			(*stream)>>category;

			pos=category.find_first_not_of("0123456789");
			cout << "pos" <<pos<<endl;
			if( pos == string::npos){

				if((isCategoryNumInMenu(category)) == true){
					dataEnteredCleared=false;
				}
			}else{
				(*stream).clear();
				(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				(*stream)<<"ERROR: Unknown entry, try again "<<endl;
				//(*stream)<<endl;
			}
		}//inner while loop
        //cout <<"OutSide of loop!"<<endl;
		(*stream).clear();
		(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		(*stream)<<"Enter menu item name: "<<endl;
		getline((*stream),food);

		(*stream)<<"Enter price: "<<endl;
		(*stream)>>price;

		menuQuery.enterMenuItems(food, price, category);

		(*stream)<<"Add more items to menu? (y) or (n): "<<endl;
		(*stream)>>choice;

		if(choice=='y' || choice=='Y'){
			category="";
			food="";
			price="";
			dataEnteredCleared=true;
            (*stream).clear();
            ss->str(string());

		}else if(choice=='n' || choice=='N'){

			stillEntering=false;
			(*stream)<<"Menu updated."<<endl;
		}

	}//parent while

	dataEnteredCleared=false;
	(*stream).clear();
    ss->str(string());
}
void Menu::activateItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string itemNumber("");

	(*ss)<<"**************Non-active Items***************"<<endl;
	(*stream) << (ss)->str();


	menuQuery.displayInactiveMenuItems(ss, stream);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Enter item ID to activate"<<endl;
	(*stream) << ss->str();
	(*stream) >> itemNumber;

	menuQuery.activateItem(itemNumber);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Item "<< itemNumber << "Has been activated."<<endl;
	(*stream) << ss->str();

    (*stream).clear();
    ss->str(string());
}
void Menu::deactivateItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string itemNumber("");
	(*ss)<<"**************Active Items***************"<<endl;
	(*stream) << (ss)->str();
	menuQuery.displayActiveMenuItems(ss, stream);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Enter item ID to deactivate"<<endl;
	(*stream) << ss->str();
	(*stream) >> itemNumber;

	menuQuery.deactivateItem(itemNumber);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Item "<< itemNumber << "Has been deactivated."<<endl;
	(*stream) << ss->str();

    (*stream).clear();
    ss->str(string());
}
void Menu::listAllItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	(*ss)<<"**************Availalbe Menu Items***************"<<endl;
	(*stream) << (ss)->str();
	menuQuery.displayAllItems(ss, stream);
    (*stream).clear();
    ss->str(string());

}
void Menu::listMenuItems(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	(*ss)<<"**************Current Menu***************"<<endl;
	(*stream) << (ss)->str();
	menuQuery.displayActiveMenuItems(ss,stream);
    (*stream).clear();
    ss->str(string());

}
