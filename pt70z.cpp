#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<utility>
#include<cstdio>
using namespace std;
vector<int> v[10002];
pair<int,int> bfs(int s);
main()
{
  int n,s,d;
  scanf("%d",&n);
  n--;
  while(n--)
  {
    scanf("%d%d",&s,&d);
    v[s].push_back(d);
    v[d].push_back(s);
  }
  pair<int,int> p=bfs(1);
//   cout<<p.first<<"  "<<p.second<<endl;
  p=bfs(p.first);
  printf("%d\n",p.second);
  return 0;
}
pair<int,int> bfs(int s)
{
  pair<int,int> p;
  vector<bool> visited(10002,false);
  queue< pair<int,int> > q;
  q.push( make_pair(s,0));
  visited[s]=true;
  while(!q.empty())
  {
    p=q.front();
    q.pop();
    int l=p.second;
    int x=p.first;
    int si=v[x].size();
    for(int i=0;i<si;i++)
    {
      int m=v[x][i];
      if(!visited[m])
      {
	q.push(make_pair(m,l+1));
	visited[m]=true;
      }
    }
  }
  return p;
}