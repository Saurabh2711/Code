#include<stdio.h>
#include<math.h>
main()
{
  int t;
  double l,k;
  scanf("%d",&t);
  double ans;
  while(t--)
  {
    scanf("%lf%lf",&l,&k);
    int lev=floor(log2(k));
    ans=(l*(2*(k-pow(2,lev))+1))/pow(2,lev+1);
    printf("%lf\n",ans);
  }
  return 0;
}
