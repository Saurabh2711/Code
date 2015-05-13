#include<iostream>
#include<cstdio>
using namespace std;
long long int fun(long long int n,long long int k)
{
    long long int a=1,i;
    for(i=1;i<=n;i++)
        a=(a+k-1)%i+1;

    return a;
}
main()
{
  long long int t,n,k;
 scanf("%lld%lld",&n,&k);
  while(n!=0 || k!=0)
  {
    printf("%lld %lld %lld\n",n,k,fun(n,k));
    scanf("%lld%lld",&n,&k);
  }
  return 0;
}