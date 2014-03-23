#include "TCPcommunication.h"
#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using namespace std;
const int PORT = 60000;

TCPcommunication::TCPcommunication(){}


void TCPcommunication::sendToClient(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){	
	//cout <<"Str in sendToClient(): "<<stream.get()<<endl;

	cout<<"To client: "<<ss->str()<<endl;

	(*stream).clear();
	(*stream) << ss->str();
	ss->str(string());	
} 

string TCPcommunication::recvFromClient(boost::shared_ptr<ip::tcp::iostream>& stream){	

	string fromClient;

	(*stream) >> fromClient;
	cout<<"From client: "<<fromClient<<endl;

	return fromClient;
}