#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int phi(int n)
{
  int p=1;
  int m=2;
  int x=n;
  bool flag=false;
  while(n>1)
  {
    while(n%m==0)
    {
      n=n/m;
      flag=true;
    }
    if(flag)
    {
      x=x-x/m;
      flag=false;
    }
    m++;
  }
  return x;
}
int pow_(int a,int b,int m)
{
  if(b==0)
    return 1;
  int x=pow_(a,b/2,m);
  if(b%2==0)
    return (x*x)%m;
  else
    return (x*x*a)%m;
}
int inverse(int e,int base)
{
  int ph=phi(base);
  return pow_(e,ph-1,base);
}
bool isprime(int n)
{
int x=sqrt(n);
for(int i=2;i<=x;i++)
{
if(n%i==0)
return false;
}
return true;
}
void rsa(string str)
{
 
  
}
int gcd(int a,int b)
{
if(b==0)
return a;
return gcd(b,a%b);
}
bool coprime(int a,int b)
{
 if(gcd(a,b)==1)
	return true;
return false;
}
main()
{
   int p,q,e,d;
   cin>>p>>q>>e;
   string str;
  int n=p*q;
  int ph=(p-1)*(q-1);
   d=inverse(e,ph);
 // cout<<p<<" "<<q<<" "<<e<<" "<<d<<endl;
  cin>>str;
  int temp[100];
  int l=str.length();
  for(int i=0;i<l;i++)
  {
    temp[i]=pow_(str[i]-'a',e,n);
  }
  printf("\nDecrypted :\n");
  for(int i=0;i<l;i++)
  printf("%c",temp[i]+'a');
  printf("\nEncrypted :\n");
  for(int i=0;i<l;i++)
  printf("%c",pow_(temp[i],d,n)+'a');
  cout<<endl;
}