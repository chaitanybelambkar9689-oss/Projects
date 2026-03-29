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
//contain text data
#define REGULARFILE     1  
#define SPECIALFILE     2


//////////////////////////////////////////////////////////////////
//
//   UserDefined Macros for error handling
//
//////////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER 1

#define ERR_NO_INODE          2

#define ERR__FILE_ALREADY_EXIST 3
#define ERR_FILE_NOT_EXIST    4

#define ERR_PERMISSION_DENIED 5

#define ERR_INSUFFICIENT_SPACE 6
#define ERR_INSUFFICIENT_DATA  7

#define ERR_MAX_FILES_OPEN     8

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
    int TotalInodes; //5
    int FreeInodes; //5
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
    int FileType;
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
    int Mode;          //create kelyvalar permission aste
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



    for(i = 1; i<= MAXINODE;i++)
    {
        
    newn = (PINODE)malloc(sizeof(INODE));
    strcpy (newn -> FileName,"\0");

    newn -> InodeNumber = i;
    newn ->FileSize =  0;
    newn ->ActualFileSize = 0;
    newn -> FileType  = 0;     // contain .txt file
    newn ->RefrenceCount = 0;
    newn -> Permission = 0;
    newn ->Buffer = NULL;
    newn ->next = NULL;
     
    if(temp == NULL) // LL is empty
    {
        head = newn ;
        temp = head;
    }
    else            //LL contain atleast one node  //Insert last logic
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
///////////////////////////////////////////////////////////////////


void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information,"Booting process  of mavellous cvfs is done");
    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialise successsfully\n");

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
    printf("----- Marvellous CVFS Help page -------------------\n");
    printf("---------------------------------------------------\n");
    
    printf("man : It is use to display manual page \n");
    printf("clear : It is use to clear the terminal\n");
    printf("creat: It is use to create the file\n");
    printf("write :It is use to write the data into the file\n");
    printf("read: It is use to read the data in the file \n");
    printf("stat : It is use to display stastical Information\n");
    printf("unlink: It is use to delete the file\n");
    printf("exit : it is use to  terminate marvellous CVFS\n");

    printf("---------------------------------------------------\n");

}



//////////////////////////////////////////////////////////////////
//
//   Function Name : ManPageDisplay
//   Description   : It is use to display man page
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 14/01/2026
//
//////////////////////////////////////////////////////////////////


void ManPageDisplay(char Name[])
{
    if(strcmp("ls",Name)== 0)
    {
        printf("About : It is used to list  the name of all files \n");
        printf("Usage : ls\n"); //how to use
    }
    else if(strcmp("man",Name)== 0)
    {
        printf("About : It is used to display manual page \n");
        printf("Usage :  man Command _name\n");  
        printf("command__name : It is the name of the command");   
    }
    else if(strcmp("exit",Name) == 0)
    {
        printf("About : It is use to terminate the shell\n");
        printf("Usage : exit\n");
    }
    else if(strcmp("clear",Name) == 0)
    {
        printf("About : It is use to clear the terminal\n");
        printf("Usage : cls\n");
    }
    else
    {
        printf(" No manual entry for manual page %s\n",Name);
    }
}



//////////////////////////////////////////////////////////////////
//
//   Function Name : IsFileExist
//   Description   : It is use to dheck file is whether file is already exist or not
//   Input         : It accepts file name
//   Output        : It returns the true or false
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 16/01/2026
//
//////////////////////////////////////////////////////////////////


bool IsFileExist(
                    char *name  //File name
                )
                {

                    PINODE temp = head;
                    bool bFlag = false;

                    while(temp  != NULL)
                    {
                        if((strcmp(name,temp -> FileName)== 0) && (temp -> FileType == REGULARFILE))
                        {
                            bFlag = true;
                            break;

                        }
                        temp = temp -> next;
                    }
                }


//////////////////////////////////////////////////////////////////
//
//   Function Name : CreateFile
//   Description   : It is use to create new regular file
//   Input         : It accepts file name and permission
//   Output        : It returns the file descriptor
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 16/01/2026
//
//////////////////////////////////////////////////////////////////


int CreateFile(
                char *name,    //Name of new file
                int permission // permission for that file
              )

