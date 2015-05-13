#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define no_ph 5
#define no_fork 5
sem_t forks[no_fork];
pthread_t th[no_ph];
void *fun(void *x);
main()
{
  int i;
  for(i=0;i<no_fork;i++)
  {
    sem_init(&forks[i],0,1);
  }
  for(i=0;i<no_ph;i++)
  {
    pthread_create(&th[i],NULL,fun,(void *)&i);
  }
  for(i=0;i<no_ph;i++)
  {
    pthread_join(th[i],NULL);
  }
  return 0;
}
void *fun(void *x)
{
  int i=*(int *)x;
  int t=10;
  while(t--)
  {
    sem_wait(&forks[i]);
    sem_wait(&forks[(i+1)%no_ph]);
    printf("Philospher %d is eating...\n",i);
     sleep(1);
    printf("Philospher %d finish eating....\n",i);
    sem_post(&forks[(i+1)%no_ph]);
    sem_post(&forks[i]);
  }
  return;
}