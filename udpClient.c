#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
        int sfd = socket(AF_INET,SOCK_DGRAM,0);
        if(sfd<0)
                printf("Error Creating Error.\n");
        struct sockaddr_in serv;
        serv.sin_family = AF_INET;
        serv.sin_port = htons(9999);
        //serv.sin_addr.s_addr = htonl(INADDR_ANY);
        inet_pton(AF_INET,"192.168.6.8",&serv.sin_addr);
        //connect(sfd,(struct sockaddr*)&serv,sizeof(serv));
        sendto(sfd,"LMAO",5,0,(struct sockaddr*)&serv,sizeof(serv));
        return 0;
}
