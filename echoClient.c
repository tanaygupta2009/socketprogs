#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
        int sfd = socket(AF_INET,SOCK_STREAM,0);
        if(sfd<0)
                printf("Error Creating Error.\n");
        struct sockaddr_in serv;
        serv.sin_family = AF_INET;
        serv.sin_port = htons(9999);
        //serv.sin_addr.s_addr = htonl(INADDR_ANY);
        inet_pton(AF_INET,"192.168.6.8",&serv.sin_addr);
        connect(sfd,(struct sockaddr*)&serv,sizeof(serv));
        char s[200];
        scanf("%s",&s);
        write(sfd,s,strlen(s));
        int n = read(sfd,s,sizeof(s));
        write(1,s,n);
        return 0;
}
