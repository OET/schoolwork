import db_connect
import json
from bson import json_util

def query(doc, queryType, testMode=False):        
    
    if(queryType == "1"):
        try: 
            if(testMode==False):
                print"Checking database\n"
                db_handle,dbConnectStatus = db_connect.dbConnection() 
                
            if(testMode==True):
                print "Executed Function: query()\n"
                db_handle,dbConnectStatus = db_connect.dbConnection(testMode=True)
                print "Executed Function: query()\n"
            
            if(dbConnectStatus == 0):      #0 is successful           
                results = db_handle.recall.find(doc,{"_id":0})       
            else:
                print"bad db connection passed into query()"
                return 1
            
            if results.count() != 0: 
                for res in results:
                   print "\t_Reminder_\n"+"Description: "+res["summary"]
                   print res["date"]
                   return 0     
         
        except IOError:
                print "Error IOError"
                return 2

    if(queryType == "2"):           
        if(testMode==True):            
            print "Executed Function: query()\n"
            print"Updating database\n"    
            
        db_handle,dbConnectStatus = db_connect.dbConnection(testMode=True) 
        
        if(dbConnectStatus == 0):      #0 is successful  
            db_handle.recall.insert(doc,safe=True)
            print "Successfully added Reminder"        
            return 0
        else:
            print"bad db connection passed into query()"
            return 1 
    
    
    else: #queryType Check
             print "query Type unknown"
             return 5