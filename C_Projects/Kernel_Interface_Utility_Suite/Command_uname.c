
#include<sys/utsname.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//  ./unamex
//  argv[0]  
//  argc = 1
/*
  Call the system call uname
  print the information from uts namestructure


*/


int main(int argc,char *argv[])
{
  struct utsname obj;
   int iRet = 0;

   iRet = uname(&obj);

   if(iRet == -1)
   {
    printf("Error unable to fetch system information\n");
    return -1;
   }

   printf("Operating system name  : %s\n",obj.sysname);
  printf("Node Name : %s\n",obj.nodename);
   printf("Operating system version : %s\n",obj.release);
  return 0;
}