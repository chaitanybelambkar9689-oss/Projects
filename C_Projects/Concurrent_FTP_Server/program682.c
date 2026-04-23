

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0; // process id store karnyasathi pid_t ha datatype use kartat

    pid = fork();

    if(pid < 0)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(pid == 0)
    {
        printf("Child process gets created succesfully\n");
    }

    return 0;
}

