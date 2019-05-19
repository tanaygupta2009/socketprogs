#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
int main()
{
	int sfd;
	char str[30];
	struct sockaddr_in serv;

	sfd=socket(AF_INET,SOCK_STREAM,0);
	serv.sin_family=AF_INET;
	serv.sin_port=htons(9999);
	inet_pton(AF_INET,"192.168.6.8",&serv.sin_addr);
	connect(sfd,(struct sockaddr *)&serv,sizeof(serv));
	while(1)
	{
		scanf("%s",&str);
		write(sfd,str,sizeof(str));
		read(sfd,str,sizeof(str));
		printf(str);
	}
	return 0;
}