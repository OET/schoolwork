import sys
import pymongo


def dbConnection(dbHost="localhost", dbPort=27017,dbName="db_remind", testMode=False):
     
    try:           
        #connection = pymongo.Connection(host="localhost",port=27017)
        connection = pymongo.Connection(dbHost,dbPort)
        successfulConnection = 0

        #dbh = connection["db_remind"]
        dbh = connection[dbName]
        
        if(testMode==False):
            return dbh,successfulConnection;
    
        if(testMode==True):
            print "Executed Function: dbConnection()\n"
            print "Access db: mongoDB\n"
            print "Executed Function: dbConnection()\n"
            return dbh,successfulConnection;
            
        
    except pymongo.ConnectionFailure, e:
        sys.stderr.write("Could not connect to MongoDB: %s" % e)
        successfulConnection = 1
        return successfulConnection
        