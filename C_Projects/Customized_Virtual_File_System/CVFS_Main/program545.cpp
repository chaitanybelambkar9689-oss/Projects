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
    printf("Chaitany CVFS :  UAREA gets initialised successfully\n");
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
    printf("Chaitany CVFS : Super Block gets initialised successfully\n");
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



    for(i = 1; i<= MAXINODE;i++)
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
        temp = head;
    }
    else            //LL contain atleast one node
    {
        temp -> next = newn;
        temp = temp ->next;
    }

    }
    printf("Chaitany CVFS : DILB created successfully");
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
    strcpy(bootobj.Information,"Booting process  of Chaitany cvfs is done");
    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Chaitany CVFS : Auxillary data initialise successsfully\n");

}



//////////////////////////////////////////////////////////////////
//
//   Function Name : DisplayHelp
//   Description   : It is use to display the help page
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 14/01/2026
//
//////////////////////////////////////////////////////////////////


void DisplayHelp()
{
    
    printf("---------------------------------------------------\n");
    printf("----- Chaitany CVFS Help page -------------------\n");
    printf("---------------------------------------------------\n");
    
    printf("man : It is use to display manual page \n");
    printf("clear : It is use to clear the terminal\n");
    printf("creat: It is use to create the file\n");
    printf("write :It is use to write the data into the file\n");
    printf(" read: It is use to read the data in the file \n");
    printf("stat : It is use to display stastical Information\n");
    printf("unlink: It is use to deleyte the file\n");
    printf("exit : it is use to  terminate Chaitany CVFS\n");

    printf("---------------------------------------------------\n");

}
//////////////////////////////////////////////////////////////////
//
//   Entry point function of the project
//
//////////////////////////////////////////////////////////////////


int main()
{
    char str[80] ={'\0'};
    char Command[5][20] ={{"\0"}}; // to avoid the grabage value
    int iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("---------------------------------------------------\n");
    printf("----- Chaitany CVFS started successfully---------\n");
    printf("---------------------------------------------------\n");

    //Infinite listening shell
    while(1) //conditional loop
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\n Chaitany CVFS : > ");
        fgets(str,sizeof(str),stdin);  
        
        iCount = sscanf("%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        printf("%d \n",iCount);
        fflush(stdin);

        if(iCount == 1)
        {
            if (strcmp("exit",Command[0]) == 0)
            {
                printf("Thank you for Chaitany CVFS \n");
                printf("Deallocating all the allocated resources\n");
                break;
            }
            else if(strcmp("ls",Command[0])== 0)
            {
                printf("Inside ls\n");
            }
            else if(strcmp("help",Command[0])==0)
            {
                DisplayHelp();
            }

        }// End of else if 1
        else if(iCount == 2)
        {

        }// End of else if 2
        else if(iCount == 3)
        {

        }// End of else if 3
        else if(iCount == 4)
        {

        }// End of else if 4
        else
        {
          printf("Command not Found \n");
          printf("Please refer help option to get information \n");  
        }// End of Else

        
    }//End of While


    return 0;
}// EDnd of main