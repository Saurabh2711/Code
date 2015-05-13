#include<bits/stdc++.h>
using namespace std;
int ct;
#define max 1002
int graph[max][max];
int bfs(int s,int n)
{
  int x;
  ct=0;
  vector<int> visited(max,0);
  queue<int> q;
  q.push(s);
  visited[s]=1;
  while(!q.empty())
  {
    x=q.front();
    cout<<"x= "<<x<<endl;
    q.pop();
    if(q.empty())
    {
    ct++;
    cout<<ct<<endl;
    }
    for(int i=1;i<=n;i++)
    {
      if(graph[x][i]==1 && !visited[i])
      {
	q.push(i);
	visited[i]=1;
      }
    }
  }
  return x;
}
main()
{
  int n,s,d;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    cin>>s>>d;
    graph[s][d]=1;
  }
  int x=bfs(1,n);
  cout<<"end"<<endl;
  bfs(x,n);
  cout<<ct+1<<endl;
  return 0;
}
