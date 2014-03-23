#ifndef DBCONNECT_H
#define DBCONNECT_H

#include "TCPcommunication.h"
#include <string>
#include <pqxx/pqxx>
#include <sstream>

using namespace std;
using namespace pqxx;

class DBconnect{

public:
	DBconnect();
	DBconnect(boost::shared_ptr<ip::tcp::iostream> stream);
	template <class T>
	T getResults();
	string getResultString();

	void displayResults(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayResultsMulti(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayResultsThree(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayResultsFive(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void setQuery(string Customquery, string column);
	void setQueryMulti(string Customquery, string column, string column2);
	void setQueryThree(string Customquery, string column, string column2, string column3);
	void setQueryFive(string Customquery, string column, string column2, string column3, string column4, string column5);
	bool isTableEmpty(string table, string column);

private:
	string connectionInfo;
	string localColumn;
	string localColumn2;
	string localColumn3;
	string localColumn4;
	string localColumn5;
	result r;
	string query;
	connection* d;
	boost::shared_ptr<TCPcommunication> tcpConnect;

};

#endif
