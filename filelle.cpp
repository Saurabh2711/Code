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
  
  for(ll i=2;i<(max_);i=i+2)
    sp[i]=2;
  for(ll i=3;i<(max_);i=i+2)
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
  FILE *fp=fopen("file1.txt","w");
  fprintf(fp,"{ %d",sp[2]);
  for(int i=3;i<max_;i=i+2)
  {
    if(sp[i]==i)
    fprintf(fp,",%d",sp[i]);
  }
  fprintf(fp,"}");
  return 0;
}


