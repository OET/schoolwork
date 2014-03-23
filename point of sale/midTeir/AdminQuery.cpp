#include <iostream>
#include <string>
#include "AdminQuery.h"

using namespace std;

void AdminQuery::genEmployID(string rangeBeg){
		query="INSERT INTO employee(employeeid,isactive) VALUES('"+rangeBeg+"',false)";
		bq.setQuery(query,"");
}
void AdminQuery::genTableID(string rangeBeg){

	query="INSERT INTO \"table\" (tableid,isactive) VALUES("+rangeBeg+",false)";
	bq.setQuery(query,"");

	table.createTable();
}
void AdminQuery::genOrderID(string rangeBeg){

		//opendate column in Orders table will be equal to isactive. If set with value, then it has been assigned
		query="INSERT INTO orders (orderid,opendate) VALUES('"+rangeBeg+"',NULL)";
		bq.setQuery(query,"");

}

void  AdminQuery::activateUserAccount(string id){

	//opendate column in Orders table will be equal to isactive. If set with value, then it has been assigned
	query="UPDATE \"employee\" SET isactive=True WHERE employeeid='"+id+"'";
	bq.setQuery(query,"");
}
void  AdminQuery::deactivateUserAccount(string id){

	//opendate column in Orders table will be equal to isactive. If set with value, then it has been assigned
	query="UPDATE \"employee\" SET isactive=False WHERE employeeid='"+id+"'";
	bq.setQuery(query,"");
}

void AdminQuery::displayEmployeeList(boost::shared_ptr<stringstream>& ss, boost::shared_ptr<ip::tcp::iostream>& stream){
	query="SELECT employeeid,fname,lname,username,isactive FROM employee WHERE isactive=True";
	bq.setQueryFive(query,"employeeid","fname","lname","username","isactive");
	bq.displayMultiFive(ss,stream);
}
