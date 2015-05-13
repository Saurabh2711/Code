#include<cstdio>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<cstring>
#include<errno.h>
#include<unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main(int argc,char *argv[])
{
  struct sockaddr_in server_ad;
  char buff[255];
  int s_fd=socket(AF_INET,SOCK_STREAM,0);
  memset(&server_ad,0,sizeof(server_ad));
  memset(buff,0,sizeof(char)*255);
  server_ad.sin_family=AF_INET;
  server_ad.sin_port=htons(5000);
  server_ad.sin_addr.s_addr=htonl(INADDR_ANY);
  bind(s_fd,(struct sockaddr *)&server_ad,sizeof(server_ad));
  listen(s_fd,10);
    int c_fd=accept(s_fd,NULL,NULL);
    strcpy(buff,"This msg from server\n");
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    send(c_fd,(char *)arr,sizeof(int)*10,0);
    recv(c_fd,buff,40,0);
    write(1,buff,40);
  return 0;
}
