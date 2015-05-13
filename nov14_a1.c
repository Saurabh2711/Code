#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 26
main()
{
  int t;
  char str[100003];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",str);
    printf("%d\n",find_largest(str));
  }
  return 0;
}
int find_largest(char *str)
{
  int arr[max],i,ct=0;
  for(i=0;i<26;i++)
    arr[i]=-1;
  int l=strlen(str);
  int largest=INT_MIN;
  for(i=0;i<l;i++)
  {
    if(arr[str[i]-'a']==-1)
    {
      arr[str[i]-'a']=1;
      ct++;
    }
  }
  return ct;
}