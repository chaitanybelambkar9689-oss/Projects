import java.io.*;
import java.util.*;

class Program564
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




