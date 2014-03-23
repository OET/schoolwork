#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include "Session.h"
#include "Waiter.h"
#include "Manager.h"
//#include "Owner.h"
#include "Admin.h"

using namespace boost;
using namespace std;
using namespace boost::asio;

Session::Session(){}
Session::Session(string username, string password,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream):uname(username),pw(password),ssLocal(ss),streamLocal(stream){
	sessionEnabled=true;
	cout<<"In contructor"<<endl;
	response="";
}
bool Session::checkUsername_Password(){
	bool authResult;
	authResult = sq.authenticate(uname, pw);
	cout<<"authResult: "<<authResult<<endl;

	if(authResult){
		 userRole();
		return true;
	}else{
		return false;
	}
}
void  Session::login(){
	sq.login(uname);
}
void  Session::logout(){
	sq.logout(uname);
}
void  Session::exit(){
	sq.exit(uname);
}
void   Session::userRole(){
	roleID = sq.getUserRole(uname);
	cout <<"Username: "<<uname<<endl;
	cout <<"RoleID in userRole: "<<roleID<<endl;
}
int   Session::getUserRole(){
	return roleID;
}

void Session::operator()(){
	cout <<"uname: "<<uname<<endl;
	cout <<"password: "<<pw<<endl;

		while(sessionEnabled){

			if(checkUsername_Password()){//authentication check
cout <<"Role ID: "<<roleID<<endl;
				//user role choice
				switch(roleID){

					//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^waiter session
				case 1: //waiter
					{
						cout<<"In Waiter Menu()"<<endl;
						bool waiterSession(true);
						boost::shared_ptr<Waiter> waiter(new Waiter(uname));

						do{

                            (*streamLocal).clear();
                            ssLocal->str(string());

							(*streamLocal) >> response;
							menuChoice = atoi(response.c_str());

							switch(menuChoice){

							case 0:

								waiter->newOrder(ssLocal,streamLocal);

								break;

							case 1:
								waiter->listAllOrderStatus(ssLocal,streamLocal);

								break;

							case 2:

                                waiter->displayPendingOrders(ssLocal,streamLocal);
								break;

							case 3:
								waiter->calculateTotal(ssLocal,streamLocal);

								break;

							case 4:
								waiter->calculateTotalEnterOrderID(ssLocal,streamLocal);

								break;

							case 5:	//logout

								logout();
								sessionEnabled = false;
								waiterSession = false;

								break;

							case 6: //exit
								exit();
								sessionEnabled = false;
								waiterSession = false;

								break;
							}//switch
						}while(waiterSession==true);
					}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^manager session
				case 3: //manager
					{
						cout<<"In Manager Menu()"<<endl;
						bool managerSession(true);
						boost::shared_ptr<Manager> manager(new Manager(uname));

						do{

							(*streamLocal) >> response;
							menuChoice = atoi(response.c_str());

							cout <<"response: "+response<<endl;

							switch(menuChoice){


							case 0:	//Employee Login
								manager->displayUsersLogin(ssLocal,streamLocal);

								break;

							case 1: //Open Orders
								manager->displayOpenorders(ssLocal,streamLocal);

								break;

							case 2: //RTS orders
								manager->displayRTSorders(ssLocal,streamLocal);

								break;

							case 3: //Pending Orders
								manager->displayPendingorders(ssLocal,streamLocal);

								break;

							case 4: //Closed Orders
								manager->displayClosedorders(ssLocal,streamLocal);

								break;

							case 5: //Items on Menu
								manager->displayMenuItems(ssLocal,streamLocal);

								break;

							case 6: //Add to Menu()
								manager->addToMenu(ssLocal,streamLocal);

								break;

							case 7: //Deactiviate Menu item()
								manager->deactivateMenuItem(ssLocal,streamLocal);

								break;

							case 8: //Activate Menu item()
								manager->displayPendingorders(ssLocal,streamLocal);

								break;


							case 9:	//logout
								logout();
								sessionEnabled = false;
								managerSession = false;

								break;

							case 10: //exit
								exit();
								sessionEnabled = false;
								managerSession = false;

								break;
							}//switch

						}while(managerSession==true);
						break;
					}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^kitchen
				case 2: //kitchen staff
					{
						cout<<"In Kitchen Menu()"<<endl;
						bool kitchenSession(true);
						boost::shared_ptr<Kitchen> kitchen(new Kitchen(uname));

						do{

							(*streamLocal) >> response;
							menuChoice = atoi(response.c_str());


							switch(menuChoice){

							case 0:

								kitchen->updateOrder(ssLocal,streamLocal);

								break;

							case 1:
								kitchen->displayPendingOrders(ssLocal,streamLocal);

								break;

							case 2:
								kitchen->displayOrder(ssLocal,streamLocal);


								break;

							case 3:	//logout

								logout();
								sessionEnabled = false;
								kitchenSession = false;

								break;

							case 4: //exit
								exit();
								sessionEnabled = false;
								kitchenSession = false;
							}

						}while(kitchenSession==true);//TS
						break;

					}
//***************************************************************************************Admin
				case 6: //Admin
					{
						cout<<"In Admin Menu()"<<endl;
						bool adminSession(true);

							boost::shared_ptr<Admin> admin(new Admin(uname));
						do{
							(*streamLocal) >> response;
							menuChoice = atoi(response.c_str());

							switch(menuChoice){

							case 0: //new user()
								admin->addNewUser(ssLocal,streamLocal);

								break;

							case 1:	//Employee Login
								admin->displayEmployeeList(ssLocal,streamLocal);

								break;

							case 2: //Disable User Account
								admin->deactivateUser(ssLocal,streamLocal);

								break;

							case 3: //Enable User Account
								admin->activateUser(ssLocal,streamLocal);

								break;

							case 4:	//logout

								logout();
								sessionEnabled = false;
								adminSession = false;

								break;

							case 5: //exit
								exit();
								sessionEnabled = false;
								adminSession = false;
								break;
							}

						}while(adminSession==true);


						break;
					}
				default:
					(*streamLocal)<<"Error: Unknown command"<<endl;
				}

			}else{
				(*ssLocal)<<"ERROR: Username / Password Unknown"<<endl;
				(*streamLocal)<<ssLocal->str()<<endl;
			}//username_pw check switch
		}//while

}
bool Session::checkUname_PW(string username, string password){
	/*
	bool authResult;
	//authResult = sq.authenticate(username, password);

	if(authResult){
		//roleID = sq.getUserRole(username);
		// userRole();
		return true;
	}else{
		return false;
	}
	*/
}
