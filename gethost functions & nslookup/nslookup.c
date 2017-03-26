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

int main(void)
{
  struct addrinfo* result;
  struct addrinfo* res;
 
  getaddrinfo("www.google.com",NULL,NULL,&result);

  for(res=result; res!=NULL; res->ai_next)
{
  char hostname[1025];
  getnameinfo(res->ai_addr, res->a_addrlen, hostname,1025,NULL,0,0);
  if(hostname != '\0')
  printf("hostname:%\n",hostname);
}

  freeaddrinfo(result);
  return 0;
}
