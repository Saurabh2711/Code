#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
/*
bool is_perfect_square(long long int n) 
{
    if (n < 0)
        return false;
    long long int root(round(sqrt(n)));
    return n == root * root;
}
*/
main()
{
  int t;
  long long int n;
  scanf("%d",&t);
  for(int x=1;x<=t;x++)
  {
    scanf("%lld",&n);
    double m=sqrt(n);
    if(m==floor(m)*1.00)
      printf("Case %d: Yes\n",x);
    else
      printf("Case %d: No\n",x);
  }
  return 0;
}