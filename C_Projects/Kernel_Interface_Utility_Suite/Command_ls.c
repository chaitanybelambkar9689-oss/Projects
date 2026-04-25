
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>


//  ./lsx
//  argv[0]   
// argc = 1
/*
     Open The Current Directory
     read all entries from that directory
     print name of all files
     close the directory

*/



int main(int argc,char *argv[])
{

    char *path = ".";
    DIR  *dp = NULL;

    dp = opendir(path);

    if(dp ==NULL)
    {
        printf("Error unable to open directory\n");
        return -1;
    }
    struct dirent *dobj;

    while((dobj = readdir(dp)) != NULL )
    {
        printf("%s\n",dobj -> d_name);
    }
    closedir(dp);
  

    return 0;
}