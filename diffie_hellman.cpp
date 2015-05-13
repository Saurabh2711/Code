#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int pow_(int a,int b,int m)
{
  if(b==0)
    return 1;
  int x=pow_(a,b/2,m)%m;
  if(b%2==0)
    return (x*x)%m;
  return (b*x*x)%m;
}
main()
{
  time_t t;
  srand((unsigned)time(&t));
  int p,a,b,g;
  cout<<"Enter Common Prime number :";
  cin>>p;
  cout<<"Enter its primitive root :";
  cin>>g;
  a=(rand()+1)%50;
  b=(rand()+2)%50;
  int X,Y;
  cout<<"Alice Sends :"<<(X=pow_(g,a,p))<<endl;
  cout<<"Bob Sends :"<<(Y=pow_(g,b,p))<<endl;
  cout<<"Alice have Key : "<<(X*Y)%p<<endl;
  cout<<"Bob have Key : "<<(X*Y)%p<<endl;
}