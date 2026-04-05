import java.io.*;
import java.util.*;

class program576
{
    public static void main(String A[]) throws Exception
    {
        int iRet = 0;
        boolean bRet= false;

        String FileName = null; 
        byte Buffer[] = new byte[100]; //use to store temporary file data //Buffer having file data in byte
        File fobj = null;
        
       
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of the file");
        FileName = sobj.nextLine();
        
        fobj = new File(FileName);

        if(fobj.exists())
        {
            String str = null;  
            FileInputStream fiobj = new FileInputStream(fobj); //Open the file for reading


            while(( iRet = fiobj.read(Buffer))  != -1) //Buffer = read maximimum 100bytes at a time
            {
                str = new String(Buffer,0,iRet); //convert byte into readable text
                System.out.println(str);
                str = null;
            }

            System.out.println("");

        }
        else
        {
            System.out.println("There is no such file");
        }
 

   
        sobj.close();

    }
 

}



