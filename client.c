#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
		printf("Error Creating Error.\n");
	struct sockaddr_in serv;
	serv.sin_family	= AF_INET;
	serv.sin_port = htons(8224);
	//serv.sin_addr = htonl("192.168.1.1");
	inet_pton(AF_INET,"192.168.19.132",&serv.sin_addr);
	connect(sfd,(struct sockaddr*)&serv,sizeof(serv));
	char s[200];
	int n=read(sfd,s,sizeof(s));
	write(1,s,n);
	return 0;
}
