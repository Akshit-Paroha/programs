import java.io.*;
import java.net.*;
import java.util.*;

public class tcpserver2 
{
    public static void main(String[] args) throws IOException
    {
        ServerSocket ss = new ServerSocket(8888);
        System.out.println("Server started. Waiting for clients...");

        while (true)   
        {
            Socket sc = ss.accept();  
            System.out.println("Client connected: " + sc.getInetAddress());

            InputStream is = sc.getInputStream();
            OutputStream os = sc.getOutputStream();

            Scanner s = new Scanner(new InputStreamReader(is));
            PrintWriter pw = new PrintWriter(os, true);

            String req = s.nextLine();
            System.out.println("Message from client: " + req);

            pw.println("Hello I recived your message ' " + req+"'");
            System.out.println("Response sent to client");

            sc.close(); 
        }
    }
}
