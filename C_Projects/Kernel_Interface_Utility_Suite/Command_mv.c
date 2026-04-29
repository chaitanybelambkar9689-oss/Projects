
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//  ./cpx  Source.txt Demo.txt
//  argv[0]   argv[1] argv[2] 
// argc = 3
/*
   Open Source file for reading

   Create Destination File
   Read the Data from Source 
   Write into Destination
   close both files

*/

#define MAX_BUFFER_SIZE 1024

int main(int argc,char *argv[])
{

    if (argc != 3)
    {
        printf("Error:Insufficient Argument\n");
        printf("Use Command as :./mvx SourcePath DestinationPath\n");
        return -1;
    }

    if(rename(argv[1],argv[2])== -1)
    {
        printf("Error :Unable to move\n");
        return -1;
    }

    
    return 0;
}