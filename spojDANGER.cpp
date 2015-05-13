#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
main()
{
  int x,y,n,c;
  scanf("%de%d",&x,&y);
  while(x!=0 || y!=0)
  {
    c=1;
    n=x*pow(10,y);
     while (c<=n)
         c<<=1;
     c>>=1;
    printf("%d\n",1+(n-c)*2);
    scanf("%de%d",&x,&y);
  }
  return 0;
}