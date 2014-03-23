#include "AppServer.h"
#include <boost/asio.hpp>
//#include <boost/thread.hpp>
#include "Session.h"
#include <iostream>


using namespace boost;
using namespace std;
using namespace boost::asio;

AppServer::AppServer(){}
AppServer::AppServer(int port):portLocal(port){}

void AppServer::operator()(){
	cout <<"In Appserver()"<<endl;

	boost::shared_ptr<ip::tcp::iostream> stream(new ip::tcp::iostream());
	boost::shared_ptr<stringstream> ss(new stringstream());
	io_service ios;
	ip::tcp::endpoint endPoint(ip::tcp::v4(), portLocal);
	ip::tcp::acceptor acceptor(ios, endPoint);
	acceptor.accept(*stream->rdbuf());
	getline((*stream),clientPacket);

	if(clientPacket.length()>0){
		token(clientPacket); //tokenizer
		uname=token.userName;
		pw=token.password;

		Session session(uname,pw,ss,stream);
		session();

	}else{
		(*ss)<<"error Network";
		(*stream)<<ss->str()<<endl;
	}//string length


}
