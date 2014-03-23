#import json
import query_pymongo

def addReminder(nameReminder="",summaryReminder="",dateRemind="", testMode=False):
     if(testMode==False):
        enterMore = True
        reminderName=""
        summary=""
        timeRemind=""
        jsonObj=[]
        
        while enterMore != False:     
            reminderName = raw_input("Enter name of reminder: ")
            summary = raw_input("Enter brief summary: ")
            timeRemind = raw_input("Enter date of reminder: ")
            jsonObj.append({"name":reminderName, "summary":summary,"date":timeRemind})
            user_answer = raw_input("Do you have more entry [y] or [n]: ")
            if (user_answer=='n'):
                enterMore = False
         
         
        status = query_pymongo.query(jsonObj, "2")
        return status
       # print json.dumps(jsonObj,indent=4)
       
     if(testMode==True):  
        jsonObj=[]
        print "Executed Function: addReminder()\n"      
        jsonObj.append({"name":nameReminder, "summary":summaryReminder,"date":dateRemind})
               
        status = query_pymongo.query(jsonObj, "2")
        return status