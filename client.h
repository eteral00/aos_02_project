#ifndef CLIENT_H
#define CLIENT_H

#include "node.h" 
#include "message.h"

#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class Client
{
	public:
		int sockfd, numbytes;  
		struct addrinfo hints, *servinfo, *p;
		int rv;
		int error_num;
		char s[INET6_ADDRSTRLEN];
		Node dest;
		Node src;
		
		Client(const Node& src, const Node& dest);
		int SendMessage(Message out);

		int Close();
		void *get_in_addr(struct sockaddr *sa);
};

#endif // CLIENT_H
