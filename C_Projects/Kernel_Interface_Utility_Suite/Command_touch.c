
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//  ./touchx FileName
//  argv[0]   argv[1]
//  argc = 2
/*
     Ccept filename from commandline
     crate that file
     If it si existing  return
     If ift is not existing 
     create that file

*/

#define MAX_BUFFER_SIZE

int main(int argc,char *argv[])
{

    if (argc != 2)
    {
        printf("Error:Insufficient Argument\n");
        printf("Use as :../touchx FileName\n");
        return -1;
    }
    if(access(argv[1],F_OK)==0)
    {
        return 0;
    }

    else
    {
        creat(argv[1],0777);
    }


    return 0;
}