#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
using namespace std;
bool flag=true;
int count_black(int ,int);
int count_red(int ,int )
{
  return 1;
}
main()
{
  int q,x,y;
  string var;
  scanf("%d",&q);
  while(q--)
  {
    cin>>var;
   if(var=="Qi")
    {
      flag=!flag;
    }
    else if(var=="Qb")
    {
	scanf("%d%d",&x,&y);
	printf("%d\n",count_black(x,y));
    }
    else if(var=="Qr")
    { 
	scanf("%d%d",&x,&y);
	printf("%d\n",count_red(x,y));
    }
  }
return 0;
}
int count_black(int x,int y)
{
  list<int> ls1;
  list<int> ls2;
  int lx=floor(log2(x));
  int ly=floor(log2(y));
  int count=0;
//   cout<<"lx "<<lx<<endl;
//   cout<<"ly "<<ly<<endl;
  while(lx!=-1)
  {
    if(flag==true)
    {
      if(lx%2==0)
      {
	count++;
	ls1.push_front(lx);
      }
    }
    else
    {
      if(lx%2!=0)
      {
	count++;
	ls1.push_front(lx);
      }
    }
//     cout<<"lx "<<lx<<" count "<<count<<endl;
    lx--;
  }
//   cout<<count<<endl;
  while(ly!=-1)
  {
    if(flag==true)
    {
      if(ly%2==0)
      {
	count++;
	ls2.push_front(ly);
      }
    }
    else
    {
      if(ly%2!=0)
      {
	count++;
	ls2.push_front(ly);
      }
    }
    ly--;
  }
   cout<<count<<endl;
  int temp=0;
  cout<<"f "<<ls1.front()<<endl;
  cout<<"f "<<ls2.front()<<endl;
  while((ls1.front()==ls2.front()) && !ls1.empty() && !ls2.empty())
  {
    temp=ls1.front();
    cout<<"l "<<ls1.front()<<endl;
    ls1.pop_front();
    ls2.pop_front();
    count=count-2;
  }
  cout<<temp<<endl;
  if(flag==true)
  {
    if(temp%2==0)
      count++;
  }
  else
  {
    if(temp%2!=0)
      count++;
  }
  return count;
}