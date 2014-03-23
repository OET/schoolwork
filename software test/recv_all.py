import json
def recving(sock, length):
   
    '''
    data = ''
    more = sock.recv(length - len(data))
    data += more
    return data
    '''
    '''
    data = ''
    while len(data) < length:
        more = sock.recv(length - len(data))
        if not more:
            raise EOFError('socket closed %d bytes into a %d-byte message'
                           % (len(data), length))
            print more   
#        data += more
#    return data
       '''



    more = sock.recv(length)
    print more.upper()
#    json_object = json.loads(more)
    
#    print json_object
    #print len(json_object)
#    for k,v in json_object.items():
#         print k,v
#    for k in json_object.items():
#        print k.get("name")
    