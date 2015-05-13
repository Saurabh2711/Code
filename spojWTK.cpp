#include<iostream>
#include<cstdio>
using namespace std;
int fun(int n,int k)
{
  if(n==1)
    return 1;
  return (fun(n-1,k+1)+k)%n+1;
}
main()
{
  int t,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    printf("%d\n",fun(n,0));
  }
}