#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
 
int main()
{
    int iRet = 0;
    int fd = 0;
    char Arr[] = "Maharashtra";  
   
    fd = open("JanuaryX.txt",O_RDWR  | O_APPEND);

    if(fd  == -1)
    {
        printf("unable to open file");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
        iRet = write(fd,Arr,11);

        printf("%d bytes gets successfully written into the file\n",iRet);
        
        close(fd);
    }
    return 0;
}