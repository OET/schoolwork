#include "objquery.h"

int main(){
	try
	{ 
		AppServer appserver(60000);
		appserver();
	}
	catch(std::exception e)
	{
		cerr <<"Error: "<<e.what() << endl;
	}

}//main
