#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
		printf("Socket Error\n");
	struct sockaddr_in serv,client;
	int len=sizeof(client);
	serv.sin_family=AF_INET;
	serv.sin_port=htons(8224);
	inet_pton(AF_INET,"192.168.19.132",&serv.sin_addr);
	int b = bind(sfd,(struct sockaddr *)&serv,sizeof(serv));
	if(b<0)
		printf("Bind Error\n");
	listen(sfd,5);
	int connfd=accept(sfd,(struct sockaddr *)&client,&len);
	write(connfd,"Tanay",6);
	close(connfd);
}