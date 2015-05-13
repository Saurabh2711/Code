#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#define s_in(a) scanf("%s",a)
#define s_out(a) printf("%s\n",a)
#define in(a) scanf("%d",&a)
#define out(a) printf("%d\n",a)
typedef long long int ll;
using namespace std;
struct node {
  int min;
  int max;
  int best;
  struct node *left;
  struct node *right;
};
struct node *create_node(int a)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp.min=a;
  temp.max=a;
  temp.best=a;
  temp.left=NULL;
  temp.right=NULL;
  return temp;
}
struct node *initialize(int *arr,int *M,int b,int e,int state)
{
  struct node *node;
  if(b==e)
  {
    node=create_node(arr[b]);
    return node;
  }
  node.left=initialize(arr,M,b,(b+e)/2,2*state);
  node.right=initialize(arr,M,(b+e)/2+1,e,2*state+1);
  node.min=min(node.left.min,node.right.min);
  mode.max=max(node.left.max,node.right.max);
  node.best=max(node.left.best,max(node.right.best,node.right.max-node.left.min));
  return node;
}
int querry(int *arr,int *M,int b,int e,int i,int j,int state)
{
  if(j<b || i>e)
    return INT_MIN;
  if(i<=b && j>=e)
    return M[state];
  int x=querry(arr,M,b,(b+e)/2,i,j,2*state);
  int y=querry(arr,M,(b+e)/2+1,e,i,j,2*state+1);
  if(x==INT_MIN)
    return M[state]=y;
  if(y==INT_MIN)
    return M[state]=x;
  if(x>=y)
    return M[state]=x;
  else
    return M[state]=y;
}
main()
{
  int n,m,x,y;
  int arr[1000];
  cin>>n;
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int M[4*(int)log2(n)+1];
  initialize(arr,M,0,n-1,1);
  cin>>m;
  while(m--)
  {
    cin>>x>>y;
    int q=querry(arr,M,0,n-1,x-1,y-1,1);
    cout<<q<<endl;
  }
  return 0;
}