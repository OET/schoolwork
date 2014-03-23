#ifndef TCPCOMMUNICATION_H
#define TCPCOMMUNICATION_H

#include <boost/asio.hpp>
#include <string>

using namespace boost;
using namespace std;
using namespace boost::asio;

class TCPcommunication{

public:
	TCPcommunication();

	void sendToClient(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	string recvFromClient(boost::shared_ptr<ip::tcp::iostream>& stream);

private:

};

#endif
