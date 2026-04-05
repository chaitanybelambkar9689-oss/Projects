import java.io.*;
import java.util.*;

class program569
{
    public static void main(String A[]) throws Exception
    {

        String FileName = null;
        File fobj = null;
      
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of the file");
        FileName = sobj.nextLine();
        
        fobj = new File(FileName);
        if(fobj.exists())
        {
            FileOutputStream foobj = new FileOutputStream(fobj);
            String str = "Jay Ganesh...";

            foobj.write(str); //error  we cant convert directly into string
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




