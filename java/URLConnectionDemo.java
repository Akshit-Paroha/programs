import java.net.*;
import java.util.*;

public class URLConnectionDemo
{
    public static void main(String[] args) throws Exception
    {
        URL url = new URL("localhost:8080//index.php");
        URLConnection conn = url.openConnection();
        Scanner sc = new Scanner(conn.getInputStream());
        while (sc.hasNextLine())
        {
            System.out.println(sc.nextLine());
        }
        sc.close();
    }
}
