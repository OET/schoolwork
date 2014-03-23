import query_pymongo


def reminder(categoryName,testMode=False):  
    if(testMode==True):
        
        print "Executed Function: reminder()\n"
        remind_doc={ "name": categoryName}
        executeStatus = query_pymongo.query(remind_doc, "1", testMode)   
        
    if(testMode==False):
        category = raw_input("Enter category name: ")
    
        remind_doc={ "name": category}
        executeStatus = query_pymongo.query(remind_doc, "1",testMode)
    
    return executeStatus