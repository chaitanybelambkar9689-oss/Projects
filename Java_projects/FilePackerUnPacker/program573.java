import java.io.*;
import java.util.*;

class program573
{
    public static void main(String A[]) throws Exception
    {
        int iRet = 0;
        boolean bRet= false;

        String FileName = null;
        byte Arr[] = new byte[100];
        File fobj = null;
        char Brr[] =null;
       
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of the file");
        FileName = sobj.nextLine();
        
        fobj = new File(FileName);

        if(fobj.exists())
        {
            FileInputStream fiobj = new FileInputStream(fobj);


            iRet = fiobj.read(Arr);

            String str = new String(Arr);

            System.out.println("iRet ="+iRet);
            System.out.println(str);

            System.out.println(Arr);
        }
        else
        {
            System.out.println("There is no such file");
        }
 

   
        sobj.close();

    }
 

}




