import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.*;
public class HashTextTest {
 
    /**
     * @param args
     * @throws NoSuchAlgorithmException 
     */
    public static void main(String[] args) throws NoSuchAlgorithmException {
        System.out.println(sha1("test string to sha1"));
    }
     
    static String sha1(String input) throws NoSuchAlgorithmException {
        MessageDigest mDigest = MessageDigest.getInstance("SHA1");
        byte[] result = mDigest.digest(input.getBytes());
       Formatter ft=new Formatter();
       for(byte b : result)
       {
	  ft.format("%02x",b);
       }
       return ft.toString();
    }
}
