// Server Code

#include<stdio.h>
#include<sys/socket.h>  // 

int main()
{
    int ServerSocket = 0;

    ServerSocket = socket(AF_INET, SOCK_STREAM, 0); // address family  dakhavat   
    // AF__INET means IPv4(Internet protocol version 4) Pattyansathi socket 
    // AF_INNET CHA use  internet var IPv4 address sathi hoto 
    // Sock_STREAM = data surakshit eka format madhhe pataval jato
    // jevha  0 dila jato tevha  yogya protocol choose karte
    if(ServerSocket < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }              

    printf("Socket gets created succesfully with fd : %d\n",ServerSocket);
    
}