#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
struct node {
  struct node *arr[26];
}*root=NULL;
int count;
struct node *create_node();
void insert(char *,struct node *,int ,bool,int);
main()
{
  FILE *in=fopen("input.txt","r"),*out=fopen("out.txt","w");
  char str[1000002];
  int t,n;
  int c=1;
  fscanf(in,"%d",&t);
  while(t--)
  {
    fscanf(in,"%d",&n);
    count=0;
    root=create_node();
    for(int i=0;i<n;i++)
    {
      fscanf(in,"%s",str);
      int l=strlen(str);
      insert(str,root,0,true,l);
    }
    fprintf(out,"Case #%d: %d\n",c,count);
    c++;
  }
}
struct node *create_node()
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  for(int i=0;i<26;i++)
    temp->arr[i]=NULL;
}
void insert(char *str,struct node *ptr,int start,bool flag,int len)
{
  while(start<len)
  {
  if(ptr->arr[str[start]-'a']==NULL)
  {
    if(flag)
    {
      count++;
      flag=false;
    }
    ptr->arr[str[start]-'a']=create_node();
    ptr=ptr->arr[str[start]-'a'];
  }
  else
    {
      if(flag)
      count++;
      ptr=ptr->arr[str[start]-'a']; 
   }
   start++;
   }
}
