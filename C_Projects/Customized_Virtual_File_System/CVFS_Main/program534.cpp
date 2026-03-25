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
#define END             2

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
    int TotalInodes;
    int FreeInodes;
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
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int RefrenceCount;
    int Permission;
    char *Buffer;  //use to store the Jay Ganesh  in datablock
    struct Inode * next;

};

typedef struct Inode  INODE;
typedef struct Inode * PINODE;
typedef struct Inode ** PPINODE;

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
    int Mode;
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


BootBlock bootobj;
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
    printf("Marvellous CVFS :  UAREA gets initialised successfully\n");
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
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes =  MAXINODE;
    printf("Marvellous CVFS : Super Block gets initialised successfully\n");
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
    PINODE temp = head;



    for(i = 1; i <= MAXINODE;i++)
    {
        
    newn = (PINODE)malloc(sizeof(INODE));
    strcpy (newn -> FileName,"\0");

    newn -> InodeNumber = i;
    newn ->FileSize =  0;
    newn ->ActualFileSize = 0;
    newn ->RefrenceCount = 0;
    newn -> Permission = 0;
    newn ->Buffer = NULL;
    newn ->next = NULL;
     
    if(temp == NULL) // LL is empty
    {
        head = newn ;
        temp = head ;
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
//   Function Name : StartAuxillaryDataInitialisation
//   Description   : It is use to call such function which is use to initialise auxillary data
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 13/01/2026
//
//////////////////////////////////////////////////////////////////


void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information,"Booting process  of Marvellous CVFS is done");
    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialise successsfully\n");

}
//////////////////////////////////////////////////////////////////
//
//   Entry point function of the project
//
//////////////////////////////////////////////////////////////////


int main()
{
    char str[80] ={'\0'};
    char Command[4][20];
    int iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("---------------------------------------------------\n");
    printf("----- Marvellous CVFS started successfully---------\n");
    printf("---------------------------------------------------\n");

    while(1) //conditional loop
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\n Marvellous CVFS : >");
         fgets(str,sizeof(str),stdin);   
       
    }


    return 0;
}