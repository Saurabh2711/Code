#include<stdio.h>
#include<string.h>
int ct=0;
int check(char *str,int s,int e);
main()
{
  int t,s,e;
  char str[100002];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",str);
    ct=0;
    if(check(str,0,strlen(str)-1))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
int check(char *str,int s,int e)
{
  if(s>e)
    return 1;
  if(str[s]==str[e])
  {
    return check(str,s+1,e-1);
  }
  else
  {
    ct++;
    if(ct>1)
      return 0;
    int x=check(str,s+1,e);
    int y=check(str,s,e-1);
    if(x==1 && y==1)
      return 1;
    else if(x^y)
    {
      ct--;
      return 1;
    }
  }
  return 0;
}