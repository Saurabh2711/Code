#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
main()
{
  int t,n,a;
  vector<int> v;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    v.clear();
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a);
      v.push_back(a);
    }
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++)
      printf("%d ",v[i]);
    printf("\n");
   
    int end=n-1;
    int flag=0;
    while(n-- && end>=0)
    {
      if(flag)
	break;
      int length=v[end];
      if(length==0)
	break;
      /*
      printf("length %d\n",length);
	for(int x=0;x<v.size();x++)
	  printf("%d ",v[x]);
	printf("\n");
	*/
      int i;
      for(i=end-1;--v[end]>=0 && i>=0;i--)
      {
	v[i]--;

	printf("length %d\n",length);
	for(int x=0;x<v.size();x++)
	  printf("%d ",v[x]);
	printf("\n");

	if(v[i]<0)
	{
	  flag=1;
	  break;
	}  
      }
      if(v[i+1]==0)
	end=i;
      else
	end--;
    }
    if(flag)
      cout<<"SAD\n";
    else
      cout<<"HAPPY\n";
  }
  return 0;
}
