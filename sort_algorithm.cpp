#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	
	int t,a[1005],b[1005];
	scanf("%d",&t);
	while(t--)
	{
		int n,sum;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		sum=0;
		for(int i=0;i<n;++i)
			sum+=a[i]*b[i];
		printf("%d\n",sum);
	}

	return 0;
}