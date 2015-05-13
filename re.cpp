#include <bits/stdc++.h>
#define getcx getchar_unlocked
using namespace std;
inline void finp(unsigned long long int *a )
{
int n=0; int ch = getcx(); int sign = 1;
while(ch < '0' || ch > '9')
{
if(ch == '-') sign=-1; ch = getcx();
}
while(ch >= '0' && ch <= '9')
{
n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
}
*a = n * sign;
}
unsigned long long int a[1000000];
unsigned long long int n,k,i,sum,ksum;
bool flag;
int main()
{
unsigned long long int t;
finp(&t);
while (t--)
{
n=k=0;
finp(&n);
finp(&k);
for(i=0;i<k;i++)
{
finp(&a[i]);
}
sort(a,a+k);
sum = 0, ksum = 0;
flag = false;
sum = (a[0]*(a[0]-1))/2;
for(i=0;i<k;i++)
{
sum = a[i]*(a[i]-1)/2 - ksum;
ksum += a[i];
if(sum < a[i])
{
if(a[i]&1)
cout << "Chef" << endl;
else
cout << "Mom" <<endl;
flag = true;
break;
}
}
if(!flag)
{ sum = ((n*(n+1))/2)-ksum;
// cout << sum <<" " << ksum<<endl;

if(sum&1)
cout << "Mom"<<endl;
else
cout << "Chef"<<endl;
}
}
return 0;
}