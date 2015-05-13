#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
#define max 10000001
bool v[max]={false};
int sp[max];
void seive()
{
  for(int i=2;i<max;i++)
  {
    sp[i]=2;
  }
  for(long long int i=3;i<max;i=i+2)
  {
    if(!v[i])
    {
      sp[i]=i;
      for(long long int j=i;j*i<max;j=j+2)
      {
	if(!v[i*j])
	{
	  sp[i*j]=i;
	  v[i*j]=true;
	}
      }
    }
  }
}
main()
{
  seive();
  int n;
  while(scanf("%d",&n)>0)
  {
    printf("1");
    while(n>1)
    {
      int x=sp[n];
      while(n%x==0)
      {
	printf(" x %d",x);
	n=n/x;
      }
    }
   printf("\n");
  }
  return 0;
}