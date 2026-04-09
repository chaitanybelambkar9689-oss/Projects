//Unpacking final Code

import java.io.*;
import java.util.*;


class program614
{
    public static void main(String A[])throws Exception
    {
        //Variable Creation
        int FileSize = 0;
        int i = 0;
        int iRet = 0;

        byte Key = 0x11;

        Scanner sobj = null;
        String FileName = null;
        String Header = null; //stores the data in readable text format
        String Tokens[] = null;

        File fpackobj = null;
        File fobj = null;

        FileInputStream fiobj = null;
        FileOutputStream foobj = null; //je file banali tyat lihinyasathi

        byte bHeader[] = new byte[100]; //byte header madhe data binary form madhe hota
        byte Buffer[] = null;


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
        while((iRet = fiobj.read(bHeader,0,100)) != -1)
        {
    

        Header = new String(bHeader); //convert byteheader into new string

        Header = Header.trim(); //remove unwanted spaces

        Tokens = Header.split(" "); //breaks header into parts

        System.out.println("File Name :"+Tokens[0]);
        System.out.println("File Size :"+Tokens[1]);

        fobj = new File(Tokens[0]);

        fobj.createNewFile();

        foobj = new FileOutputStream(fobj);  //A.txt file  pass keli 
         
        FileSize = Integer.parseInt(Tokens[1]); //Token[1] ="500"->500
        //Buffer for reading the data
        Buffer = new byte[FileSize]; //create space for 500 bytes in memory
        //Read from packed file
        fiobj.read(Buffer,0,FileSize); //read(byte[]array,int start,int length )
        //Decrypt the data
        for(i = 0;i< FileSize;i++)
        {
            Buffer[i] = (byte)(Buffer[i]^Key);
        }
        //write into extract file
        foobj.write(Buffer,0,FileSize);



        }
  

    }
}
