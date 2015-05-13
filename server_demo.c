#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
void error(char *msg)
{
  perror(msg);
  exit(1);
}
main(int argc,char *argv[])
{
  int socket_fd,new_socket_fd,port_no;
  struct sockaddr_in server_addr,client_addr;
  char buffer[256];
  bzero(buffer,256);
  socket_fd=socket(AF_INET,SOCK_STREAM,0);
  if(socket_fd<0)
  {
    error("ERROR, unable to create socket\n");
  }
  server_addr.sin_family=AF_INET;
  server_addr.sin_port=htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr=INADDR_ANY;
  if((bind(socket_fd,(struct sockaddr *)&server_addr,sizeof(server_addr)))<0)
  {
    error("Error, Unable to bind\n");
  }
  listen(socket_fd,10);
  int client=sizeof(client_addr);
  new_socket_fd=accept(socket_fd,(struct sockaddr *)&client_addr,&client);
  if(new_socket_fd<0)
  {
    error("Error, unable to accept\n");
  }
  int n=read(new_socket_fd,buffer,255);
  printf("Here is your msg : %s\n",buffer);
  write(new_socket_fd,"I got your msg",15);
 return 0; 
}
