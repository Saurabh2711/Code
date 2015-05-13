#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[501];
int cnt[501];
main()
{
  int t,n,m,a,b;
  scanf("%d",&t);
  for(int i=1;i<=t;i++)
  {
    scanf("%d%d",&n,&m);
    memset(arr,0,sizeof(int)*(n+1));
    for(int j=0;j<m;j++)
    {
      scanf("%d%d",&a,&b);
      arr[a]++;
      arr[b]++;
    }
    int flag=0;
    int count_4=0;
    int count_3=0;
    int count_2=0;
    for(int j=1;j<=n;j++)
    {
      if(arr[j]==2)
      {
	count_2++;
	if(count_2>(n-1))
	  flag=1;
      }
      if(arr[j]==3)
      {
	count_3++;
	if(count_3>1)
	{
	  flag=1;
	  break;
	}
      }
      else if(arr[j]==4)
      {
	count_4++;
	if(count_4>1)
	{
	  flag=1;
	  break;
	}
      }
      else  if(arr[j]>4)
      {
	  flag=1;
	  break;
      }
    }
   // printf("%d %d\n",count_3,count_4);
    if(flag || (count_3==1 && count_4==1))
      printf("Case %d: NotValid\n",i);
    else if(count_4==1)
      printf("Case %d: X\n",i);
    else if(count_3==1)
      printf("Case %d: Y\n",i);
    else
      printf("Case %d: I\n",i);
  }
  return 0;
}