#!/usr/local/bin/python

import menuDisplay
import addReminder
import todayReminder
import recv_all
import socket
import recv_pymongo

def main():
    
    
    inputUser = 9
    
    while inputUser != 0: 
       inputUser = menuDisplay.displayMenu()
       #s = socket.socket()
       #s.connect("localhost", 4001)
    
    
       if(inputUser == "1"):
           #todayReminder.todayReminder()
           #s.send("Hi Node")
           #recv_all.recving(s, 1024)
#           reply = recv_all.recving(s, 1024)
#           for q in reply:
#               print "Server Reply:",q
            recv_pymongo.recv()
           
       if(inputUser == "2"):
           addReminder.addReminder()
           

       


if __name__ == '__main__':
    main()
