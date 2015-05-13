#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int gcd(int a,int b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}
int mod(string str,int n)
{
  int r=0,l=str.length();
  for(int i=0;i<l;i++)
  {
    r=10*r+str[i]-'0';
    r=r%n;
  }
  return r;
}
main()
{
  int n,t;
  string str;
  cin>>t;
  while(t--)
  {
    cin>>n>>str;
    if(n==0)
      cout<<str<<endl;
    else
      cout<<gcd(n,mod(str,n))<<endl;
  }
  return 0;
}
