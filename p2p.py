
  # OUTPUT: a list of URL's of servers in the network.
  # DESCRIPTION:
  #   1. If the URL, u, equals to my own URL, just returns the server list.
  #   2. Otherwise, creates a ServerProxy object for server u. Then calls its
  #      request handling function f with a HMAC digest, mode 0, and server
  #      list with myself added.
  #   3. Calls pr() with the result returned from server u to add them to my
  #      own list.
  #   4. Returns the new list.
  
  pr() and [aug(s) for s in aug(pr()[0])]
  # 1. Checks the server list is not empty.
  # 2. Takes the first server on the list. Asks that server to augment its
  #    server list with my URL.
  # 3. For each server on the returned list, asks it to add this server to its
  #    list.
  
  (lambda sv:sv.register_function(f,"f") or srv(sv))(xs((ar[3],int(ar[4]))))
  # Starts request processing.
  # 1. Defines a function with lambda expression that takes a SimpleXMLRPCServer
  #    object, registers request handling function, f, and starts the server.
  # 2. Creates a SimpleXMLRPCServer object using hostname (ar[3]) and portnum
  #    (ar[4]). Then feeds the object to the lambda function.
  
# Running in client mode...
for url in pxy(ar[3]).f(pw(ar[3]),0,[]):
# 1. Create a ServerProxy object using the serverurl (ar[3]).
# 2. Calls the remote server and retrieves a server list.
# 3. For each URL on the list, do the following:

  for fn in filter(lambda n:not n in ls(), (pxy(url).f(pw(url),1,ar[4]))[0]):
  # 1. Create a ServerProxy object using the URL.
  # 2. Calls the remote server to return a list of filenames matching the
  #    pattern (ar[4]).
  # 3. For each filename doesn't exist locally, do the following:
  
    (lambda fi:fi.write(pxy(url).f(pw(url),2,fn)) or fi.close())(file(fn,"wc"))
    # 1. Define a lambda function that takes a file object, calls remote server
    #    for the file content, then closes the file.
    # 2. Create a file object in write and binary mode with the filename. (I
    #    think the mode "wc" should be "wb".)
    # 3. Passes the file object to the lambda function.
