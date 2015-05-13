#include<cstdio>
using namespace std;
main()
{
  int t,x,y;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&x,&y);
    if(x%2==0 || y%2==0)
      printf("Suresh\n");
    else
      printf("Ramesh\n");
  }
  return 0;
}