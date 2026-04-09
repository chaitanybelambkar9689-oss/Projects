//Unpacking Code

import java.io.*;
import java.util.*;


class program612
{
    public static void main(String A[]) throws Exception
    {
        //Variable Creation
        int FileSize = 0;
        int i = 0;
        byte Key = 0x11;
        Scanner sobj = null;
        String FileName = null;
        File fpackobj = null;
        File fobj = null;
        FileInputStream fiobj = null;
        FileOutputStream foobj = null; //je file banali tyat lihinyasathi
        byte bHeader[] = new byte[100];
        byte Buffer[] = null;
        String Header = null;
        String Tokens[] = null;

        sobj = new Scanner(System.in);

        System.out.println("Enter the name of packed file");
        FileName  = sobj.nextLine();
        
         fpackobj = new File(FileName);

        if(fpackobj.exists() == false)
        {
            System.out.println("There is no such pack file");
            return;
        }
        fiobj = new FileInputStream(fpackobj);//vachanyasathi reader  banavala

        //Read the header
        fiobj.read(bHeader,0,100);

        Header = new String(bHeader);

        Header = Header.trim();

        Tokens = Header.split(" ");
        System.out.println("File Name :"+Tokens[0]);
        System.out.println("File Size :"+Tokens[1]);

        fobj = new File(Tokens[0]);

        fobj.createNewFile();

        foobj = new FileOutputStream(fobj);
         
        FileSize = Integer.parseInt(Tokens[1]);
        //Buffer for raeding th dat
        Buffer = new byte[FileSize];
        //Read from packed file
        fiobj.read(Buffer,0,FileSize);
        //Decrypt the data
        for(i = 0;i< FileSize;i++)
        {
            Buffer[i] = (byte)(Buffer[i]^Key);
        }
        //write into extract file
        foobj.write(Buffer,0,FileSize);




    }
}