{
    PINODE temp = head;
    int i = 0;

    printf("Total number of Inodes remaining %d\n",superobj.FreeInodes);

    // If name is missing
    if(name == NULL)
    {
        return ERR_INVALID_PARAMETER;
    }
    
    // If the permission is wrong
    // permission -> 1 -> READ
    // permission -> 2 -> WRITE
    // permission -> 3 -> READ+WRITE

    if(permission < 1 ||permission>3)
    {
        return ERR_INVALID_PARAMETER;
    }
    //If the inodes are full
    if(superobj.FreeInodes == 0)
    {
        return ERR_NO_INODE;
    }

    //If file is already present
    if(IsFileExist(name) == true)
    {
        return ERR__FILE_ALREADY_EXIST;
    }

    //Search empty Inpde

    while(temp != NULL)
    {
        if(temp -> FileType == 0)  // Inode rikama ahe
        {
            break;
        }
        temp = temp -> next;
    }

    if(temp == NULL)
    {
        printf("There is no Inode\n");
        return ERR_NO_INODE;
    }

    //Search for empty UFDT(Array) Entry
    //Note 0,1,2 are reserved
    for(i = 3;i < MAXOPENFILES;i++)
    {
        if(uareaobj.UFDT[i]== NULL)
        {
            break;
        }

    }

    //UFDT is full
    if(i == MAXOPENFILES)
    {
        return ERR_MAX_FILES_OPEN;
    }

    //Allocate memory for filetable
    uareaobj.UFDT[i] = (PFILETABLE)malloc(sizeof(FileTable));

    //Initialise file table
    uareaobj.UFDT[i] -> ReadOffset = 0;
    uareaobj.UFDT[i] -> WriteOffset = 0;
    uareaobj.UFDT[i] -> Mode = permission;

    //connect filetable with Inode
    uareaobj.UFDT[i] -> ptrinode = temp;

    //Initialise elements of Inode
    strcpy(uareaobj.UFDT[i] -> ptrinode -> FileName,name);
    uareaobj.UFDT[i] -> ptrinode ->FileSize = MAXFILESIZE;
    uareaobj.UFDT[i] -> ptrinode ->ActualFileSize = 0;
    uareaobj.UFDT[i] -> ptrinode ->FileType = REGULARFILE;
    uareaobj.UFDT[i] -> ptrinode ->RefrenceCount = 1;
    uareaobj.UFDT[i] -> ptrinode ->Permission = permission;

    //Allocate memory for files data
    uareaobj.UFDT[i] -> ptrinode ->Buffer = (char*)malloc(MAXFILESIZE);

    superobj.FreeInodes--;

    return i; //File table




} 


//////////////////////////////////////////////////////////////////
//
//   Function Name : LsFile
//   Description   : It is use to list all files
//   Input         : Nothing
//   Output        : Nothing
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 16/01/2026
//
//////////////////////////////////////////////////////////////////

void LsFile()  //dispaly ch function
{
    PINODE temp = head;

    printf("---------------------------------------------------\n");
    printf("----- Marvellous CVFS Files Information------------\n");
    printf("---------------------------------------------------\n");

    while(temp != NULL)
    {
        if(temp -> FileType != 0)
        {
        printf("%d\t%s\t%d\n",temp ->InodeNumber,temp->FileName,temp ->ActualFileSize);
        }

        temp = temp -> next;
    }
    printf("---------------------------------------------------\n");
}



//////////////////////////////////////////////////////////////////
//
//   Function Name : UnlinkFile()
//   Description   : It is use to delete the file
//   Input         : File Name
//   Output        : Nothing
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 22/01/2026
//
//////////////////////////////////////////////////////////////////



int UnlinkFile(
                char *name
            )
{
    int  i  = 0;

    if(name == NULL)
    {
        return ERR_INVALID_PARAMETER;
    }

    if(IsFileExist(name)== false)
    {
        return ERR_FILE_NOT_EXIST;
    }

    //Travel the UFDT
    for(i = 0;i<MAXOPENFILES;i++)
    {
        if(uareaobj.UFDT[i] != NULL)
        {
            if(strcmp(uareaobj.UFDT[i]->ptrinode->FileName,name)== 0)
            {
                //Deallocate memery of Buffer
                free(uareaobj.UFDT[i]->ptrinode->Buffer );
                uareaobj.UFDT[i]->ptrinode->Buffer = NULL;  
                //Reset all values of inode
                //dont deallocate memory of inode
                uareaobj.UFDT[i]->ptrinode->FileSize = 0;
                uareaobj.UFDT[i]->ptrinode-> ActualFileSize= 0;
                uareaobj.UFDT[i]->ptrinode->FileType = 0;
                uareaobj.UFDT[i]->ptrinode->RefrenceCount = 0;
                uareaobj.UFDT[i]->ptrinode->Permission =  0;

                memset(uareaobj.UFDT[i]->ptrinode->FileName,'\0',sizeof(uareaobj.UFDT[i]->ptrinode->FileName));

                //Deallocate memeory of filetable
                free(uareaobj.UFDT[i]);

                //Set Null to UFDT
                uareaobj.UFDT[i] =NULL;

                //Increment free inodes count
                superobj.FreeInodes++;

                break; // IMP

            } //End of if
        }// end of if
       
    }
     return EXECUTE_SUCCESS;
    //end of for
}//end of function




