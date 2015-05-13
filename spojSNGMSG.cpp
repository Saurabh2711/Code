#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char decrypt(char c,int i)
{
  int x=c-'a';
  int rem=x-i;
  if(rem<0)
    c='a'+26+rem;
  else
    c='a'+rem;
  return c;
}
string reverse_str(string str)
{
  string msg="";
  int l=str.length();
  for(int i=l-1;i>=0;i--)
    msg+=str[i];
  return msg;
}
main()
{
  int t;
  cin>>t;
  string str;
  string num;
  while(t--)
  {
    cin>>num;
    cin>>str;
    int count=0;
    int l=str.length();
    string msg="";
    int m=num.length();
    for(int i=0;i<l;)
    {
      for(int j=0;j<m;j++)
      {
	if(i>=l)
	  break;
	msg+=decrypt(str[i++],num[j]-'0');
      }
	num=reverse_str(num);
     // cout<<num<<endl;
    }
    cout<<msg<<endl;
  }
  return 0;
}