
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//  ./catx FileName
//  argv[0]   argv[1]
//  argc = 2
/*
     Ccept filename from commandline
     check whetether the file is existing or not
     if it is existing then print on cosole

     If it si existing  return
     If ift is not existing 
     create that file

*/


#define MAX_BUFFER_SIZE 1024
int main(int
    
     argc,char *argv[])
{

    if (argc != 2)
    {
        printf("Error:Insufficient Argument\n");
        printf("Use as :../catx FileName\n");
        return -1;
    }
    if(access(argv[1],F_OK) !=0)
    {
        printf("cat :  %s:No such file or directory\n",argv[1]);
        return-1;
    }

    else
    {
        int fd = 0;

        fd = open(argv[1],O_RDONLY);

        if(fd < 0)
        {
            printf("Error : Unable to open file\n");
            return-1;
        }
        char Buffer[MAX_BUFFER_SIZE] ={'\0'};

        int iRet = 0;

        while((iRet = read(fd,Buffer,sizeof(Buffer))) !=0)
        {
            write(1,Buffer,iRet);

        }
        printf("\n");
        close(fd);


    }


    return 0;
}