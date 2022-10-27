#include <stdio.h>   //Including required Header files
#include<stdlib.h>
#include<string.h>
#define maxlen 20
#define adminid "admin"
#define adminpwd "abc@123"

struct user{
	char username[maxlen];
	char password[maxlen];
};


int checkpassword(char *a, char*b)
{
	if(strcmp(a,b)==0)
	return 1;
	return 0;
}

struct user USERS[10];
int no_of_users=0;

int usernamecheck(char * key)
{
	for(int i=0;i<no_of_users;i++)
	{
		if(strcmp(USERS[i].username,key)==0)
		{
		return 1;
		}
	}
	return 0;

}
void displayusers()
{
	printf("\n\n");
	printf("ALL Registered Users\n");
	printf("\n");
	printf("USERNAME  \t PASSWORD");
	for(int i=0;i<no_of_users;i++)
	{
		printf("\n %s  \t\t\t %s\n",USERS[i].username,USERS[i].password);
		
	}
	return;
}

int registeruser(){
	char uname[20];
	char pwd[20];
	system("clear");
	printf("REMOTE CALCULATOR ");
	printf("Client Side");
	printf("***********");
	printf("Register-");
	printf("Enter Username :  ");
	fgets(uname,20,stdin);
	uname[strlen(uname)-1]='\0';
	printf("\n\n");
	printf("Enter Password :  ");
	fgets(pwd,20,stdin);
	pwd[strlen(pwd)-1]='\0';
		
	//ID CHECK IF ALREADY EXISTS		
	if(usernamecheck(uname))
	{
		printf("Username already exists ");
		return 0;
	}
	strcpy(USERS[no_of_users].username,uname);
	strcpy(USERS[no_of_users].password,pwd);
	no_of_users++;
	printf("\nRegistered Successfully !");
	return 0;
}

struct user getdetails(int x)
{
	char str[25];
	struct user newuser;
	char uname[20];
	char pwd[20];
	if(x==1)
	strcpy(str,"CLIENT");
	else
	strcpy(str,"SERVER");
	int choice=0;
	int Banker_pass=0;
	system("clear");
	printf("\nREMOTE CALCULATOR\n");
	printf("\n");
	printf("ENTER USERNAME : ");
	fgets(newuser.username,20,stdin);
	newuser.username[strlen(newuser.username)-1]='\0';
	printf("ENTER PASSWORD : ");
	fgets(newuser.password,20,stdin);
	newuser.password[strlen(newuser.password)-1]='\0';
	printf("\n");
	return newuser;
}

int login(int x)               
{
	char str[25];
	char uname[20];
	char pwd[20];
	if(x==1)
	strcpy(str,"Client");
	else
	strcpy(str,"Server");
	int choice=0;
	int Banker_pass=0;
	system("clear");
	printf("\nREMOTE CALCULATOR\n",str);
	printf("%s Side",str);
	printf("\n");
	printf("Enter Username :  ");
	fgets(uname,20,stdin);
	uname[strlen(uname)-1]='\0';
	printf("Enter Password :  ");
	fgets(pwd,20,stdin);
	pwd[strlen(pwd)-1]='\0';
			
	if(x==1)
	{
		for(int i=0;i<=no_of_users;i++)
		{
			if(strcmp(USERS[i].username,uname)==0)
			{
				if(strcmp(USERS[i].password,pwd)==0)
				{
					printf("\nYou have logged in to the server !\n");
					return 1;
				}
				else
					{
					printf("\nWrong password !\n");
					exit(0);
					}
			}
		}
		printf("\nUsername not found !\n");
		exit(0);
	}
	else
	{
		if(strcmp(adminid,uname)!=0)
		{
			printf("\nUsername not found !\n");
			return 0;
		}
		if(!checkpassword(adminpwd,pwd))
		{
			printf("\nWrong password !\n");
			exit(0);
		}
		printf("\nYou have logged in to the server !\n");
		return 1;
	}
}

// This is the Main function.
/*int main(){
	strcpy(USERS[0].username,"anshul");
	strcpy(USERS[0].password,"hmm");
	
	//login(0);
	//registeruser();
	//displayusers();
	int choice;
	
	while(1){
	//system("clear");
	printf("\n\n\t\t\t\t    REMOTE CALCULATOR ");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Client Side \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\t_________________________________________\n\n");
		//printf("\n\n");
		printf("\n\n\t\t\t 1 : LOGIN  \n\n");
		//printf("\n\n");
		printf("\t\t\t 2 : REGISTER  \n\n");
		//printf("\n\n");
		printf("\t\t\t 3 : EXIT  \n\n");
		//printf("\n\n");
		printf("Enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					getchar();
					login(1);//change para for diff UI
					break;
				}
			case 2:
				{
					getchar();
					registeruser();//change para for diff UI
					break;
				}
			case 3:
				{	
					displayusers();
					return 0;
				}
			default:
				{
				printf("\t\t\tINVALID CHOICE !!!");
				return 0;
				}
		}	
	}
	
	return 0;
}*/
