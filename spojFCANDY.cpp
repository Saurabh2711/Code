#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100000];
int n;
int fun(int i);
main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("%d\n",fun(0));
}
int fun(int i)
{
  if(i==n)
    return 0;
  return min(fun(i+1)+arr[i],fun(i+1)-arr[i]);
}