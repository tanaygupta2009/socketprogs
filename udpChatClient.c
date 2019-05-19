#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
int main()
{
	int sfd;
	char str[30];
	struct sockaddr_in serv;
	int len=sizeof(serv);
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	serv.sin_family=AF_INET;
	serv.sin_port=htons(9999);
	inet_pton(AF_INET,"192.168.6.8",&serv.sin_addr);
	//connect(sfd,(struct sockaddr *)&serv,sizeof(serv));
	while(1)
	{
		scanf("%s",&str);
		sendto(sfd,str,strlen(str),0,(struct sockaddr*)&serv,len);
		recvfrom(sfd,str,sizeof(str),0,(struct sockaddr*)&serv,&len);
		printf("%s\n",str);
	}
	return 0;
}