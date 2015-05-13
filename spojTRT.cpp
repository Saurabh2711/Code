#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int mem[2001][2001];
int arr[2001];
int fun(int year,int s,int e);
main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("%d\n",fun(1,0,n-1));
    return 0;
}
int fun(int year,int s,int e)
{
  if(s>e)
    return 0;
  if(mem[s][e]!=0)
    return mem[s][e];
  return mem[s][e]=max(fun(year+1,s+1,e)+arr[s]*year,fun(year+1,s,e-1)+arr[e]*year);
}