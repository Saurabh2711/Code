#include<cstdio>
#include<set>
using namespace std;
main()
{
  int t;
  int n;
  set<int> s;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    s.erase();
    while(n--)
    {
      scanf("%d",&a);
      s.push_back(a);
    }
    printf("%d\n",s.size());
  }
  return 0;
}