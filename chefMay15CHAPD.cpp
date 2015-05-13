#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<utility>
#include<cmath>
#define LET(x,a) __typeof(a) x(a)
#define itr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define INF 2147483647
#define LINF 9223372036854775807
#define getcx getchar_unlocked
#define read_line(str) scanf(" %[^\n]s",str)
#define str_itr(x,str) for(int i=x;str[i]!='\0';i++)



typedef long long int ll;
#define mod 1000000007
using namespace std;


inline void input(int &n )
{
    n=0;
    int ch=getcx();
	int sign=1;
    while( ch < '0' || ch > '9' )
	{
		if(ch=='-')
			sign=-1;
		ch=getcx();
	}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}


inline void input(long long int  &n )
{
    n=0;
    int ch=getcx();
	ll sign=1;
    while( ch < '0' || ch > '9' )
	{
		if(ch=='-')
			sign=-1;
		ch=getcx();
	}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}
main()
{
  int t;
  ll a,b;
  input(t);
  while(t--)
  {
    input(a);
    input(b);
    bool flag=true;
    bool stop=true;
    for(ll f=2;f*f<=b;++f)
    {
      while(b%f==0)
      {
	if(flag)
	{
	  if(a%f!=0)
	  {
	    stop=false;
	    break;
	  }
	}
	b/=f;
	flag=false;
      }
      flag=true;
      if(!stop)
      {
	printf("No\n");
	flag=false;
	break;
      }
    }
    if(b>1)
    {
      if(a%b==0)
	printf("Yes\n");
    }
    else if(flag)
    {
      printf("Yes\n");
    }
  }
  return 0;
}