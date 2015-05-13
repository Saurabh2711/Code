#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main(int argc,char *argv[])
{
  struct sockaddr_in serv_addr;
  int fd,n,i;
  char buff[255];
  memset(&serv_addr,0,sizeof(serv_addr));
  fd=socket(AF_INET,SOCK_STREAM,0);
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(5000);
  serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
  connect(fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
  int arr[10];
  char str[10];
  printf("enter the number of element : \n");
  scanf("%s",str);
  write(fd,str,strlen(str));
  int ne=atoi(str);
  for(i=0;i<ne;i++)
  {
    scanf("%s",str);
    write(fd,str,strlen(str));
  }
  for(i=0;i<ne;i++)
  {
    n=read(fd,buff,255);
    write(1,buff,n);
  }
}
