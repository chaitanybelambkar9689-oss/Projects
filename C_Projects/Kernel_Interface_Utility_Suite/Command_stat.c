
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>



//  ./statx FileName
//  argv[0]   argv[1]
//  argc = 2
/*
     Accept Commandline from commandline
     call access to check existance of file
     cal stat system call to get file meta data
     displaaay the metadata

*/


int main(int argc,char *argv[])
{

    if (argc != 2)
    {
        printf("Error:Insufficient Argument\n");
        printf("Use as :../statx FileName\n");
        return -1;
    }

    if(access(argv[1],F_OK)==0)
    {
      struct stat sobj;

      int iRet = 0;

      iRet = stat(argv[1],&sobj);

      if(iRet == -1)
      {
        printf("Error Unable to fetch stastical information ");
        return -1;
      }

    printf("FileName : %s\n",argv[1]);
    printf("FileSize : %ld\n",(long)sobj.st_size);
    printf("Inode Nummber : %ld\n",(long)sobj.st_ino);


    }

    else
    {
       printf("error  : File Not Found\n ");
       return -1;
    }


    return 0;
}