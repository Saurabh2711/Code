#include<cstdio>
#include<algorithm>
#include<climits>
#define TRUE 1
#define FALSE 0
using namespace std;
long long int mem[2][2][10001];
long long int a[10001],b[10001];
long long int fun(int tof,int i,int f);
int n;
main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      mem[0][0][i]=INT_MIN;
      mem[1][0][i]=INT_MIN;
      mem[0][1][i]=INT_MIN;
      mem[1][1][i]=INT_MIN;
    }
    for(int j=0;j<n;j++)
      scanf("%lld",&b[j]);
    printf("%lld\n",max(fun(TRUE,1,TRUE)+a[0],fun(FALSE,1,FALSE)-b[0]));
  }
  return 0;
}
long long int fun(int tof,int i,int f)
{
 if(i>=n)
   return 0;
 if(i==n-1)
 {
   if(f==TRUE)
     return -b[i];
 }
 if(tof==TRUE)
 {
   if(mem[FALSE][f][i]==INT_MIN)
   mem[FALSE][f][i]=fun(FALSE,i+1,f)-b[i];
   return mem[FALSE][f][i];
 }
 if(mem[TRUE][f][i]==INT_MIN)
 mem[TRUE][f][i]=fun(TRUE,i+1,f)+a[i];
 if(mem[FALSE][f][i]==INT_MIN)
 mem[FALSE][f][i]=fun(FALSE,i+1,f)-b[i];
 return max(mem[TRUE][f][i],mem[FALSE][f][i]);
}