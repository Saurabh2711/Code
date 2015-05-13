#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
void initialize(int *arr,int *M,int b,int e,int node)
{
  if(b==e)
  {
    M[node]=b;
    return;
  }
  initialize(arr,M,b,(e+b)/2,node*2);
  initialize(arr,M,(b+e)/2+1,e,node*2+1);
  if(arr[M[node*2]]<=arr[M[node*2+1]])
  {
    M[node]=M[node*2];
  }
  else
  {
    M[node]=M[node*2+1];
  }
}
int querry(int *arr,int *M,int b,int e,int i,int j,int node)
{
  if(j<b || i>e)
    return -1;
  if(i<=b && j>=e)
  {
    return M[node];
  }
  int x=querry(arr,M,b,(b+e)/2,i,j,node*2);
  int y=querry(arr,M,(b+e)/2+1,e,i,j,node*2+1);
  if(x==-1)
   return M[node]=y;
  if(y==-1)
    return M[node]=x;
  if(arr[x]<=arr[y])
    return M[node]=x;
  else
    return M[node]=y;
}
main()
{
  int n,q,s,e;
  int arr[100];
  cin>>n;
  int M[4*(int)log2(n)+1];
  for(int i=1;i<=4*(int)log2(n)+1;i++)
  {
    M[i]=-1;
  }
  for(int i=0;i<n;i++)
    cin>>arr[i];
  initialize(arr,M,0,n-1,1);
  cin>>q;
  for(int i=1;i<=4*(int)log2(n)+1;i++)
  {
  //  cout<<M[i]<<endl;
  }
  while(q--)
  {
    cin>>s>>e;
    cout<<arr[querry(arr,M,0,n-1,s,e,1)]<<endl;
  }
  return 0;
}