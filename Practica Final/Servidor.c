#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 1000
#define SA struct sockaddr

// Function designed to calculate an addition between 2 numbers
void func(int sockfd)
{
	char buff[MAX];
	char numero1[MAX];
	char numero2[MAX];
	char suma[MAX]= {'0'};
	char auxString[MAX];
	long lenNum1, lenNum2;

	//Limpiamos las variables.
	
	bzero(numero1, sizeof(numero1));
	bzero(numero2,sizeof(numero2));

	// read the message from client and copy it in numero1
	read(sockfd, numero1, sizeof(numero1));
	lenNum1 = strlen(numero1);
	char num1[lenNum1];
	strcpy(num1, numero1);

	
	printf("Tamaño del numero 1: %li\n", lenNum1);
	printf("Valor del numero 1: %s\n", num1);


	read(sockfd, numero2, sizeof(numero2));
	lenNum2 = strlen(numero2);
	char num2[lenNum2];
	strcpy(num2, numero2);
	
	
	printf("Tamaño del numero 2: %li\n", lenNum2);
	printf("El valor del numero 2 es: %s\n", num2);
	

	//Comparison of the numbers to see which is bigger.
	int longest_num;

	if(lenNum1 >= lenNum2){

		longest_num = lenNum1+1;
	}else{

		strcpy(auxString, num1);
		strcpy(num1, num2);
		strcpy(num2,auxString);

		lenNum1 = strlen(num1);
		lenNum2 = strlen(num2);

		longest_num = lenNum2+1;
	}

	printf("El numero mas grande es de: %i digitos", longest_num);

	//suma[longest_num];


	int acarreo = 0;
	int aux, auxNum1, auxNum2;
	int j = lenNum2 - 1;
	if(lenNum1 >= lenNum2){
		for(int i = lenNum1 - 1; i >= 0; i--){
			auxNum1 = (num1[i]) - '0';
			if (j >= 0){
				auxNum2 = (num2[j]) - '0';
				j--;
			} else {
				auxNum2 = 0;
			}
			aux = auxNum1 + auxNum2 + acarreo;

			if (aux >= 10){
				suma[i+1] = (aux - 10)+'0';

				acarreo = 1;
			} else {
				suma[i+1] = (aux)+'0';
				acarreo = 0;
			}
		}
	}
		
	if(suma[0] = '0'){

		for(int i=0; i<longest_num;i++){

			suma[i] = suma[i+1];
		}
	}	

	printf("\nLa suma es: %s\n", suma);

	write(sockfd, suma, sizeof(suma));
	printf("\nAnswer sent");
	
}

// Driver function
int main(int argc, char const *argv[])
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
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

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
