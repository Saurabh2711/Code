#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
int number(int *arr);
int solve(int *arr,int n,int k,int nb);
int fun(int *bit_arr,int nb,int x);
vector<int> v[20];
main()
{
  int n,t,arr[100001],k;
  scanf("%d",&t);
  int largest;
  while(t--)
  {
    scanf("%d%d",&n,&k);
    largest=INT_MIN;
    for(int i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
      largest=(arr[i]>largest)?arr[i]:largest;
    }
//       printf("l= %d\n",largest);
    printf("%d\n",solve(arr,n,k,floor(log2(largest))+1));
  }
  return 0;
}
int solve(int *arr,int n,int k,int nb)
{
  int bit_arr[20];
  memset(bit_arr,0,sizeof(int)*20);
  int m=k;
  int i=0;
  while(m>0)
  {
    bit_arr[i++]=m%2;
    m=m/2;
  }
  for(i=0;i<20;i++)
  v[i].clear();
  for(i=0;i<n;i++)
  {
    if(arr[i]==1)
    {
      v[1].push_back(1);
    }
    else
    {
      v[(int)floor(log2(arr[i]))+1].push_back(arr[i]);
    }
  }
  int ans=max(k,fun(bit_arr,nb,floor(log2(k))+1));
  return ans;
}
int fun(int *bit_arr,int nb,int x)
{
  /*
  printf("nb = %d x =  %d\n",nb,x);
  printf("%d\t ",nb);
  for(int i=0;i<10;i++)
    printf("%d ",bit_arr[i]);
  printf("\n");
  */
  if(nb==x)
    return fun(bit_arr,nb-1,x);
  if(nb==0)
  {
    return number(bit_arr);
  }
//   printf("Hello\n");
  int arr[20];
  int ans=INT_MIN;
  for(int j=0;j<12;j++)
    arr[j]=bit_arr[j];
  for(int i=0;i<v[nb].size();i++)
  {
    for(int j=0;j<12;j++)
    arr[j]=bit_arr[j];
    int m=v[nb][i];
    int k=0;
    while(m>0)
    {
      arr[k++]+=m%2;
      m=m/2;
    }
    ans=max(ans,fun(arr,nb-1,x));
  }
  
  return max(ans,number(arr));
}
int number(int *arr)
{
  int num=0;
  for(int i=0;i<12;i++)
  {
    num+=pow(2,i)*(arr[i]%2);
  }
  return num;
}