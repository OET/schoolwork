#!/usr/local/bin/python

import menuDisplay
import addReminder
import getReminder


def main(displayUserInput="", categoryName="",nameReminder="",summaryReminder="",dateRemind="",testMode=False):
       
    inputUser = 9
    
    if(testMode==False):
        while inputUser != 0: 
            inputUser,menuFuncExecuteStatus = menuDisplay.displayMenu(displayUserInput, testMode)
            
            if(menuFuncExecuteStatus == 0):
                
               if(inputUser == "1"):
                 reminderFuncExecuteStatus = getReminder.reminder(categoryName, testMode)
                 if(reminderFuncExecuteStatus != 0):
                    print"Reminder function returned bad value"
                    return 1 
                   
               if(inputUser == "2"):
                 addReminderFuncExecuteStatus = addReminder.addReminder(nameReminder,summaryReminder,dateRemind,testMode)  
                 if(addReminderFuncExecuteStatus != 0):
                    print"addReminder function returned bad value"
                    return 2        
            else:
                print "Bad user entry during display menu"  
                
                
    if(testMode==True):  
             
            print "Executed Function: main()\n"     
            inputUser,menuFuncExecuteStatus = menuDisplay.displayMenu(displayUserInput, testMode)
            
            if(menuFuncExecuteStatus == 0):
                
               if(inputUser == "1"):
                 reminderFuncExecuteStatus = getReminder.reminder(categoryName, testMode)
                 return 0
             
                 if(reminderFuncExecuteStatus != 0):
                    print"Reminder function returned bad value"
                    return 1 
                   
               if(inputUser == "2"):
                 addReminderFuncExecuteStatus = addReminder.addReminder(nameReminder,summaryReminder,dateRemind,testMode) 
                 return 0
              
                 if(addReminderFuncExecuteStatus != 0):
                    print"addReminder function returned bad value"
                    return 2        
            else:
                print "Bad user entry during display menu"      
                     
if __name__ == '__main__':
    main()
   
