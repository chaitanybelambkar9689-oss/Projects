//////////////////////////////////////////////////////////////////
//
//   Header File Inclusion
//
//////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>


//////////////////////////////////////////////////////////////////
//
//   UserDefined Macros
//
//////////////////////////////////////////////////////////////////


//Maximum file size that allow in file size
#define MAXFILESIZE     50
//
#define MAXOPENFILES    20
//
#define MAXINODE        5
//
#define READ            1
//
#define WRITE           2
//
#define EXECUTE         4
//
#define START           0
#define CURRENT         1
#define END             0

#define EXECUTE_SUCCESS 0

//////////////////////////////////////////////////////////////////
//
//   UserDefined Structures
//
//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
//
//   Structure name : BootBlock
//   Description    : Holds the information to boot of os
//
//////////////////////////////////////////////////////////////////

#pragma pack(1)
struct BootBlock
{
    char Information[100];
};


//////////////////////////////////////////////////////////////////
//
//   Structure name : SuperBlock
//   Description    : Holds the information about fileSystem
//
//////////////////////////////////////////////////////////////////

#pragma pack(1)
struct SuperBlock
{
    int TotalInode;
    int FreeInode;
};


//////////////////////////////////////////////////////////////////
//
//   Structure name : Inode
//   Description    : Holds the information about file
//
//////////////////////////////////////////////////////////////////


#pragma pack(1)
struct Inode
{
    char FileName[20];
    int INodeNumber;
    int FileSize;
    int ActualFileSize;
    int RefrenceCount;
    int Permission;
    char *Buffer;  //use to store the Jay Ganesh  in datablock
    struct iNode * next;

};

typedef struct Inode  INODE;
typedef struct Inode * PINODE;
typedef struct Inode * PPINODE;

//////////////////////////////////////////////////////////////////
//
//   Structure name : FileTable
//   Description    : Holds the information about opened file
//
//////////////////////////////////////////////////////////////////


struct FileTable
{
    int ReadOffset;   //kuthe point karto te sangato lets say to display the column number and &line number
    int WriteOffset; 
    int mode;
    PINODE ptrinode;

};


typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;


//////////////////////////////////////////////////////////////////
//
//   Structure name : UAREA
//   Description    : Holds the information about process file
//
//////////////////////////////////////////////////////////////////


struct UAREA
{
    char ProcessName[20];  //name of exe
    PFILETABLE UFDT[MAXOPENFILES];
};


//////////////////////////////////////////////////////////////////
//
//   Global variable or objects used in project
//
//////////////////////////////////////////////////////////////////


BootBlock bobj;
SuperBlock superobj;
UAREA uareaobj;


PINODE head = NULL;


//////////////////////////////////////////////////////////////////
//
//   Function Name : InitialiseUAREA
//   Description   : It is use to initialise UAREA members
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 13/01/2026
//
//////////////////////////////////////////////////////////////////


void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");

    int i = 0;

    for(i = 0; i < MAXOPENFILES;i++)
    {
        uareaobj.UFDT[i] = NULL;
    }
    printf("Marvellous CVFS :  UAREA gets initialised successfully");
}


//////////////////////////////////////////////////////////////////
//
//   Function Name : InitialiseSuperBlock
//   Description   : It is use to initialise SuperBlock members
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 13/01/2026
//
//////////////////////////////////////////////////////////////////


void InitialiseSuperBlock()
{
    superobj.TotalInode = MAXINODE;
    superobj.FreeInode =  MAXINODE;
    printf("Marvellous CVFS : Super Block gets initialised successfully");
}


//////////////////////////////////////////////////////////////////
//
//   Function Name : CreateDILB
//   Description   : It is use to create LinkedList of inodes
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 13/01/2026
//
//////////////////////////////////////////////////////////////////


void CreateDILB()
{
    int i = 1; //maintaining 1234
    PINODE newn = NULL;
    PINODE temp = NULL;



    for(i = 1; i<= MAXINODE;i++)
    {
        
    newn = (PINODE)malloc(sizeof(INODE));
    strcpy (newn -> FileName,'\0');

    newn -> INodeNumber = i;
    newn ->FileSize =  0;
    newn ->ActualFileSize = 0;
    newn ->RefrenceCount = 0;
    newn -> Permission = 0;
    newn ->Buffer = NULL;
    newn ->next = NULL;
     
    if(temp == NULL) // LL is empty
    {
        head = newn ;
        temp = head;
    }
    else            //LL contain atleast one node
    {
        temp -> next = newn;
        temp = temp ->next;
    }

    }
    printf("Marvellous CVFS : DILB created successfully");
}



//////////////////////////////////////////////////////////////////
//
//   Entry point function of the project
//
//////////////////////////////////////////////////////////////////


int main()
{

    return 0;
}