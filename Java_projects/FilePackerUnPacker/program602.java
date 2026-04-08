import java.io.*;
import java.util.*;


class program602
{
    public static void main(String A[]) throws Exception
    {
        String str = "A.txt 10";

        String Arr[] = str.split(" "); //tokanize karnyasathi

        System.out.println(Arr.length);

        for(int i = 0;i < Arr.length;i++)
        {
            System.out.println(Arr[i]);
        }
        //ji string ghetali ahe   tyacha 10 next line la n yenyasathi asa kel
        File fobj = new File(Arr[0]);
        fobj.createNewFile();

        int Size = Integer.parseInt(Arr[1]);


    }
}