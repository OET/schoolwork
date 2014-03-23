#ifndef BASEQ_H
#define BASEQ_H

#include <string>
#include "DBconnect.h"
#include <sstream>

using namespace std;

class BaseQ{
public:
	BaseQ();
	BaseQ(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream); //TS
	void updateActiveField(string idColumn,  string table, int ID);

	//non human id retrival
	int assignID(string idColWanted, string table);
	void display();
	//void displayMulti();
	void display(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayMulti(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayMultiThree(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void displayMultiFive(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream);
	void setQuery(string query, string column);
	void setQueryMulti(string query, string column, string column2);
	void setQueryThree(string query, string column, string column2, string column3);
	void setQueryFive(string query, string column, string column2, string column3, string column4, string column5);
	template<class T>
	T getResult();
	string getResultString();
	int getMaxID(string table, string column);
	int getMaxEmployeeID(string table, string column);
	bool isTableEmpty(string table, string column);

private:
	DBconnect dbConnect;
	boost::shared_ptr<ip::tcp::iostream> streamTS;
	boost::shared_ptr<stringstream> ssTS;
};

#endif
