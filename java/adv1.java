import java.net.*;

public class adv1 
{
    public static void main(String[] args) throws UnknownHostException
    {
        InetAddress ip = InetAddress.getLocalHost();
        String hostname, hostaddress;

        hostname = ip.getHostName();
        hostaddress = ip.getHostAddress();

        System.out.println("Host Name: " + hostname + "\nHost Address: " + hostaddress);

        ip = InetAddress.getByName("amazon.in");
        hostname = ip.getHostName();
        hostaddress = ip.getHostAddress();
        System.out.println("Host Name: " + hostname + "\nHost Address: " + hostaddress);

        InetAddress[] obj = InetAddress.getAllByName("amazon.com");
        for (int i = 0; i < obj.length; i++)
        {
            hostname = obj[i].getHostName();
            hostaddress = obj[i].getHostAddress();
            System.out.println("Host Name: " + hostname + " | Host Address: " + hostaddress);
        }
    }
}
