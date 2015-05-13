#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
int dp[105][105];
int arr[105][105];
int row,col;
int is_safe(int r,int c);
int fun(int sum,int r,int c);
main()
{
  int t,c,r,i,j;
  scanf("%d",&t);
  while(t--)
  {
   scanf("%d%d",&r,&c);
   row=r;
   col=c;
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       scanf("%d",&arr[i][j]);
       dp[i][j]=-1;
     }
   }
   int max=INT_MIN;
   for(i=0;i<c;i++)
   {
     int l=fun(arr[0][i],0,i);
     max=l>max?l:max;
   }
   printf("%d\n",max);
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       printf("%d ",dp[i][j]);
     }
     printf("\n");
   }
  }
  return 0;
}
int fun(int sum,int r,int c)
{
  int max=sum;
  int l;
  if(is_safe(r+1,c-1))
  {
    if(dp[r+1][c-1]!=-1)
      l= dp[r+1][c-1];
    else
    {
    l=fun(sum+arr[r+1][c-1],r+1,c-1);
    dp[r][c]=l>dp[r][c]?l:dp[r][c];
    }
    max=l>max?l:max; 
  }
  if(is_safe(r+1,c))
  {
    if(dp[r+1][c]!=-1)
      l= dp[r+1][c];
    else
    {
    l=fun(sum+arr[r+1][c],r+1,c);
    dp[r][c]=l>dp[r][c]?l:dp[r][c];
    }
    max=l>max?l:max;
  }
  if(is_safe(r+1,c+1))
  {
    if(dp[r+1][c+1]!=-1)
      l= dp[r+1][c+1];
    else
    {
    l=fun(sum+arr[r+1][c+1],r+1,c+1);
    dp[r][c]=l>dp[r][c]?l:dp[r][c];
    }
    max=l>max?l:max;
  }
  return max;
}
int is_safe(int r,int c)
{
  if(r<row && c>=0 && c<col)
    return 1;
  return 0;
}