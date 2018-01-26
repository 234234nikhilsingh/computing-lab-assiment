#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "tockanizer.c"
#include "tocken2.c"
#include "read.c"

void fun(int sock);    // function for handaling communication

char buffer[255];
char bu[255];
int i1;
void error (const char *msg)     // show system error message
{
	perror(msg);
	exit(1);
}

int main(int argc , char *argv[])

{	
	
	if(argc<2)
	{
		fprintf(stderr , "port no- not provided.program termination");
		exit(1);
	}
	
	int sockfd ,newsockfd ,portno,n;
	
	
	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen;
	sockfd = socket(AF_INET , SOCK_STREAM , 0);     // create socket descripter
	if(sockfd<0)
	{
		error("error opening socket");
		
	}
	bzero((char *) &serv_addr , sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if(bind(sockfd , (struct sockaddr *) &serv_addr , sizeof(serv_addr)) < 0)     // bind the socket with server address
		error("binding failed");
	listen(sockfd ,  10);
	clilen = sizeof(cli_addr);
	
	while(1)
	{       
	  	newsockfd = accept (sockfd ,(struct sockaddr *)  &cli_addr, &clilen);   //accept client connection request
	
		if(newsockfd <0 )
		error("error on accept");
		
		int pid = fork();                              // creating new child for handling client request 
		if(pid < 0)
		printf("error in creating chld");
		if(pid==0)
		{	
			close(sockfd);                      // close server socket in child process 
			fun(newsockfd);
			exit(0);
			
		}
		else
		close(newsockfd);                       // close client socket in parent process
		
		}
		close(sockfd);                       // close server socket in parent, no new connection can be estabilished
		return 0;
     }
		
		
		
		
		
		
		
	
void fun(int newsockfd)
 {
 	  
 	      while(1)
 	      {
 		bzero(buffer ,255);
		int n = read(newsockfd , buffer , 255);
		if(n<0)
			error("error on reading. ");
		char choice[255];
		char toc[255];
		strcpy(toc ,buffer);
		strcpy(choice ,tocken2(toc));
		char read1[] = "READX";
		char write1[] = "WRITEX";
		if(strcmp(choice,"READX") == 0 )
		{
			
			i1 = tockenizer(buffer);
			bzero(buffer , 255);
			strcpy(buffer,reading(i1));
			n = write(newsockfd , buffer , strlen(buffer));
		        if(n<0)
				error("error on writting. ");
			
			bzero(buffer ,255);
		    n = read(newsockfd , buffer , 255);
		   if(n<0)
		    	error("error on reading. ");
		
		}
		
		else if(strcmp(choice,"WRITEX")== 0 )
		{
			FILE *fp;
			fp= fopen("abb.txt","a+");
			if(fp == 0)
			printf("error openinf");
			char message[255] ="SEND ME WHAT U WANT TO BE WRITTEN IN FILE\n";
			bzero(buffer , 255);
			strcpy(buffer ,message);
			n = write(newsockfd , buffer , strlen(buffer));
		        if(n<0)
				error("error on writting. ");
			
			bzero(buffer ,255);
		        n = read(newsockfd , buffer , 25);
		        if(n<0)
			error("error on reading. ");
			fprintf(fp,"%s%s","we",buffer);
			fclose(fp);
			
		}
		  
 	  }
 	  
 	  close(newsockfd);	
 	  
 }



	










