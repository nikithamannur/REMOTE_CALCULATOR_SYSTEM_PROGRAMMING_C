/* 	Filename: server.c
	Description: This file is used to display the server side to the user.*/

#include "../Header/Header1.h"   //Header file
#include "calculate.c" 		//Calculate file
#include "login.c"     		//Login file

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

// argc is the total number of the parameter we are passing 

int main(int argc,char *argv[]){
	if(argc < 2){
		fprintf(stderr , "Port not provided . Program Terminated \n");
		exit(1);
	}

	int sockfd,newsockfd,portno,n;
	char buffer[255];                    // to store msg or send

	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen;                   //socklen_t is a datatype in socket.h 32 bit 

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{                                   // if sock fd is resulting in failure
		error("Error opening socket");
	} 
	
	bzero((char *) &serv_addr,sizeof(serv_addr)); // it clears all the data to what it it reference to 
      
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
	{
		error("Binding Failed");
	}

	//server trying to connect
	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr , & clilen);//Connection established with client 
	if(newsockfd < 0)
	{
		error("Error on Accept");
	}
	
	//Login functionality
	int errmsg;
	struct user newuser;
	recv(newsockfd, &newuser, sizeof(struct user), 0);//Receiving proper username and password from client
	{
		if(strcmp(newuser.username,"nikitha")!=0)
		{
			errmsg=write(newsockfd,"Username not found.Access denied!",strlen("Username not found.Access denied!"));
			close(newsockfd);
			close(sockfd);
			return 0;

		}	
		if(strcmp(newuser.password,"qwerty")!=0)
		{
		errmsg=write(newsockfd,"Wrong Password.Access denied!",strlen("Wrong Password.Access denied!"));
		close(newsockfd);
		close(sockfd);
		return 0;
		}
		else{
			printf("LOGIN SUCCESSFULL...\n");
	     	}
	}
	int msg1,msg2,msg3,answer,choice;//Initializing
	char num[256];				//Initialize num
	char operands[256];			//Initialize operands
	char  expression[256];		//Initialize expression

S:	msg1 = write(newsockfd,"Enter the number of arguments and operands using (:) - ",strlen("Enter the number of arguments and operands using (:)- "));
	if(msg1<0)
	{
		error("error writing to socket");	
	}
	read(newsockfd,&num,sizeof(num));
	

	//defining numbers and operands array 

	msg2 = write(newsockfd,"Select operators from ( + , - , * , /).\nEnter the operators using (;) seperator- ",strlen("Select operators from ( + , - , * , /).\nEnter the operators using (;) seperator- "));	
	read(newsockfd,&operands,sizeof(operands));
	tn=-1;
	to=-1;
	
	solve(expression,num,operands); 
    	printf("\nEntered expression is : %s \n",expression);
	answer=eval(expression);
	printf("The answer is %d.\n",answer);
	char finans[256];
	sprintf(finans,"%d",answer);
	int x=write(newsockfd,&finans,sizeof(finans));
 	if(x<0)
	{
	error("ERROR PRINTING ANSWER.");	
	}
	read(newsockfd,&x,sizeof(int));
	if(x==1)
	{
		strcpy(num,"");
		strcpy(operands,"");
		strcpy(buffer,"");
                strcpy(expression,"");

		goto S;
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}
