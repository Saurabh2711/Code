#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define g 9.806
#define PI 2*acos(0.0)
main()
{
  int t;
  float d,s;
  scanf("%d",&t);
  for(int p=1;p<=t;p++)
  {
    scanf("%f%f",&d,&s);
    float si=(g*d)/(s*s);
    float x=((((asin(si)))*180.0)/(PI))/2;
    if(si<=1)
    printf("Scenario #%d: %.2f\n",p,x);
    else
      printf("Scenario #%d: -1\n",p);
  }
  return 0;
}