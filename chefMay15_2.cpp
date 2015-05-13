//Saurabh Uttam
//use '\n' insted of endl
//use ++i than i++ , if possible
//  use call by reference to avoid copy
 
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
using namespace std;
//---------for unix only------------
 
inline void input( ll &n )
{
    n=0;
    ll ch=getcx();
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
 
ll arr[100002];
main()
{
	int t,n,i,j;
	ll diff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%lld",&arr[i]);
		}
		sort(arr,arr+n);
		diff=0;
		for(i=0;i<n-1;++i)
		{
			for(j=i+1;j<n;++j)
			{
				diff=(diff+((arr[j]-arr[i])*((1<<(j-i-1))%1000000007))%1000000007)%1000000007;
			}
		}
		printf("%lld\n",diff);
	}
	return 0;
}