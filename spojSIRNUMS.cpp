#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
main()
{
  int t,n,x;
  cin>>t;
  char arr[1000009];
  while(t--)
  {
    scanf("%d%d",&n,&x);
    int carry=0;
    bool flag=false;
    for(int i=x;i<=9;i++)
    {
      arr[n-1]=i+'0';
      carry=0;
      for(int j=n-2;j>=0;j--)
      {
	int in=((arr[j+1]-'0')*x+carry);
	arr[j]=in%10+'0';
	carry=in/10;
      }
    //  cout<<arr<<"\n";
      if((arr[0]-'0')*x+carry==i)
      {
	flag=true;
	break;
      }
    }
    if(flag)
    {
      arr[n]='\0';
      cout<<arr<<"\n";
    }
    else
    {
      cout<<"Impossible\n";
    }
  }
  return 0;
}