#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 1000
#define SA struct sockaddr
void func(int sockfd)
{
	char buff[MAX];
	char num1[MAX], num2[MAX], resultado[MAX];

	bzero(buff, sizeof(buff));
	bzero(resultado,sizeof(resultado));
	bzero(num1, sizeof(num1));
	bzero(num2,sizeof(num2));

	int n;
	//unsigned long long int resultado;

	printf("Enter number 1 : ");
	scanf("%s", &num1);

	write(sockfd, num1, sizeof(num1));
	
	printf("Enter number 2 : ");
	scanf("%s", &num2);

	write(sockfd, num2, sizeof(num2));
	

	bzero(buff, sizeof(buff));
	bzero(resultado,sizeof(resultado));

	read(sockfd, buff, sizeof(buff));
	strcpy(resultado,buff);
	printf("The answer from Server : %s\n", resultado);
}

int main(int argc, char **argv)
{

	if(argc<2){
		printf("<host> <puerto>\n");
    	return 1;
  	}

	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and varification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		return -1;
	}
	else
		printf("connected to the server..\n");

	// function for chat
	func(sockfd);

	// close the socket
	close(sockfd);
}
