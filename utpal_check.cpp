#include<bits/stdc++.h>
#define maxi 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll ans[maxi-1];
ll t,n;

ll arr[maxi-1];

void pre()
{
	ans[0]=1;
	ans[1]=2;

	for(int i=2;i<maxi;i++)
	{
		ans[i]=(ans[i-1]*2)%mod;
	}
}
ll a;
int main()
{
	pre();
	cin >> t;
	while(t--)
	{
		a=0;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		sort(arr,arr+n);

        for(int i=0;i<n;i++)
        {
            a+=(ans[i]*arr[i])%mod;             
        }



        for(int i=0;i<n;i++)
        {
        	a-=(arr[i]*ans[n-i-1])%mod;      	
        }

       cout<<a<<endl;

	}
	return 0;
}