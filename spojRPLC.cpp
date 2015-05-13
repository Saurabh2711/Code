#include<cstdio>
#include<iostream>
using namespace std;
main()
{
  int t,n;
  long long int arr[1000001];
  scanf("%d",&t);
  for(int x=1;x<=t;x++)
  {
    scanf("%d",&n);
    long long int ans=1;
    long long int max=1;
    for(int i=0;i<n;i++)
    {
      scanf("%lld",&arr[i]);
      ans+=-1*arr[i];
      if(ans>max)
	max=ans;
    }
    printf("Scenario #%d: %lld\n",x,max);
  }
  
  return 0;
}