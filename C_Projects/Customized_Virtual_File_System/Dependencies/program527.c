#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int iRet = 0;
    int fdSrc = 0;
    int fdDest = 0;

    char fdSource[] ={'\0'};
    char fdDestination[] = {'\0'};
    char Buffer[100] = {'\0'};

    printf("Enter the source file : \n");
    scanf("%s",fdSource);

    printf("Enter the destination file : \n");
    scanf("%s",fdDestination);


    fdSrc = open(fdSource,O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Unable to open the file");
       
        return -1;
    }
    fdDest = creat(fdDestination,0777);

    if(fdDest == -1)
    {
        printf("Unable to open the file");
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer)) != 0))
    {
        write(fdDest,Buffer,iRet);
    }
    printf("File gets copied \n");
    close(fdSrc);
    close(fdDest);


}