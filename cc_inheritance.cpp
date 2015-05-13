#include<iostream>
#include<cstdio>
using namespace std;
class Base{
public :
  virtual void fun()
  {
    cout<<"From Base Class\n";
  }
} ; 
class Derived1 : public Base
{
};
class Derived2 : public Base{

public :
  void fun()
  { 
    cout<<"From D2 Class\n";
  }
  void fun(int a)
  {
    cout<<"This is from D2 with value "<<a<<endl;
  }
};
int main()
{
  Base *B;
  Derived2 D1;
  B=&D1;
  B->fun();
  return 0;
}