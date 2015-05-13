import java.util.*;
public class MathDemo{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
   // int n=sc.nextInt();
    int n=Integer.parseInt("89");
    System.out.println(Math.sqrt(n));
    String msg=sc.nextLine();
   // msg=sc.nextLine();
    System.out.println(msg);
    String[] arr=msg.split(" ");
    for(String str :  arr)
	System.out.println(str);
  }
  
}