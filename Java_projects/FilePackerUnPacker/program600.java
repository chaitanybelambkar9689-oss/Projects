import java.io.*;
import java.util.*;


class program600
{
    public static void main(String A[]) 
    {
        String str = "Python Java Data Structure";

        String Arr[] = str.split(" "); //tokanize karnyasathi

        System.out.println(Arr.length);

        for(int i = 0;i < Arr.length;i++)
        {
            System.out.println(Arr[i]);
        }



    }
}