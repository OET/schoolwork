#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include "DBconnect.h"
#include "TCPcommunication.h"
#include <sstream>


using namespace std;
using namespace pqxx;


DBconnect::DBconnect(): connectionInfo("user=t4432 password=ter0@33 dbname=lp009 port=5434 host=localhost"){

}

template <class T>
T DBconnect::getResults(){
	T returnValue;

	result::const_iterator i = r.begin();
	if(!i[0].to(returnValue)){
	    throw runtime_error("ERROR IN getResult()");
	}
	return returnValue;
}
string DBconnect::getResultString(){
	stringstream ss;
	string returnValue;
	ss << (r[0][0]);
	returnValue = ss.str();
	return returnValue;
}
void DBconnect::displayResults(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	for(result::size_type i = 0; i < r.size(); ++i){
		cout << r[i][localColumn] << endl;
		*ss  << r[i][localColumn] << endl;
        (*stream).clear();
        (*stream) << ss->str();
        ss->str(string());
	}
}
void DBconnect::displayResultsMulti(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	for(result::size_type i = 0; i < r.size(); ++i){
		cout << r[i][localColumn]<<", "<< r[i][localColumn2]<<endl;
		*ss  << r[i][localColumn]<<", "<< r[i][localColumn2]<<endl;
        (*stream).clear();
        (*stream) << ss->str();
        ss->str(string());
	}
}
void DBconnect::displayResultsThree(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){

	for(result::size_type i = 0; i < r.size(); ++i){
		cout << r[i][localColumn]<<", "<< r[i][localColumn2]<<", "<< r[i][localColumn3]<<endl;
		*ss  << r[i][localColumn]<<", "<< r[i][localColumn2]<<", "<< r[i][localColumn3]<<endl;
        (*stream).clear();
        (*stream) << ss->str();
        ss->str(string());
	}
}
void DBconnect::displayResultsFive(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	for(result::size_type i = 0; i < r.size(); ++i){
		cout << r[i][localColumn]<<", "<< r[i][localColumn2]<<", "<< r[i][localColumn3]<<", "<< r[i][localColumn4]<<", "<< r[i][localColumn5]<<endl;
		*ss  << r[i][localColumn]<<", "<< r[i][localColumn2]<<", "<< r[i][localColumn3]<<", "<< r[i][localColumn4]<<", "<< r[i][localColumn5]<<endl;

        (*stream).clear();
        (*stream) << ss->str();
        ss->str(string());
	}
}
void DBconnect::setQuery(string Customquery, string column){

	query = Customquery;
	localColumn = column;
	try
	{
		connection c(connectionInfo);
		d = &c;
		work w(*d); //wrapping connection into transaction
		r = w.exec(query);
		w.commit();
	}
	catch(std::exception e)
	{
		cerr << e.what() << endl;
	}
}
void DBconnect::setQueryMulti(string Customquery, string column, string column2){

	query = Customquery;
	localColumn = column;
	localColumn2=column2;
	try
	{
		connection c(connectionInfo);
		d = &c;
		work w(*d); //wrapping connection into transaction
		r = w.exec(query);
		w.commit();
	}
	catch(std::exception e)
	{
		cerr << e.what() << endl;
	}
}
void DBconnect::setQueryThree(string Customquery, string column, string column2, string column3){
	query = Customquery;

	localColumn = column;
	localColumn2=column2;
	localColumn3=column3;

	try
	{
		connection c(connectionInfo);
		d = &c;
		work w(*d); //wrapping connection into transaction
		r = w.exec(query);
		w.commit();
	}
	catch(std::exception e)
	{
		cerr << e.what() << endl;
	}

}
void DBconnect::setQueryFive(string Customquery, string column, string column2, string column3, string column4, string column5){
		query = Customquery;

	localColumn = column;
	localColumn2=column2;
	localColumn3=column3;
	localColumn4=column4;
	localColumn5=column5;

	try
	{
		connection c(connectionInfo);
		d = &c;
		work w(*d); //wrapping connection into transaction
		r = w.exec(query);
		w.commit();
	}
	catch(std::exception e)
	{
		cerr << e.what() << endl;
	}

}
bool DBconnect::isTableEmpty(string table, string column){
	int rowNum;

	// query for number of rows in column
	query="SELECT COUNT("+column+") FROM \""+table+"\"";
	setQuery(query,column);
	rowNum=getResults<int>();

	if(rowNum>0){
		return false;
	}else{
		return true;
	}
}

