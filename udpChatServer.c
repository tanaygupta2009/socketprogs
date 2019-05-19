#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
        int sfd=socket(AF_INET,SOCK_DGRAM,0);
        if(sfd<0)
                printf("Socket Error\n");
        struct sockaddr_in serv,client;
        int len=sizeof(client);
        serv.sin_family=AF_INET;
        serv.sin_port=htons(9999);
        inet_pton(AF_INET,"192.168.6.8",&serv.sin_addr);
        int b = bind(sfd,(struct sockaddr *)&serv,sizeof(serv));
        if(b<0)
                printf("Bind Error\n");
        //listen(sfd,5);
        //int connfd=accept(sfd,(struct sockaddr *)&client,&len);
        char s[200];
        while(1)
        {
                recvfrom(sfd,s,sizeof(s),0,(struct sockaddr* )&client,&len);
                printf("%s\n",s);
                scanf("%s",&s);
                sendto(sfd,s,strlen(s),0,(struct sockaddr*)&client,len);
        }
        close(sfd);
        return 0;
}
