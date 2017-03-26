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

int main(int argc, char * argv[])
{
 int i;
struct in_addr ipv4addr;
struct hostent *he;
struct in_addr **addr_list;
he=gethostbyname(argv[1]);
addr_list=(struct in_addr **)he->h_addr_list;

for(i=0; addr_list[i]!=NULL; i++)
{
 printf("%s\n",inet_ntoa(*addr_list[i]));
}

inet_aton("216.58.220.196",&ipv4addr);
he=gethostbyaddr(&ipv4addr,sizeof(ipv4addr),AF_INET);
printf("Host name:%s\n",he->h_name);

return 0;
}
