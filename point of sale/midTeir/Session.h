#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <boost/asio.hpp>
#include <boost/tokenizer.hpp>
#include "SessionQuery.h"
#include "Waiter.h"
#include "Manager.h"
//#include "Owner.h"
#include "Admin.h"
#include "Kitchen.h"


using namespace boost;
using namespace std;
using namespace boost::asio;

class Session{

public:
	Session();
	Session(string username, string password,boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	bool checkUsername_Password();
	bool checkUname_PW(string username, string password);
	void login();
	void logout();
	void exit();
	void userRole();
	void operator()();
	int getUserRole();

private:

	string uname;
	string pw;
	string response;
	int roleID;
	int menuChoice;
	SessionQuery sq;
	bool sessionEnabled;
	boost::shared_ptr<stringstream> ssLocal;
	boost::shared_ptr<ip::tcp::iostream> streamLocal;
	
	struct SessionToken{
		string userName;
		string password;
	

		void operator()(string &packet){
			escaped_list_separator<char> esc('\\',' ','\"');
			tokenizer<escaped_list_separator<char> > tok(packet, esc);
			tokenizer<escaped_list_separator<char> >::iterator tok_iter;
			
			for(tok_iter=tok.begin(); tok_iter != tok.end(); ){

				userName = *tok_iter;
				++tok_iter;
				password = *tok_iter;
				++tok_iter;
			}
		}//operator()
		
	}token;
};

#endif