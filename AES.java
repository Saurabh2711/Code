import java.util.*;
import java.security.*;
import javax.crypto.*;
public class AES{
  public static void main(String args[])
  {
    try{
      Cipher ci=Cipher.getInstance("AES/ECB/PKCS5Padding");
      KeyGenerator keyGen=KeyGenerator.getInstance("AES");
      SecretKey key=keyGen.generateKey();
      ci.init(Cipher.ENCRYPT_MODE,key);
      Scanner sc=new Scanner(System.in);
      String msg=sc.next();
      byte[] text=msg.getBytes();
      byte[] c_text=ci.doFinal(text);
      System.out.println("Encrypted Text : "+(new String(c_text)));
      ci.init(Cipher.DECRYPT_MODE,key);
      byte[] p_text=ci.doFinal(c_text);
      System.out.println("Plain Text : "+(new String(p_text)));
    }
    catch(Exception e)
    {
      System.out.println("Error : "+e);
    }
  }
}