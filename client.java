import java.io.*;
import java.util.*;
import java.net.*;
public class client{
  public static void main(String args[])
  {
  
    try{
    Socket skt=new Socket("localhost",8888);
    OutputStream in=skt.getOutputStream();
    in.println("Saurabh");
    }
    catch(Exception e)
    {
    System.out.println("Erorr : "+e);
    }
  }
}