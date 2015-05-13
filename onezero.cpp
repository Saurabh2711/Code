#include<iostream>
#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
int n;
string find_ans(string str,int rem);
main()
{
  int t;
  string str;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    str="1";
    cout<<find_ans(str,1)<<endl;
  }
  return 0;
}
string find_ans(string str,int rem)
{
  queue< pair<string ,int> > q;
  q.push(make_pair(str,rem));
  pair<string ,int > p;
  while(!q.empty())
  {
    p=q.front();
    q.pop();
    if(p.second%n==0)
      return p.first;
    q.push(make_pair(p.first+'0',(rem*10)%n));
    q.push(make_pair(p.first+'1',(rem*10+1)%n));
  }
  return p.first;
}