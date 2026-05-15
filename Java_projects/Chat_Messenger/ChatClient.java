import java.io.*;
import java.net.*;

class ChatClient
{
    public static void main(String A[])
    {



        Socket sobj = new Socket("localhost",5100);
        System.out.println("Client  request get accept successfuly");

        PrintStream pobj = PrintStream(sobj.getOutputStream);
        BufferedReader bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream));
        BufferedReaader bobj2 = new BufferedReader(new InputStreamReader(System.in));




        System.out.println("Enter a message for server");
        String str = bobj2.readline();
        pobj.println(str);



        str = bobj1.readLine();
        System.out.prinln("Server says"+str);
    }
}