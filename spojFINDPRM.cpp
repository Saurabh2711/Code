#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define max_ 10000001
typedef long long int ll;
using namespace std;
int sp[max_];
bool v[max_]={false};
void sieve()
{
  sp[2]=2;
  for(ll i=3;i<max_;i=i+2)
  {
    if(!v[i])
    {
      sp[i]=i;
      for(ll j=i;j*i<max_;j=j+2)
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
  sieve();
  int t;
  scanf("%d",&t);
  while(t--)
  {
   int n;
   scanf("%d",&n);
   int count=0;
   int m=(n%2==0)?n-1:n;
  for(int i=m;i>n/2;i=i-2)
  {
   // bool flag=true;
    if(sp[i]==i)
    {
      count++;
    }
  }
  if(n<4)
    count++;
  printf("%d\n",count);
  }
  return 0;
}