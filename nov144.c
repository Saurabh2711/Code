#include<stdio.h>
#include<stdlib.h>
int min(int x,int y)
{
  return (x<y)?x:y;
}
int ans_pow[500][500];
int ans[500][500];
main()
{
  int t,n,m,q,i,r,j;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<500;i++)
    {
      
      for(j=0;j<500;j++)
      {
	ans[i][j]=-1;
	ans_pow[i][j]=-1;
      }
    }
    for(i=0;i<q;i++)
    {
      scanf("%d",&r);
      printf("%d\n",find_ans(n,r,m));
    }
  }
  return 0;
}
int find_ans(int n,int r,int m)
{
  r=min(r,n-r);
  if(ans[n][r]!=-1)
    return ans[n][r];
  if(r==1)
    return (ans[n][r]=calculate_pow(n,n,m));
  else
    return (ans[n][r]=(find_ans(n-1,r,m)+find_ans(n-1,r-1,m))%m);
}
int calculate_pow(int x,int y,int m)
{
  if(ans_pow[x][y]!=-1)
    return ans_pow[x][y];
    int temp;
    if( y == 0)
        return 1;
    temp = calculate_pow(x, y/2,m);
    if (y%2 == 0)
        ans_pow[x][y]=(temp*temp)%m;
    else
        ans_pow[x][y]=(x*temp*temp)%m;
    printf("%d %d = %d\n",x,y,ans_pow[x][y]);
    return ans_pow[x][y];
  
}