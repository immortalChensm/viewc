
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <error.h>
int main(int argc,char *argv[])
{

    if(argc<2){
        printf("usage:%s ip and port\n",basename(argv[0]));
    }

    const char *ip = argv[1];
    const int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address,sizeof(address));

    address.sin_family = AF_INET;

    address.sin_port = htons(port);//host to network short int
    inet_pton(AF_INET,ip,&address.sin_addr);

    int sock = socket(PF_INET,SOCK_STREAM,0);

    assert(sock>=0);

    int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
printf("errno=%d\n",errno);
    assert(ret!=-1);

    ret = listen(sock,5);
    assert(ret!=-1);

    sleep(30);

    struct sockaddr_in client;
    socklen_t client_addrlenth = sizeof(client);

    int confd = accept(sock,(struct sockaddr*)&client,(socklen_t*)&client_addrlenth);
ets
    if(confd<0){
        printf("error is %d\n",error);
    }else{
        char remote[INET_ADDRSTRLEN];
        printf("ip is %s,port is %d\n",inet_ntop(AF_INET,&client.sin_addr,remote,INET_ADDRSTRLEN),ntohs(client.sin_port));
        close(confd);
    }
    close(sock);


    return 0;
}
