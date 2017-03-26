 

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

int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, clilen;
   char buffer[256];
   struct sockaddr_in serv_addr, cli_addr;
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   memset(&serv_addr, '0', sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(5000);                        
  bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   listen(sockfd,5);
  
   clilen = sizeof(cli_addr);
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
   bzero(buffer,256);
    read( newsockfd,buffer,255 );
   printf("Here is the message: %s\n",buffer);
    write(newsockfd,"I got your message",18);
   
      
   return 0;
}
