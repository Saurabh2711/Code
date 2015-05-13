#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>
sem_t f[5];
void *eat(void *x)
{
  int p=*(int *)x;
  int left,right;
  if(p==0)
    left=4;
  else
    left=p-1;
  right=p;
  if(p%2!=0)
  {
    sem_wait(&f[left]);
    sem_wait(&f[right]);
    printf("%d eating ....\n",p);
    sleep(1);
    sem_post(&f[right]);
    sem_post(&f[left]);
  }
  else
  {
    sem_wait(&f[right]);
    sem_wait(&f[left]);
    printf("%d eating....\n",p);
    sleep(1);
    sem_post(&f[left]);
    sem_post(&f[right]);
  }
  printf("%d finished eating...\n",p);
}
main()
{
  pthread_t th[20];
  int i;
  for(i=0;i<5;i++)
  {
    sem_init(&f[i],0,1);
  }
  for(i=0;i<20;i++)
  {
    int x=i%5;
    pthread_create(&th[i],NULL,eat,(void *)&x);
  }
  for(i=0;i<20;i++)
  {
    pthread_join(th[i],NULL);
  }
}
