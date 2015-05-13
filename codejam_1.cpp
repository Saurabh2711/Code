#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
main()
{
  int t,r,c,w,ans;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&r,&c,&w);
    ans=(r-1)*(ceil(c/w));
    for(int i=0;i<(w-1);i++)
    {
      if(i+w<c)
	ans+=1;
    }
    ans+=(w);
    cout<<ans<<endl;
  }
  
  
}