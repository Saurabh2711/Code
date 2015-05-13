#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 26
int longest_substring(char *str);
main()
{
  int t;
  scanf("%d",&t);
  char str[100003];
  while(t--)
  {
    scanf("%s",str);
    printf("%d\n",longest_substring(str));
  }
  return 0;
}
int longest_substring(char *str)
{
  int arr[max],i,lx,s=0;
  for(i=0;i<max;i++)
    arr[i]=-1;
  int l=strlen(str);
  int largest=INT_MIN;
  for(i=0;i<l;i++)
  {
    if(arr[str[i]-'a']>=s)
    {
      int lx=i-s;
      if(lx>largest)
      {
	largest=lx;
      }
      s=arr[str[i]-'a']+1;
      arr[str[i]-'a']=i;
    }
    else
    {
      arr[str[i]-'a']=i;
    }
  }
  lx=i-s;
  if(lx>largest)
    largest=lx;
  return largest;
}