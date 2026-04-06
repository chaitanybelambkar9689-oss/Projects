import java.io.*;
import java.util.*;

class program577
{
    public static void main(String A[]) throws Exception
    {
        int iRet = 0;  //store number of bytes read
        String str = null;

        File fobjsrc = null;
        File fobjDest= null;

        boolean bRet= false;

        String FileNameSrc = null;
        String FileNameDest = null;

        byte Buffer[] = new byte[1024];
    
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of the source file");
        FileNameSrc = sobj.nextLine();
        
        fobjsrc = new File(FileNameSrc);

        if(fobjsrc.exists())
        {
           System.out.println("Enter the name of the destination file");
           FileNameDest = sobj.nextLine();

            fobjDest = new File(FileNameDest);

            fobjDest.createNewFile();
            

        
            FileInputStream fiobj = new FileInputStream(fobjsrc); //open the file for reading 

            FileOutputStream foobj = new FileOutputStream(fobjDest); //open the file for writing


            while(( iRet = fiobj.read(Buffer))  != -1)
            {
                
                //System.out.println(str);
                foobj.write(Buffer,0,iRet);

            }

            System.out.println("File Copy Succeessfuly");
            fiobj.close();
            foobj.close();

        }
        else
        {
            System.out.println("There is no source file");
        }
 

        
        sobj.close();

    }
 

}



