#ifndef APPSERVER_H
#define APPSERVER_H

#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include "Session.h"


class AppServer{

public:

	AppServer();
	AppServer(int port);
	void operator()();


private:
	string ID;
	string uname;
	string pw;
	boost::shared_ptr<Session> session;
	int portLocal;
	string clientPacket;
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