import java.io.*;
import java.net.*;

class ChatServer
{
    public static void main(String A[]) throws Exception
    {
        ServerSocket ssobj = new ServerSocket(5100);
        System.out.println("Server is waiting at port 5100");

        Socket sobj = ssobj.accept(); //listener
        System.out.println("Client  request get accepted successfuly");

        PrintStream pobj = new PrintStream(sobj.getOutputStream);
        BufferedReader bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream));
        BufferedReader bobj2 = new BufferedReader(new InputStreamReader(System.in));






        String str = bobj1.readLine(); //aikale
        System.out.printlnln("Client says :"+str);
        System.out.println("Enter message for client");
        bobj2.readLine();
        pobj.println(str);
       }
}