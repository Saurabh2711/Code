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

ll power(ll n)
{
  if(n==0)
    return 1;
  if(n==1)
    return 2;
  ll x=n/2;
  x=power(x)%mod;
  if(n%2==0)
    return (x*x)%mod;
  else
    return (((x*x)%mod)*2)%mod;
}
main()
{
  int t,n;
  ll arr[100002],ans;
  input(t);
  while(t--)
  {
    input(n);
    for(int i=0;i<n;++i)
      input(arr[i]);
    sort(arr,arr+n);
    ans=0;
    for(int i=0;i<n;++i)
    {
      ans=(ans+((((power(i)%mod)-(power(n-i-1)%mod))%mod)*arr[i])%mod)%mod;
    }
    printf("%lld\n",ans);
  }
  return 0;
}