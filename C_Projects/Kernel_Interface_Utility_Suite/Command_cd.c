
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//  ./cdx  Directorypath
//  argv[0]   argv[1]
//  argc = 2
/*
  Accept new directory path
  call chddir with that path
  get cwd to check to changed path

*/

#define MAX_BUFFER_SIZE 256

int main(int argc,char *argv[])
{

    char Buffer[256] = {'\0'};

    if (argc != 2)
    {
        printf("Error:Insufficient Argument\n");
        printf("Use Command : ./cdx Directorypath\n");
        return -1;
    }

    if(chdir(argv[1]))
    {
        printf("Error : Unable to change directory\n");
        return -1;
        
    }

        getcwd(Buffer,sizeof(Buffer)-1);
        printf("Current directory change to  %s\n",Buffer);
    


    return 0;
}