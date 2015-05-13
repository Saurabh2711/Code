#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
main()
{
  int n;
  string str;
  cin>>n;
  getchar();
  while(n--)
  {
    getline(cin,str);
    cout<<str<<endl;
  }
}