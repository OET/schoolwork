#include <iostream>
#include <string>
#include "SessionQuery.h"

using namespace std;

bool SessionQuery::authenticate(string username, string password){

	bool result(true);
	string str("");
	customQuery="";

	customQuery ="SELECT \"authen\"('"+username+"','"+password+"\')";
	BaseQ::setQuery(customQuery,"");
	str = BaseQ::getResultString();

	if(str=="t"){
		return true;
	}else{
		return false;
	}

}

//actve=true; onduty=true
void SessionQuery::login(string username){
	bool result(true);
	string str("");
	customQuery="";

	customQuery ="SELECT \"existSession\"('"+username+"')";
	BaseQ::setQuery(customQuery,"");
	str = BaseQ::getResultString();

	if(str=="t"){
		customQuery = "UPDATE session SET active=true, onduty=true WHERE uname='"+username+"'";
		BaseQ::setQuery(customQuery,"");

	}else{
		customQuery ="SELECT \"new_session\"('"+username+"')";
		BaseQ::setQuery(customQuery,"");
	}

}

//actve=false; onduty=true
void SessionQuery::logout(string username){
	customQuery = "UPDATE session SET active=false, onduty=true WHERE uname='"+username+"'";
	BaseQ::setQuery(customQuery,"");
}

//actve=false; onduty=false
void SessionQuery::exit(string username){
	customQuery = "UPDATE session SET active=false, onduty=false WHERE uname='"+username+"'";
	BaseQ::setQuery(customQuery,"");
}

int SessionQuery::getUserRole(string username){
	int result(0);
	string tmp;

	customQuery ="SELECT usercategoryid FROM employee WHERE username='"+username+"'";
	BaseQ::setQuery(customQuery,"");
    result = BaseQ::getResult<int>();

    //cout << "result from sessionquery: "<<result<<endl;
	return result;
}
