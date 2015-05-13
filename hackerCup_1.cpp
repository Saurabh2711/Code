#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<utility>
#define MAX 1000000007
typedef long long int ll;
using namespace std;
main()
{
  FILE *in=fopen("input.txt","r"),*out=fopen("out.txt","w");
  int t;
  int c=1;
  char str[12],arr[100];
  fscanf(in,"%d",&t);
  while(t--)
  {
    fprintf(out,"Case #%d: ",c);
    fscanf(in,"%s",str);
    strcpy(arr,str);
    int l=strlen(str);
    int s,e,min;
    bool flag=false;
    for(int i=0;i<=(l-2);i++)
    {
      s=i,e=i,min=arr[i]-'0';
      flag=false;
      for(int j=i+1;j<=(l-1);j++)
      {
	int m=arr[j]-'0';
	if(i==0)
	{
	  if(m!=0)
	  {
	    if(m<=min)
	    {
	      min=m;
	      e=j;
	      flag=true;
	    }
	  }
	}else
	{
	  if(m<=min)
	  {
	    min=m;
	    e=j;
	    flag=true;
	  }
	}
      }
      
      if(flag==true)
      {
	if((arr[s]-'0')!=(arr[e]-'0'))
	{
	char temp=arr[s];
	arr[s]=arr[e];
	arr[e]=temp;
	break;
	}else
	{
	  flag=false;
	}
      }
    }
    fprintf(out,"%s ",arr);
    strcpy(arr,str);
    int max,m;
    for(int i=0;i<=(l-2);i++)
    {
      max=arr[i]-'0',s=i,e=i,flag=false;
      for(int j=i+1;j<=(l-1);j++)
      {
	m=arr[j]-'0';
	if(m>=max)
	{
	 max=m;
	 e=j;
	 flag=true;
	}
      }
      if(flag)
      {
	if((arr[s]-'0')!=(arr[e]-'0'))
	{
	 // cout<<s<<" "<<e<<endl;
	  char temp=arr[e];
	  arr[e]=arr[s];
	  arr[s]=temp;
	  break;
	}
	else
	{
	  flag=false;
	}
      }
    }
    fprintf(out,"%s\n",arr);
    c++;
  }
	return 0;
}

