#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// for showing error message 
void error (const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc , char *argv[])
{
	int sockfd ,portno ,n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	char buffer[255];
	if(argc < 3)
	{	
		//enter hostname and server port
		fprintf(stderr , "usage %s hostname port\n" , argv[0]);
		exit(1);
	}
	// converting portno from string to integer
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if(sockfd <0)
		error("error openong socket");
	
	//function for converting name of client to ip address	
	server = gethostbyname(argv[1]);
	if(server == NULL)
	fprintf(stderr , "error , no such host");
	
	bzero((char *) &serv_addr , sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	//bcopy((char *) server->h_addr , (char *) &serv_addr.sin_addr.s_addr ,server->h_length);
	serv_addr.sin_port = htons(portno);
	
	//calling connect function for connection estabilishment to server
	if(connect(sockfd , (struct sockaddr *) &serv_addr , sizeof(serv_addr))<0)
		error("connection failed");
	
	
	while(1)
	{
		printf("connected to server, plase enter what u want to do.\n");
		bzero(buffer ,255);
		fgets(buffer , 255 ,stdin);
		
		//sending message to server
		n = write(sockfd , buffer , strlen(buffer));
		if(n<0)
			error("error on writing");
		
		
		//receiving message	
		bzero(buffer ,255);
		n = read(sockfd , buffer , 255);
		if(n<0)
			error("eoor on reading");
		
		printf("server : %s" , buffer);
		bzero(buffer ,255);
		fgets(buffer ,255 ,stdin);
		n = write(sockfd , buffer , strlen(buffer));
		if(n<0)
			error("error on writing");
		
		
			
		
	   }
	
	
	// closing the socket
	
	     close(sockfd);
	      return 0;
	
	
	}
		





