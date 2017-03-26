/*
    Simple udp client
*/
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#define SERVER "127.0.0.1"
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to send data
 

int main(void)
{
    struct sockaddr_in si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];
 
    s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
     
    inet_aton(SERVER , &si_other.sin_addr);
   
    while(1)
    {
        printf("Enter message : ");
        scanf("%s",message);
         
        //send the message
        sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, sizeof(si_other));
                 
        //receive a reply and print it
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
        //try to receive some data, this is a blocking call
        recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);       
         
        puts(buf);
    }
 
    close(s);
    return 0;
}