//////////////////////////////////////////////////////////////////
//
//   Function Name : WriteFile()
//   Description   : It is use to write the data into file
//   Input         : File Descriptor,Address of BufferWhich contain data,Size of data that we want to write
//   Output        : Number of bytes Succeesfully Written
//   Author        : Chaitany Dilip  Belambkar
//   Date          : 22/01/2026
//
/////////////////////////////////////////////////////////////////

int WriteFile(
               int fd,
               char*data,
               int size 
            )
{
    printf("File Descriptor : %d \n",fd);
    printf("Data that we want to write : %s \n",data);
    printf("Number of of bytes that we want to write %d\n",size);

    return 0;
}

//////////////////////////////////////////////////////////////////
//
//   Entry point function of the project
//
//////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0;
    char str[80] ={'\0'}; //command
    char Command[5][20] ={{"\0"}}; // to avoid the grabage value // tokanize kelcommand ne
    char InputBuffer[MAXFILESIZE] ={'\0'};
    int iCount = 0;   //to count the tokens


    StartAuxillaryDataInitialisation();

    printf("---------------------------------------------------\n");
    printf("----- Marvellous CVFS started successfully---------\n");
    printf("---------------------------------------------------\n");

    //Infinite listening shell
    while(1) //conditional loop // 1-indicates True
    {
        fflush(stdin);  //Buffer clean karnyasathi 

        strcpy(str,"");

        printf("\n Marvellous CVFS : > ");
        fgets(str,sizeof(str),stdin);   //formated nahi means yachatala file chi string aana 
        
        iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4]);

        printf("%d \n",iCount);
        fflush(stdin);

        if(iCount == 1)
        {
            // Marvellous CVFS : >  exit
            if (strcmp("exit",Command[0]) == 0)
            {
                printf("Thank you for Marvellous CVFS \n");
                printf("Deallocating all the allocated resources\n");
                break;
            }
            // Marvellous CVFS : >  ls
            else if(strcmp("ls",Command[0])== 0)
            {
               LsFile();
            }
            // Marvellous CVFS : >  help
            else if(strcmp("help",Command[0])==0)
            {
                DisplayHelp();
            }
            // Marvellous CVFS : > clear
            else if(strcmp("clear",Command[0])== 0)
            {
                #ifdef _WIN32
                system("cls");
                #else
                    system("clear");
                    
                #endif
            }
          

        }// End of else if 1
        else if(iCount == 2)
        {
            // Marvellous CVFS : >  man ls
            if(strcmp("man",Command[0]) == 0)
            {
                ManPageDisplay(Command[1]);
            }
            // Marvellous CVFS : >  Unlink Demo.txt file
            if(strcmp("unlink",Command[0]) == 0)
            {
                iRet=UnlinkFile(Command[1]);

                if(iRet== ERR_INVALID_PARAMETER)
                {
                    printf("INVALID PARAMETER\n");
                }
                if(iRet== ERR_FILE_NOT_EXIST)
                {
                    printf("Error : unable to delete as there is no such file\n");
                }

                if(iRet == EXECUTE_SUCCESS)
                {
                    printf("Execute the filedata Successfully\n");
                }
            }
            // Marvellous : >write 2
            else if(strcmp("write",Command[0])==0)  
            {
                printf("Enter the data that you want to write : \n");
                fgets(InputBuffer,MAXFILESIZE,stdin);

                iRet = WriteFile(atoi(Command[1]),InputBuffer,strlen(InputBuffer));
            }
            else
            {
                printf("There is no such command\n");
            }
        }// End of else if 2
        else if(iCount == 3)
        {
            // Marvellous CVFS : >  creat  Ganesh.txt 3
            if(strcmp("creat",Command[0]) == 0)
            {
               iRet = CreateFile(Command[1],atoi(Command[2]));

               if(iRet == ERR_INVALID_PARAMETER)
               {
                printf("Error : Unable to creatt the file as parameter are invalid\n");
                printf("Please refer the ManPage\n");
               }

               if(iRet == ERR_NO_INODE)
               {
                printf("Error : Unable to create file as there are no Inode\n");
               }

               if(iRet == ERR__FILE_ALREADY_EXIST)
               {
                printf("Error : Unable to create the file because this file is present\n");
               }

               if(iRet == ERR_MAX_FILES_OPEN)
               {
                printf("Error : Unable to create the file\n");
                printf("Max Open files limit reached\n ");
               }

               printf("File getssuccessfully created with fd : %d\n",iRet);


            }
          else
          {
            printf("There is no such Command\n");
          }

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
}// End of main