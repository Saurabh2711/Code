#include<iostream>
#include<cmath>
#include<cstdlib>
typedef long long int ll;
using namespace std;
int phi(int n)
{
	int result=n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n/=i;
			result-=result/i;
		}
		
	
	}
	if(n>1)
		result-=result/n;
	return result;
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int power(int b,int p,int m)
{
	if(p==0)
	return 1;
	if(p==1)
		return b;
	if(p%2==0)
	{
		return (power(b,p/2,m)*power(b,p/2,m))%m;
	}
	else
	{
		return ((b*((power(b,p/2,m)*power(b,p/2,m))%m))%m);
	}
}
int inverse(int x,int m)
{
	if(gcd(x,m)!=1)
		exit(0);
 	return power(x,phi(m)-1,m);
}
main()
{
	ll n,m,p,q;
	cin>>p;
	cin>>q;
	n=p*q;
	m=phi(n);
//	cout<<phi(n)<<endl;
//	cout<<inverse(n,m)<<endl;
	ll e;
	for(int i=2;i<m;i++)
	{
		ll x=gcd(i,m);
		if(x==1)
		{
		e=i;
			break;
	}	}
	ll num[100],nu,t;
	string msg;
	ll d=inverse(e,m);
	cin>>msg;
	for(int i=0;i<msg.length();i++)
	num[i]=power(msg[i],e,n);
	for(int i=0;i<msg.length();i++)
		cout<<char(num[i]);
	cout<<endl;
	for(int i=0;i<msg.length();i++)
	cout<<char(power(num[i],d,n));
	cout<<endl;
	cout<<endl;
}
