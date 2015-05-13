#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int ct=0;
bool check(string str,int s,int e);
main()
{
  int t,s,e;
  string str;
  scanf("%d",&t);
  while(t--)
  {
    cin>>str;
    ct=0;
    if(check(str,0,str.size()-1))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
bool check(string str,int s,int e)
{
  if(s>e)
    return true;
  if(str[s]==str[e])
  {
    return check(str,s+1,e-1);
  }
  else
  {
    ct++;
    if(ct>1)
      return false;
    bool x=check(str,s+1,e);
    bool y=check(str,s,e-1);
    if(x==true && y==true)
      return true;
    else if(x^y)
    {
      ct--;
      return true;
    }
  }
  return false;
}