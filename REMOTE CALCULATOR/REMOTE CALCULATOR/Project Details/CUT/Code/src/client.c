/* 	Filename: client.c
	Description: This file is used to display the client to the user.*/

#include "../Header/Header2.h" //Header file
#include "login.c" //Login file
void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc,char *argv[])
{
	struct user newuser=getdetails(1);
	int sockfd,portno,n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];           
	if(argc < 3)                //To provide proper ipaddress/port no.
	{
		fprintf(stderr,"Usage %s hostname port.\n",argv[0]);
		exit(1);
	}
	portno = atoi(argv[2]);    
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)            // If socket fails
	{
		error("Error opening socket.");
	}
	server = gethostbyname(argv[1]); //get the ipaddress of the server
	if(server == NULL)
	{
		fprintf(stderr,"no Such host");
        	exit(0);
	}
	bzero((char *) &serv_addr,sizeof(serv_addr)); //
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);//copies n bytes 
	serv_addr.sin_port = htons(portno);
	if(connect(sockfd, (struct sockaddr *) &serv_addr , sizeof(serv_addr)) < 0)
	{
		error("Connection Failed !!");
	}
      	send(sockfd,&newuser,sizeof(newuser),0); 
	
	char expression[256];
	char nums[256];
	char operands[256];
    
X:	bzero(buffer,256);//clearing buffer
	read(sockfd,buffer,256);
	printf("SERVER - %s",buffer);
    	scanf("%s",nums);
	nums[strlen(nums)-1]='\0';           

	int x=write(sockfd,&nums,sizeof(nums));// send nums to server
	bzero(buffer,256);
	read(sockfd,buffer,256); //read server string
	printf("SERVER - %s",buffer); 
      	scanf("%s",operands);
	//printf("%s",operands);
	//operands[strlen(operands)-1]='\0';   
	
	int y=write(sockfd,&operands,sizeof(operands));//send operands to server

	char answer[256];
	read(sockfd,&answer,sizeof(answer));
	printf("\nSERVER : The answer is : %s\n",answer);//Result will be fetched from server
	int choice;
	printf("\n\n1.CONTINUE \n2.EXIT\n"); //Enter choice
	scanf("%d",&choice);
	write(sockfd,&choice,sizeof(choice));//send choice
	if(choice==1)
	{
		goto X;
	}
	printf("YOU HAVE SELECTED TO EXIT \nEXIT SUCCESSFULLY!!!");
	close(sockfd);// close socket
	return 0;

}
