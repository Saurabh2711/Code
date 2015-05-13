#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
int a,b;
void *fun(void *temp)
{

  a=*(int *)temp;
  pthread_exit("Saurabh");
}
void *fun2(void *temp)
{

  b=*(int *)temp;
}
main()
{
  int c;
  pthread_attr_t atr1,atr2;
  pthread_attr_init(&atr1);
   pthread_attr_init(&atr2);
   pthread_attr_setdetachstate(&atr2,PTHREAD_CREATE_DETACHED);
  a=1,b=2;
  int x=4,y=5;
  pthread_t thread_a,thread_b;
  pthread_create(&thread_a,&atr1,fun,(void *)&x);
  pthread_create(&thread_b,&atr2,fun2,(void *)&y);
  sleep(1);

  c=a+b;
  printf("%d\n",c);
  x=pthread_join(thread_a,NULL);
  if(x==EINVAL)
    printf("Detached Thread\n");
  else
    printf("Joinable Thread\n");
  
  y=pthread_join(thread_b,NULL);
  if(y==EINVAL)
    printf("Detached Thread\n");
  else
    printf("Joinable Thread\n");
  
}