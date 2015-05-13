#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<utility>
typedef long long int ll;
using namespace std;
ll arr[100001],sum[100001],brr[100001];
ll find_t(ll *arr,ll n)
{
  ll res=1;
  for(int i=0;i<n && arr[i]<=res;i++)
  {
    res+=arr[i];
  }
  return res;
}
main()
{
  int t;
  ll n,m;
  cin>>t;
  while(t--)
  {
  cin>>n>>m;
  if(m==0)
  {
    if(((n*(n+1))/2+1)%2==0)
    {
      cout<<"Mom\n";
    }
    else
    {
    cout<<"Chef\n";
    }
    continue;
  }
  for(int i=0;i<m;i++)
  {
    cin>>arr[i];
  }
    sort(arr,arr+m);
    int j=0,k=0;
    for(int i=1;i<=n;i++)
    {
      if(arr[j]!=i)
      {
	brr[k++]=i;
      }
      else{
	j++;
      }
    }
    int x=find_t(brr,n-m);
    cout<<x<<endl;
    if(x%2==0)
    {
      cout<<"Mom\n";
    }
    else
    {
      cout<<"Chef\n";
    }
  }
return 0;
}