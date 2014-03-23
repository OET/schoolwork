#include <iostream>
#include <string>
#include "TableQuery.h"
#include "Waiter.h"


using namespace std;
//create ID in db with ID column already populated
void TableQuery::assignID(){

	query="INSERT INTO \"table\"(tableid, isactive) VALUES (nextval('tablesq'),'false'); ";
	BaseQ::setQuery(query,"");
}
//assign table with user prompt
void TableQuery::idAssignment(){

	cout <<"Enter id for table: ";
	cin>>tableID;

	query="UPDATE \"table\" SET isactive=true WHERE tableid='"+tableID+"'";
	BaseQ::setQuery(query,"");	
}
void TableQuery::addTable(int tableNum){
	int tableNotEmptyCheck;

	if(tableNum>=1){
		for(int i=1; i<=tableNum; ++i){
			assignID();			
		}				
	}else{
		cout<<"No tables added."<<endl;
	}//parent if	
}
void TableQuery::assignTable(string waiterID, string tableID){
	query = "UPDATE \"table\" SET isactive=true, waiter_id='"+waiterID+"' WHERE tableid='"+tableID+"'";
	BaseQ::setQuery(query,"");	
}
string TableQuery::getID(){
	return tableID;
}
void TableQuery::deactivateTable(string idTable){
	query = "UPDATE \"table\" SET isactive=false WHERE tableid='"+idTable+"'";
	BaseQ::setQuery(query,"");	
}
bool TableQuery::tableAssignedCheck(string idTable){
	string str("");
	query="";
	query="SELECT \"isTableAssigned\"(\'"+idTable+"\')";
	BaseQ::setQuery(query,"");	

	str = BaseQ::getResultString();
	
	if(str=="t"){
		return true;
	}

	return false;
}