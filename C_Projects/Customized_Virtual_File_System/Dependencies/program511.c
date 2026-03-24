#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
 
int main()
{
    int iRet = 0;
    int fd = 0;
    char Arr[] = "Pune";  
   
    fd = open("JanuaryX.txt",O_RDWR);

    if(fd  == -1)
    {
        printf("unable to open file");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
        iRet = write(fd,Arr,3);

        printf("%d bytes gets successfully written into the file\n",iRet);
        
        close(fd);
    }
    return 0;
}