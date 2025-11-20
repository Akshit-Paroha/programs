import java.io.*;
import java.net.*;
import java.util.*;

public class tcp 
{
    public static void main(String[] args) throws IOException, UnknownHostException
    {
        Socket sc = new Socket("192.168.43.209", 8888);

        InputStream is = sc.getInputStream();
        OutputStream os = sc.getOutputStream();

        PrintWriter pw = new PrintWriter(os, true);
        Scanner s = new Scanner(new InputStreamReader(is));

        pw.println("Akshit");
        System.out.println("Message sent to server");

        String res = s.nextLine();
        System.out.println("Message from server: " + res);

        sc.close();
    }
}
