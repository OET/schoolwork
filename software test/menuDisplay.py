#client will either send request to database for today's reminders 
#OR add a reminder

def displayMenu(inputFromUser="", testMode=False):
    
    if(testMode==False):
        print("\t\t****WELCOME TO REMINDER APP*****\n"
             "(1) Check Today's Reminder\n"
             "(2) Add Reminder")
        userInput = raw_input("Enter menu option: ")
        
        while (userInput != "1") and (userInput != "2") and (userInput != "0"):            
            print"ERROR: Unknown entry, try again \n"
            userInput = raw_input("Enter menu option: ")
        return userInput,0    
          
            
    if(testMode==True):
        
        
        print "Executed Function: displayMenu()\n"
        if(inputFromUser != "1"):
           return inputFromUser,0
        if(inputFromUser != "2"):
           return inputFromUser,0
        if(inputFromUser != "0"):
           return inputFromUser,0
        else:
           return inputFromUser,1
 
                                            
                                
    