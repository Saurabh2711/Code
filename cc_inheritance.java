import java.util.*;
class Base{
  void fun()
  {
    System.out.println("This is from Base Class\n");
  }
}
class Derived1 extends Base{
  void fun()
  {
    System.out.println("From D1 Class");
  }
}
class Derived2 extends Base{
  void fun()
  {
  System.out.println("From D2 class\n");
  }
  void fun(int a)
  {
  System.out.println("From D2 with value "+a);
  }
}
class MainClass{
public static void main(String arg[])
{
  Derived1 d1=new Derived1();
  d1.fun(1);
}
}