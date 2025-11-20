import java.io.*;
import java.net.*;
import java.util.*;

public class tcpserver 
{
    public static void main(String[] args) throws IOException , UnknownHostException
    {
        ServerSocket ss = new ServerSocket(8888);
        System.out.println("Server started. Waiting for client...");

        Socket sc = ss.accept();
        System.out.println("Client connected!");

        InputStream is = sc.getInputStream();
        OutputStream os = sc.getOutputStream();

        PrintWriter pw = new PrintWriter(os, true);
        Scanner s = new Scanner(new InputStreamReader(is));

        String req = s.nextLine();
        System.out.println("Message from client: " + req);

        pw.println("Hello " + req);
        System.out.println("Response sent to client");

        sc.close();
        ss.close();
    }
}
