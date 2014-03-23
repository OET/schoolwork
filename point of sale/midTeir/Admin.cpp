#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin(){}
Admin::Admin(string userName):uname(userName){}
Admin::Admin(string first, string last, string password){
	User::User(first,last,password, "6");
	ID = User::getID(first, last);
}
string Admin::getID(){
	return ID;
}
void Admin::addNewUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string fName(""), lName(""), password(""), catID(""), username("");

	(*ss)<<"The following prompts will add a new employee "<<endl;
	(*ss)<<"First name: "<<endl;
	(*stream) << ss->str();
	(*stream) >> fName;

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Last name: "<<endl;
	(*stream) << ss->str();
	(*stream) >> lName;

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Password: "<<endl;
	(*stream) << ss->str();
	(*stream) >> password;

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Work Category ID: "<<endl;
	(*stream) << ss->str();
	(*stream) >> catID;

	User::User(fName,lName,password, catID);
	username = User::getUsername(fName, lName);

	cout<<"pass the User function"<<endl;

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<fName<<" "<<lName<<" username is: "<<username<<endl;
	(*stream) << ss->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());
}
void Admin::generateEmployeeID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string rangeBeg;

	(*ss)<<"**************Generate Employee ID***************"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"The following will set the initial value for Table ID: "<<endl;
	(*ss)<<"Enter starting value for ID: ";
	(*stream) >> rangeBeg;
	(*stream) << (ss)->str();
	adminquery.genTableID(rangeBeg);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Setup complete. "<<endl;
	(*stream) << (ss)->str();

	adminquery.genEmployID(rangeBeg);


	 (*stream).clear();
     ss->str(string());
}
void Admin::generateTableID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string rangeBeg;

	(*ss)<<"**************Generate Table ID***************"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"The following will set the initial value for Table ID: "<<endl;
	(*ss)<<"Enter starting value for ID: ";
	(*stream) >> rangeBeg;
	(*stream) << (ss)->str();
	adminquery.genTableID(rangeBeg);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Setup complete. "<<endl;
	(*stream) << (ss)->str();


	 (*stream).clear();
     ss->str(string());

}
void Admin::generateOrderID(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	string rangeBeg;

	(*ss)<<"**************Generate Order ID***************"<<endl;
	(*ss)<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"The following will set the initial value for Order ID"<<endl;
	(*ss)<<"Enter starting value for ID: ";
	(*stream) >> rangeBeg;
	(*stream) << (ss)->str();
	adminquery.genOrderID(rangeBeg);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"Setup complete. "<<endl;
	(*stream) << (ss)->str();


	 (*stream).clear();
     ss->str(string());
}
void Admin::activateUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	string id;

	displayEmployeeList(ss,stream);

	(*ss)<<"Enter Employee ID to activate: "<<endl;
	(*stream) >> id;
	(*stream) << (ss)->str();
	adminquery.activateUserAccount(id);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"User ID "<< id<<" has not been activated."<<endl;
	(*stream) << (ss)->str();

	 (*stream).clear();
     ss->str(string());
}
void Admin::deactivateUser(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
		string id;

	displayEmployeeList(ss,stream);

	 (*stream).clear();
     ss->str(string());


	(*ss)<<"Enter Employee ID to deactivate: "<<endl;
	(*stream) << (ss)->str();
	(*stream) >> id;
	adminquery.deactivateUserAccount(id);

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	(*ss)<<"User ID "<< id<<" has been deactivated."<<endl;
	(*stream) << (ss)->str();
}
void Admin::displayEmployeeList(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	(*ss)<<"**************Employee Listing***************"<<endl;
	(*stream) << (ss)->str();

	(*stream).clear();
	(*stream).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ss->str(std::string());

	adminquery.displayEmployeeList(ss,stream);

	(*ss)<<"********************************************"<<endl;
	(*stream) << (ss)->str();
}
