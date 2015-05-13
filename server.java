import java.io.*;
import java.util.*;
import java.net.*;
public class server{
  public static void main(String args[])
  {
  try{
      ServerSocket sskt=new ServerSocket(8888);
      while(true)
      {
	Socket skt=sskt.accept();
	InputStream ot=skt.getInputStream();
	System.out.println(ot.read());
      }
      }catch(Exception e)
      {
      System.out.println("Error : "+e);
      }
  }
}