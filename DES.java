import java.util.*;
import java.security.*;
import javax.crypto.*;
public class DES{
  public static void main(String args[])
  {
    try{
    Cipher ci=Cipher.getInstance("AES/ECB/PKCS5Padding");
    KeyGenerator kg=KeyGenerator.getInstance("AES");
    SecretKey myKey=kg.generateKey();
    ci.init(Cipher.ENCRYPT_MODE,myKey);
    Scanner sc=new Scanner(System.in);
    String msg;
    msg=sc.next();
    byte[] text=msg.getBytes();
    byte[] cText=ci.doFinal(text);
    System.out.println("Cipher Text : "+(new String(cText)));
    ci.init(Cipher.DECRYPT_MODE,myKey);
    byte[] d_text=ci.doFinal(cText);
    System.out.println("Plain Text : "+(new String(d_text)));
    }
    catch(Exception e)
    {
    System.out.println("Error : "+e);
    }
  }
 }