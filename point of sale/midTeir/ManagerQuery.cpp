#include <iostream>
#include <string>
#include "ManagerQuery.h"


using namespace std;


void ManagerQuery::activateUserAccount(string userID){
	
	customQuery="UPDATE employee SET isactive=true WHERE employeeid='"+userID+"'";
	baseQuery.setQuery(customQuery,"");
}
void ManagerQuery::deactivateUserAccount(string userID){

	customQuery="UPDATE employee SET isactive=false WHERE employeeid='"+userID+"'";
	baseQuery.setQuery(customQuery,"");
}
void ManagerQuery::genMenuItemID(){

	bool moreCategories(true), choiceCorrect(true);
	char choice;

	cout<<"The following will setup menu categories and their respective ID"<<endl;

	while(moreCategories){

		cout<<"Enter Category name:";
		cin>>catList.name;
		cout<<endl;

		cout<<"Enter ID number for "<<catList.name<<":";
		cin>>catList.ID;
		cout<<endl;

		while(choiceCorrect){

			cout<<"Confirm? (y) or (n): ";
			cin>>choice;

			if(choice=='y' || choice=='Y'){


				customQuery="INSERT INTO menu (itemid,category,isactive) VALUES('"+catList.ID+"','"+catList.name+"',false)";
				baseQuery.setQuery(customQuery,"");

				cout<<endl;

				cout<<"More Categories? (y) or (n): ";
				cin>>choice;

				if(choice=='y' || choice=='Y'){

					choiceCorrect=false;

				}else if(choice=='n' || choice=='N'){

					choiceCorrect=false;
					moreCategories=false;

				}else{
					cout<<"Error: Entry not recognized"<<endl;
				}

			}else if(choice=='n' || choice=='N'){

				choiceCorrect=false;

				catList.name="";
				catList.ID="";

			}else{
				cout<<"Error: Entry not recognized"<<endl;
			}
		}//inner while
		choiceCorrect=true;
	}//parent while


}

