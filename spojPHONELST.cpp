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
#define s_in(a) scanf("%s",a)
#define s_out(a) printf("%s\n",a)
#define in(a) scanf("%d",&a)
#define out(a) printf("%d\n",a)
typedef long long int ll;
using namespace std;
struct node {
  bool flag;
  struct node *arr[10];
};
bool insert(char *str,struct node *ptr,int start,int len);
struct node *create_node();
main()
{
  int t,n;
  char str[15];
  in(t);
  struct node *root;
  while(t--)
  {
      in(n);
      root=create_node();
      bool flag=true;
      for(int i=0;i<n;i++)
      {
	s_in(str);
	bool b=insert(str,root,0,(int)strlen(str));
	if(!b)
	{
	  flag=false;
	}
      }
      if(flag)
      {
	printf("YES\n");
      }
      else
      {
	printf("NO\n");
      }
  }
  return 0;
}
struct node *create_node()
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->flag=false;
  for(int i=0;i<10;i++)
    temp->arr[i]=NULL;
  return temp;
}
bool insert(char *str,struct node *ptr,int start,int len)
{
  while(start<len)
  {
    if(ptr->arr[str[start]-'0']==NULL)
    {
      if(start==(len-1))
      {
	 ptr->flag=true;
      }
      struct node *temp=create_node();
      ptr->arr[str[start]-'0']=temp;
      ptr=temp;
    }
    else
    {
      if(start==(len-1))
	return false;
      if(ptr->flag==true)
      {
	return false;
      }
      ptr=ptr->arr[str[start]-'0'];
    }
    start++;
  }
  return true;
}