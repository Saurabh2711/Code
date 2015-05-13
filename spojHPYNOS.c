#include<stdio.h>
#include<stdlib.h>
int fun(int n)
{
  int ans=0,rem;
  while(n>0)
  {
    rem=n%10;
    ans+=rem*rem;
    n/=10;
  }
  return ans;
}
main()
{
  int hash[1000]={0};
  int n,i;
  scanf("%d",&n);
  int ans=n;
  int count=0;
  while(1)
  {
    ans=fun(ans);
    count++;
    if(hash[ans]==1)
    {
      printf("-1\n");
      return 0;
    }
//     printf("ans %d\n",ans);
    if(ans==1)
    {
      printf("%d\n",count);
      return 0;
    }
    hash[ans]=1;
  }
  return 0;
}