 import java.io.*;
import java.util.*;

class program567
{
    public static void main(String A[]) throws Exception
    {

        String FileName = null;
        File fobj = null;
        FileReader frobj = null;
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of the file");
        FileName = sobj.nextLine();
        
        fobj = new File(FileName);
        if(fobj.exists())
        {
         frobj = new FileReader(FileName);
           
         char Buffer[] =new char[50];   //aray is treated as pointer

         frobj.read(Buffer,0,10); //total data read karnyasathi
         System.out.println("Data from file :"+new String(Buffer));

        }
        else
        {
            System.out.println("There is no such file");
        }
        
        if(frobj != null)
        {
            frobj.close();
        }

   
        sobj.close();

    }
 

}






