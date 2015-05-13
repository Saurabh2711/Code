#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
sem_t reader_count_block,writer_count_block,;
int count=0;
void *reader()
{
  int t=10;
  while(t--)
  {
  sem_wait(&reader_count_block);
  count++;
  if(count==1)
  sem_wait(&writer_block);
  sem_post(&reader_count_block);
  printf("Reader is Reading.....\n");
  sem_wait(&reader_count_block);
  count--;
  if(count==0)
    sem_post(&writer_block);
  sem_post(&reader_count_block);
  }
}
void *writer()
{
  int t=10;
  while(t--)
  {
  sem_wait(&writer_block);
  printf("Writer is writing ...\n");
  sem_post(&writer_block);
  }
}
main()
{
  sem_init(&reader_count_block,0,1);
  sem_init(&writer_block,0,1);
  pthread_t p_reader,p_writer;
  pthread_create(&p_reader,NULL,reader,NULL);
  pthread_create(&p_writer,NULL,writer,NULL);
  pthread_join(p_reader,NULL);
  pthread_join(p_writer,NULL);
  return 0;
}

