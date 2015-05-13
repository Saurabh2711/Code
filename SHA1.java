import java.util.*;
import java.security.*;
import javax.crypto.*;
public class SHA1{
  public static void main(String args[])
  {
    try{
    MessageDigest md=MessageDigest.getInstance("SHA1");
    Scanner sc=new Scanner(System.in);
    String msg=sc.next();
    byte[] result=md.digest(msg.getBytes());
    Formatter ft=new Formatter();
    for(byte b : result)
    {
      ft.format("%02x",b);
    }
    System.out.println(ft.toString());
    }
    catch(Exception e)
    {
    System.out.println("Error : "+e);
    }
  }
}