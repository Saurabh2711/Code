#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int find_level(int k);
double find_ans(double n,double k);
main()
{
  int t;
  double n,k;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lf%lf",&n,&k);
    printf("%.8lf\n",find_ans(n,k));
  }
  return 0;
}
double find_ans(double n,double k)
{
  double mid=n/2;
  if(k==1)
    return mid;
  int l=find_level(k);
  double curr=pow(2,l);
  double base=mid/curr;
  double prev=pow(2,l-1);
  double add=mid/prev;
  return (base+(k-curr)*add);
}
int find_level(int k)
{
  if(k==1)
    return 0;
  return find_level(k/2)+1;
}