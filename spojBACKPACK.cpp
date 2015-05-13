#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
  int val;
  int imp;
  int flag;
  struct node *left;
  struct node *right;
};
int mem[63][32004];
struct node *create_node(int val,int imp)
{
  struct node * temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->val=val;
  temp->imp=imp;
  temp->flag=0;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
int n;
int fun(int ,int);
vector<struct node *> vect;
main()
{
  int t,w,v,imp,p;
  scanf("%d",&t);
  while(t--)
  {
    vect.clear();
    scanf("%d%d",&w,&n);
    for(int i=0;i<n;i++) 
    {
      scanf("%d%d%d",&v,&imp,&p);
      if(p==0)
      {
	vect.push_back(create_node(v,imp));
      }
      else
      {
	if(vect[p-1]->flag==0)
	{
	  vect[p-1]->left=create_node(v,imp);
	  vect[p-1]->flag=1;
	}
	else
	{
	  vect[p-1]->right=create_node(v,imp);
	}
      }
    }
    
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=w;j++)
	mem[i][j]=-1;
    }
    n=vect.size();
   cout<<fun(0,w)<<endl;
  }
}
int fun(int node,int w)
{
  int m,l,r;
  if(node>=n)
    return 0;
  if(mem[node][w]!=-1)
  {
    return mem[node][w];
  }
  int ans=fun(node+1,w);
  if((m=w-vect[node]->val)>=0)
  {
    ans=max(ans,fun(node+1,m)+(vect[node]->val)*(vect[node]->imp));
    
    if(vect[node]->left!=NULL)
    {
      l=m-vect[node]->left->val;
      if(l>=0)
      {
	ans=max(ans,fun(node+1,l)+(vect[node]->left->val)*(vect[node]->left->imp)+fun(node+1,m));
      }
    }
    if(vect[node]->right!=NULL)
    {
      r=m-vect[node]->right->val;
      if(r>=0)
      {
	ans=max(ans,fun(node+1,m)+fun(node+1,r)+(vect[node]->right->val)*(vect[node]->right->imp));
      }
    }
    if((vect[node]->left!=NULL) && (vect[node]->right!=NULL))
    {
      if(l>=0 && r>=0)
      {
	ans=max(ans,fun(node+1,l)+(vect[node]->left->val)*(vect[node]->left->imp)+fun(node+1,r)+(vect[node]->right->val)*(vect[node]->right->imp));
      }
    }
  }
  return mem[node][w]=ans;
}