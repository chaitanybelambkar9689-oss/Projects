#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    //O_RD only  O_Trunc  O_WRONLY O_CREAT O_RDWR   O_APPEND
    fd = open("LB.txt",O_RDWR);

    if(fd  == -1)
    {
        printf("unable to open file");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
    }
    return 0;
}