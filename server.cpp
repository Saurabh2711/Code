#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<stdlib.h>
#include<pthread.h>
void *sort(void *id);
main(int argc,char *argv[])
{
  struct sockaddr_in server_ad;
  char buff[255];
  int n;
  int s_fd=socket(AF_INET,SOCK_STREAM,0);
  memset(&server_ad,0,sizeof(server_ad));
  memset(buff,0,sizeof(char)*255);
  server_ad.sin_family=AF_INET;
  server_ad.sin_port=htons(5000);
  server_ad.sin_addr.s_addr=htonl(INADDR_ANY);
  bind(s_fd,(struct sockaddr *)&server_ad,sizeof(server_ad));
  listen(s_fd,10);
  while(1)
  {
    int ne,i,arr[29],j;
    int c_fd=accept(s_fd,NULL,NULL);
    pthread_t pth;
    pthread_create(&pth,NULL,sort,(void *)&c_fd);
  }
  return 0;
}
void *sort(void *id)
{
  int c_fd=*(int *)id;
  int n,i,j,arr[10],ne;
  char buff[255];
  char str[10];
    n=read(c_fd,buff,255);
    strncpy(str,buff,n);
    str[n]='\0';
    ne=atoi(str);
    for(i=0;i<ne;i++)
    {
      n=read(c_fd,buff,255);
      strncpy(str,buff,n);
      str[n]='\0';
      arr[i]=atoi(str);
      printf("%d\n",arr[i]);
    }
    for(i=0;i<ne;i++)
    {
      for(j=0;j<ne-1;j++)
      {
	if(arr[j]>arr[j+1])
	{
	  int temp=arr[j];
	  arr[j]=arr[j+1];
	  arr[j+1]=temp;
	}
      }
    }
    for(i=0;i<ne;i++)
    {
     sprintf(str,"%d\n",arr[i]);
     write(c_fd,str,strlen(str));
    }
}
