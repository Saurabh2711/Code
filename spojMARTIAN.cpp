#include<cstdio>
#include<algorithm>
#define LEFT 0
#define UP 1
using namespace std;
int y[501][501],b[501][501];
int mem[2][501][501];
int n,m;
int fun(int i,int j);
main()
{
  scanf("%d%d",&n,&m);
  while(n!=0 && m!=0)
  {
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
	scanf("%d",&y[i][j]);
	mem[LEFT][i][j]=-1;
	mem[UP][i][j]=-1;
      }
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
	scanf("%d",&b[i][j]);
     for(int i=0;i<n;i++)
      for(int j=1;j<m;j++)
	y[i][j]+=y[i][j-1];
     for(int j=0;j<m;j++)
       for(int i=1;i<n;i++)
	 b[i][j]+=b[i-1][j];
/*
       printf("----------\n");
       for(int i=0;i<n;i++)
       {
      for(int j=0;j<m;j++)
	printf("%d ",y[i][j]);
      printf("\n");
       }
       printf("----------\n");
       for(int i=0;i<n;i++)
       {
      for(int j=0;j<m;j++)
	printf("%d ",b[i][j]);
      printf("\n");
       }
       */
/*
     int row=n-1,col=m-1;
    int ans=0;   
    while(row>=0 && col>=0)
       {
	 if(y[row][col]>b[row][col])
	 {
	   ans+=y[row][col];
// 	   printf("%d %d = %d\n",row,col,y[row][col]);
	   row--;
	 }
	 else
	 {
	   ans+=b[row][col];
// 	   printf("%d %d = %d\n",row,col,b[row][col]);
	   col--;
	 }
	 
       }
       */
       printf("%d\n",fun(n-1,m-1));
       scanf("%d%d",&n,&m);
  }
  return 0;
}
int fun(int i,int j)
{
 if(i<0 || j<0)
   return 0;
 if(mem[LEFT][i][j]==-1)
   mem[LEFT][i][j]=fun(i-1,j)+y[i][j];
 if(mem[UP][i][j]==-1)
   mem[UP][i][j]=fun(i,j-1)+b[i][j];
 return max(mem[LEFT][i][j],mem[UP][i][j]);
}