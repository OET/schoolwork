#!/usr/local/bin/python

import insertDocument
import main
import query_pymongo
import addReminder
import db_connect
import getReminder
import menuDisplay

def _test_1():
    print('test_2 executed ')
    value=insertDocument.one()
    assert(5== value),"one() failed"
    
def _test_main():
    #main(displayUserInput="", categoryName="",nameReminder="",summaryReminder="",dateRemind="",testMode=False):
    # 0 : success
    # 1 : Reminder function returned bad value
    # 2 : addReminder function returned bad value
                    
    value = main.main("1", "school","","","", True)
    print "Returned Function Value:",value
    assert(0== value),"main() failed"

def _test_query_pymongo():
    #query(doc, queryType, testMode=False):
    # 0 : success
    #1 : bad db connection passed into query()
    #2 : "Error IOError"
    #5: "query Type unknown
    doc = {"name":"school"}
    queryType = "4"
    value = query_pymongo.query(doc, queryType,True)
    print "Returned Function Value:",value
    
    assert(5== value),"query_pymongo() failed"
   
def _test_addReminder():
    #addReminder(nameReminder="",summaryReminder="",dateRemind="", testMode=False):
    # 0 : success
    #1 : bad db connection passed into query()
    #2 : "Error IOError"
    #5: "query Type unknown
    value = addReminder.addReminder("school","CS presentation","May 15,2013",True)
    print "Returned Function Value:",value
    assert(0== value),"addReminder() failed"

def _test_db_connect():
    #dbConnection(dbHost="localhost", dbPort=27017,dbName="db_remind", testMode=False):
    #0 : success
    #1 : bad db connection passed into query()
    value = db_connect.dbConnection(testMode=True)
    print "Returned Function Value:",value
    assert(0== value),"db_connect() failed"

def test_getReminder():
    #reminder(categoryName,testMode=False):
    # 0 : success
    #1 : bad db connection passed into query()
    #2 : "Error IOError"
    #5: "query Type unknown 
    value = getReminder.reminder(2,True)
    print "Returned Function Value:",value
    assert(0== value),"getReminder() failed"

def _test_menuDisplay():
    #displayMenu(inputFromUser="", testMode=False):
    # 0 : success
    #1 : Unknown input
    value = menuDisplay.displayMenu("1",True)
    print "Returned Function Value:",value
    assert(0== value),"menuDisplay() failed"  
    
if __name__ == '__main__':      
     for func in (val for key,val in vars().items()
                  if key.startswith('test')):
                      func()