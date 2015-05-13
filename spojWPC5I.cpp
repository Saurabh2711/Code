#include<cstdio>
#include<iostream>
#include<algorithm>
long long int gcd(long long int a,long long int b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}
main()
{
  int t;
  long long int n,m;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld%lld",&m,&n);
    
    long long int x=gcd(n,m);
      n=n/x;
      m=m/x;
      
    printf("%lld\n",(n*m));//gcd(n,m));
  }
  return 0;
}