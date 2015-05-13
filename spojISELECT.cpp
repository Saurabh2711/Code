#include<cstdio>
#include<iostream>
using namespace std;
int fun_take(bool tof,int energy,int i,bool f);
int a[1001],b[1001];
int n;
main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
      scanf("%d",&b[i]);
    }
    if(n==1)
      printf("%d\n",a[0]);
    else
    printf("%d\n",max(fun_take(true,a[0],0,true),fun_take(false,-1*b[0],0,false)));
  }
  return 0;
}
int fun_take(bool tof,int i,bool f)
{
  if(i+1==n)
    return 0;
  if(i+1==n-1)
  {
    if(f==true)
    {
      return -b[n-1];
    }
  }
  if(tof==true)
  {
    return fun_take(false,i+1,f)-b[i+1];
  }
  else
  {
    return max(fun_take(true,i+1,f)+a[i+1],fun_take(false,i+1,f)-b[i+1]);
  }
}

