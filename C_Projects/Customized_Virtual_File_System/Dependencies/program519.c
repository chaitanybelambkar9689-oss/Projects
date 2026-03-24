#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
 
int main()
{
    int fd = 0, iRet = 0;
    char Fname[100] = {'\0'};

    printf("Enter the name of file :\n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDWR);

    if(fd != -1)
    {
        printf("File gets succeefully opened  \n");
        
    }
    else
    {
        printf("There is no such file \n");
    }
    close(fd);
   
    

    return 0;
}