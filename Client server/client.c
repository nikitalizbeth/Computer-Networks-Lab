
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[]) {
   int sockfd, n;
   struct sockaddr_in serv_addr;
   char buffer[256];
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   memset(&serv_addr, '0', sizeof(serv_addr)); 
   inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
   serv_addr.sin_port = htons(5000);
   serv_addr.sin_family = AF_INET;
   connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   
   printf("Please enter the message: ");
   bzero(buffer,256);
   fgets(buffer,255,stdin);
    write(sockfd, buffer, strlen(buffer));
   bzero(buffer,256);
   read(sockfd, buffer, 255);
   printf("%s\n",buffer);
   return 0;
}
