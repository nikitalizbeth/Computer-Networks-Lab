#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main( int argc,char *argv[])
{
struct servent * serv;
struct servent * ser;
serv=getservbyname("msp","tcp");
ser=getservbyport(4608,"tcp");
printf("%d\n",serv->s_port);
printf("%s\n",ser->s_name);
return 0;

}
