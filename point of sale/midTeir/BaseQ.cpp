#include <iostream>
#include <string>
#include "BaseQ.h"
#include <sstream>


using namespace std;

BaseQ::BaseQ(){}
BaseQ::BaseQ(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream):ssTS(ss), streamTS(stream){}

void BaseQ::updateActiveField(string idColumn,  string table, int ID){
	string query, id;
	id = to_string(ID);

	query = "UPDATE "+table+" SET isactive=true WHERE "+idColumn+"='"+id+"'";

	dbConnect.setQuery(query,"");//second argument left blank on purpose, just a place holder. Not used in base function
}

//non human id retrival
int BaseQ::assignID(string idColWanted, string table){
	string query;
	int ID;

	query ="SELECT '"+idColWanted+"' FROM '"+table+"' WHERE isactive=false";

	dbConnect.setQuery(query,idColWanted);
	ID = BaseQ::getResult<int>();

	return ID;
}
void BaseQ::display(){
	dbConnect.displayResults(ssTS, streamTS);
}
void BaseQ::display(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	dbConnect.displayResults(ss, stream);
}
void BaseQ::displayMulti(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	dbConnect.displayResultsMulti(ss, stream);
}
void BaseQ::displayMultiThree(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	dbConnect.displayResultsThree(ss,stream);
}
void BaseQ::displayMultiFive(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	dbConnect.displayResultsFive(ss,stream);
}
void BaseQ::setQuery(string query, string column){

	dbConnect.setQuery(query, column);
}
void BaseQ::setQueryMulti(string query, string column, string column2){

	dbConnect.setQueryMulti(query, column, column2);
}
void BaseQ::setQueryThree(string query, string column, string column2, string column3){
	dbConnect.setQueryThree(query,column,column2,column3);
}
void BaseQ::setQueryFive(string query, string column, string column2, string column3, string column4, string column5){
	dbConnect.setQueryFive(query, column,column2,column3,column4,column5);
}
template<class T>
T BaseQ::getResult(){
	return dbConnect.getResults<T>();
}
string BaseQ::getResultString(){
	return dbConnect.getResultString();
}
int BaseQ::getMaxID(string table, string column){
	string query="";
	int ID;
	query="SELECT MAX("+column+") FROM \""+table+"\"";

	dbConnect.setQuery(query, column);
	ID=dbConnect.getResults<int>();

	return ID;
}
int BaseQ::getMaxEmployeeID(string table, string column){
	string query="";
	int ID;
	query="SELECT MAX("+column+") FROM \""+table+"\" WHERE isactive=false AND fname=NULL";

	dbConnect.setQuery(query, column);
	ID=dbConnect.getResults<int>();

	return ID;
}
bool BaseQ::isTableEmpty(string table, string column){
	return (dbConnect.isTableEmpty(table,column));
}

