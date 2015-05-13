#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
  return a>b?a:b;
}
int arr[101][101];
main()
{
  int t,r,c,i,j;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
	scanf("%d",&arr[i][j]);
      }
    }
    for(i=r-2;i>=0;i--)
    {
      for(j=0;j<c;j++)
      {
	if(j==0)
	{ 
	  arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
	  continue;
	}
	if(j==c-1)
	{ 
	  arr[i][j]+=max(arr[i+1][j],arr[i+1][j-1]);
	  continue;
	}
	arr[i][j]+=max(max(arr[i+1][j-1],arr[i+1][j]),arr[i+1][j+1]);
      }
    }
    int ans=-1;
    for(i=0;i<c;i++)
    {
      ans=arr[0][i]>ans?arr[0][i]:ans;
    }
    printf("%d\n",ans);
  }
  return 0;
}