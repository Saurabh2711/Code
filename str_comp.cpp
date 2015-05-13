#include<iostream>
#include <string>
#include<cstdio>
using namespace std;
string arr[20]={
"S",".","..","...","....","-",". -",".. -","... -",".... -","- -",". - -",".. - -","... - -",".... - -","- - -",". - - -",".. - - -","... - - -",".... - - -"
};

int main()
{

 
      long long n,j=0,x,l,i;
      long long ans;
      string num[7],a;
     
      cin>>n;
      getchar();
      while(n>0)
      {
          for(i=0;i<n;i++)
	  {
	    fflush(stdin);
             getline(cin,num[i]);
	   //  cout<<num[i]<<endl;
          }

            ans=0;x=1;
          for(int j=i-1,l=0;j>=0;j--)
          {
              for(int k=0;k<20;k++)
              {

                  if(arr[k]==num[j] && l==2)
                  {
                      ans+=360*k;
                      l++;
                      x=360*20;
                      //cout<<"a "<<k<<" "<<ans<<endl;
                      break;
                  }
                   //if(strcmp(arr[k],num[j]) && l!=2)
                  if(arr[k]==num[j] && l!=2)
                  {
                      ans+=x*k;
                      x=x*20;
                      l++;
                      // cout<<"b "<<k<<" "<<ans<<endl;
                      break;
                  }
              }
          }
          cout<<ans<<endl;
	  cin>>n;
      }
      return 0;
}
