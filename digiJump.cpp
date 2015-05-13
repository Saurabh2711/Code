#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int find_ans(int s);
char str[100005];
int N;
vector<int> v[10];
main()
{
  
  scanf("%s",str);
  N=strlen(str);
  for(int i=0;i<N;i++)
    v[str[i]-'0'].push_back(i);
  printf("%d\n",find_ans(str[0]-'0'));
  return 0;
}
int find_ans(int s)
{
  /*
  for(int i=0;i<10;i++)
  {
    cout<<i<<" : ";
    for(int j=0;j<v[i].size();j++)
      cout<<v[i][j]<<" ";
    cout<<"\n";
  }
  */
  vector<bool> visited(100005,false);
  vector<int> level(100005,0);
  queue<int> q;
  q.push(s);
//   cout<<"s : "<<s<<endl;
  visited[s]=true;
  level[s]=0;
  while(!q.empty())
  {
    int idx=q.front();
    int l=level[idx];
    if(idx==N-1)
      return l;
    q.pop();
    int val=str[idx]-'0';
    int sz=v[val].size();
    for(int i=0;i<sz;i++)
    {
      int nidx=v[val][i];
      if(!visited[nidx])
      {
	visited[nidx]=true;
	q.push(nidx);
	level[nidx]=l+1;
      }
    }
//     cout<<"val : "<<val<<endl;
    v[val].clear();
    if(idx-1>=0 && !visited[idx-1])
    {
      level[idx-1]=l+1;
      q.push(idx-1);
      visited[idx-1]=true;
    }
    if(idx+1<N && !visited[idx+1])
    {
      level[idx+1]=l+1;
      q.push(idx+1);
      visited[idx+1]=true;
    }
  }
}