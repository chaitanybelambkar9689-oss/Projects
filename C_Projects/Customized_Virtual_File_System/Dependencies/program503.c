#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = creat("LB.txt",0777);

    if(fd  == -1)
    {
        printf("unable to create file");
    }
    else
    {
        printf("File gets successfully created with fd : %d\n",fd);
    }
    return 0;
}