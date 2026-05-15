/////////////////////////////////////////////////////////////////////
//   Generalised Data Structure Library
/////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------
 Type             name of class for node              name of class for functionality

-------------------------------------------------------------------------------------
SinglyLinear      SinglyLLLnode                        SinglyLLL        Done
SinglyCircular      SinglycLLnode                      SinglycLL

DoublyLinear      DoublyLLLnode                        DoublyLLL        Done
DoublyCircular    DoublyCLLnode                        DoublyCLL 

Stack              Stacknode                           Stack              Done
Queue              Queuenode                           Queue               Done
-------------------------------------------------------------------------------------
*/


#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////
//  Singly Linear LinkedList using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
         SinglyLLLnode <T>* next;

     SinglyLLLnode(int no)
    {
        this -> data = no;
        this -> next = NULL;
    }    
};


template <class T>
class SinglyLLL
{

    private: //Important
        SinglyLLLnode <T> *first;  //head
        int iCount;

    public:
       SinglyLLL();
        void InsertFirst(T);
        
        void InsertLast(T);
       
        void DeleteFirst();
       

        void DeleteLast();
       
        void Display();
       
        int Count();
        

        void InsertAtPos(T ,int );
        
        void DeleteAtPos(int );
       
           
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
cout<<"Object of singly LL gets created.\n";
this->first = NULL;
this->iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name :InsertFirst
// Input           :
//Output           :Nothing
// Description     :Used to insert At first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: InsertFirst(T no)
{
 SinglyLLLnode<T> * newn = NULL;

newn = new  SinglyLLLnode<T>(no);

if(first == NULL)
{
this->first = newn;
}
else
{
newn ->next = first;
this->first = newn;
}
iCount++;
}


//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertLast
// Input           :Data of node
//Output           :Nothing
// Description     :Used to insert At Last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: InsertLast(T no)
{

 SinglyLLLnode <T> * newn = NULL;
 SinglyLLLnode <T>* temp =NULL;

newn = new SinglyLLLnode<T>(no);

newn->data = no;
newn ->next = NULL;

if(first == NULL)
{
this->first = newn;
}
else
{
temp = this-> first;
while(temp -> next != NULL)
{
    temp = temp ->next;
}
temp ->next = newn;
}
iCount++;
}


//////////////////////////////////////////////////////////////////////
//
// Function name    :Deleteirst
// Input           :nothing
//Output           :Nothing
// Description     :Used to Delete At first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: DeleteFirst()
{
 SinglyLLLnode<T>* temp = NULL;

if(first == NULL)
{
    return;
}
else if(this->first ->next == NULL)  //else if(this->iCount == 1)
{
    delete this->first;
    this->first = NULL;
}
else
{
    temp = this-> first;
    first = this->first -> next;
    delete temp;
}
this->iCount--;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Delete Last
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete At Last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>::DeleteLast()
{
     SinglyLLLnode<T> * temp = NULL;

if(this->first == NULL)
{
    return;
}
else if(this->first ->next == NULL)
{
    delete first;
    this->first = NULL;
}
else
{
    temp = first;
    while(temp ->next ->next != NULL)
    {
        temp = temp ->next;
    }
    delete temp->next;
    temp ->next = NULL;
}
this->iCount--;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Display
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Display all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: Display()
{
    int iCnt = 0;
     SinglyLLLnode <T> * temp = NULL;


temp = this->first;

for(iCnt = 1;iCnt < iCount;iCnt++)  //Updated
{
    cout<<"|"<<temp->data<<"|->";
    temp = temp ->next;
}
cout<<"NULL\n";
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Noting
//Output           :Nothing
// Description     :Used to Count number of nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
int SinglyLLL<T>::Count()
{
return this->iCount;
}


//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertAtPos
// Input           :Data of node
//Output           :Nothing
// Description     :Used to Insert At any position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: InsertAtPos(T no,int pos)
{
     SinglyLLLnode <T> * temp = NULL;
     SinglyLLLnode <T> * newn = NULL;

int iCnt = 0;

if((pos < 1) || (pos > this-> iCount +1))
{
    cout<<"Invalid posistion\n";
    return;
}

if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == iCount+1)
{
    this->InsertLast(no);
}
else
{
    newn = new  SinglyLLLnode<T>(no);
    

    temp = this->first;
    
    for(iCnt = 0;iCnt <pos-1;iCnt++)
    {
        temp = temp ->next;

    }
    newn ->next = temp ->next;
    temp -> next = newn;

    this->iCount++;
}
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteAtPos
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete any position position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLLL<T>:: DeleteAtPos(int pos)
{
 SinglyLLLnode <T>* temp = NULL;
 SinglyLLLnode <T>* target = NULL;

int iCnt = 0;



if((pos < 1) || (pos >iCount ))
{
    cout<<"Invalid posistion";
    return;
}

if(pos == 1)
{
    this-> DeleteFirst();
}
else if(pos == iCount)
{
    this->DeleteLast();
}
else
{
    temp = this-> first;
    
    for(iCnt = 0;iCnt <pos-1;iCnt++)
    {
        temp = temp ->next;

    }
    target = temp ->next;

    temp ->next = target ->next;
    delete target;
    this->iCount--;
    
}
}



////////////////////////////////////////////////////////////////
//  Singly Linear LinkedList using generic Appoach
////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode <T>* next;
      

    SinglyCLLnode(T no)
    {
      this -> data = no;
      this -> next = NULL;
    }    
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode <T> *first;
        SinglyCLLnode <T> *last;
        int iCount;
    
    public:
        SinglyCLL();
        
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);

        void Display();
        int Count();

};

template<class T>
SinglyCLL <T>::SinglyCLL()
{
    cout<<"Object of SinglyCLL gets created successfully\n";
    this ->first = NULL;
    this ->last = NULL;
    this -> iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertFirst
// Input           :Data of node
//Output           :Nothing
// Description     :Used to Insert At first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL <T>:: InsertFirst(T no)
{
    SinglyCLLnode <T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this -> first ==  NULL ) && (this -> last ==NULL))
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }

    this -> last -> next = this -> first;
    this -> iCount++;


}


//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertLast
// Input           :Data of node
//Output           :Nothing
// Description     :Used to Insert At last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL <T>:: InsertLast(T no)
{
    SinglyCLLnode <T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if((this -> first == NULL) && (this -> last == NULL))
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = newn;

    }
    this -> last -> next = this -> first;
    this -> iCount++;
}



//////////////////////////////////////////////////////////////////////
//
// Function name  :DeleteFirst
// Input           :Nothing
//Output           :Nothing
// Description     :Used to delete first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: DeleteFirst()
{
    SinglyCLLnode <T> * temp = this -> first;

    if((this -> first == NULL) )
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete(this -> first);
        this -> first = NULL;
        this -> last = NULL;
    }

    else
    {
        this -> first = this -> first -> next;
        delete(temp);

        this -> last -> next = this -> first;
    }
    this -> iCount--;
}



//////////////////////////////////////////////////////////////////////
//
// Function name   : DeleteLast
// Input           :Nothing
//Output           :Nothing
// Description     :Used to delete last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL <T>:: DeleteLast()
{
    SinglyCLLnode <T> *temp = this -> first;

    if(this -> first == NULL )
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete(this -> first);
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
       this -> first = temp;
        
       while (temp ->next != this -> last)
       {
        temp = temp -> next;
       }
       
        delete this -> last;
        this -> last = temp;

        this -> last -> next = this -> first;
  
    }
    this -> iCount--;

}



//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertAtPos
// Input           :Data of node
//Output           :Nothing
// Description     :Used to Insert At any position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void  SinglyCLL <T>:: InsertAtPos(T no ,int pos)
{
    SinglyCLLnode <T> * temp = NULL;
    SinglyCLLnode <T> *newn = NULL;
    int iCnt = 0;

 

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position";
        return ;
    }

    if(pos == 1)
    {
       this -> InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
       this -> InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this -> first;

        for(iCnt = 1 ; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next = newn;

        this -> last -> next = this -> first;
        this -> iCount++;
    }

}



//////////////////////////////////////////////////////////////////////
//
// Function name  :DeleteAtPos
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete any position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void  SinglyCLL <T>::DeleteAtPos(int pos)
{
    SinglyCLLnode <T> * temp = NULL;
    int iCnt = 1;

    if((pos < 1) || (pos >  iCount))
    {
        return;
        cout<<"Invalid position";
    }

    if(pos == 1)
    {
       this -> DeleteFirst();
    }
    else if(pos == iCount)
    {
       this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp -> next;
        }

        SinglyCLLnode<T> *target = temp -> next;
        temp -> next = target->next;
        delete(target);

        this -> last ->next = this -> first;
        this -> iCount--;

    }

}


//////////////////////////////////////////////////////////////////////
//
// Function name  :DeleteAtPos
// Input           :Nothing
//Output           :Display all nodes
// Description     :Used to Display all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void   SinglyCLL <T>::Display()
{
    SinglyCLLnode <T> * temp = NULL;
    
    temp = this-> first;

    do
    {
        cout<<"| "<<temp -> data<<" |<=>";
        temp = temp -> next;
    } while(this -> first != temp);

    cout<<"\n";

}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Nothing
//Output           :Nothing
// Description     :Used to count all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
int  SinglyCLL <T>:: Count()
{
    return iCount;
}



////////////////////////////////////////////////////////////////
// Doubly  Linear LinkedList using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class DoublyLLLnode 
{
    public:

    T data;
    DoublyLLLnode*next;
    DoublyLLLnode *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first = NULL;
        int iCount; //total node
    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int); //2.alwayys int

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();


};

template <class T>
DoublyLLL <T>:: DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created successfully\n";

    this -> first = NULL;
    this -> iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name :InsertFirst
// Input           :Data of node
//Output           :Nothing
// Description     :Used to insert At first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void  DoublyLLL<T> ::InsertFirst(T no)
{
   DoublyLLLnode<T> * newn = NULL;
   newn = new DoublyLLLnode <T>(no);
   
   if(this -> first == NULL)
   {
    this ->first = newn;
   }
   else
   {
    newn -> next = this ->first;
    this -> first->prev = newn;
    this -> first = newn;
   }
   this -> iCount++;
}

//////////////////////////////////////////////////////////////////////
//
// Function name  :InsertLast
// Input           :Data of node
//Output           :Nothing
// Description     :Used to insert At Last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> ::InsertLast(T no)
{
   DoublyLLLnode<T> * newn = NULL;
   DoublyLLLnode <T>*temp = NULL;

   newn = new DoublyLLLnode<T>(no);
   
   if(this -> first == NULL)
   {
    this ->first = newn;
   }
   else
   {
        temp = this ->first;

        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }

        temp ->next = newn;
        newn ->prev = temp;
   }
   this -> iCount++;    
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :InsertAtPos
// Input           :Data of node
//Output           :Nothing
// Description     :Used to Insert At any position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;
  if((pos<1)|| pos>iCount+1)
  {
    cout<<"Invalid position";
    return;
  }
  
  if(pos == 1)
  {
    this ->InsertFirst(no);
  }
  else if(pos == iCount+1)
  {
    this->InsertLast(no);
  }
  else
  {
    newn = new DoublyLLLnode<T>(no);

    temp = this ->first;

    for(iCnt= 1;iCnt <pos -1;iCnt++)
    {
        temp = temp -> next;
    }
     newn -> next = temp -> next;
     temp -> next ->prev = newn;

     temp ->next = newn;
     newn -> prev = temp;
     this ->iCount++;
  }
 
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteFirst
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> ::DeleteFirst()
{
    
    if(this -> first == NULL)          
    {
        return;
    } 
    else if(this -> first->next ==NULL)  
    {
        delete this->first;
        this -> first  =NULL;

    }
    else                                
    {
        this -> first = this-> first->next;
        delete this ->first -> prev;
        this ->first ->prev = NULL;

    }
    this ->iCount--;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteLast
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete  Last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> :: DeleteLast()
{
   DoublyLLLnode <T> *temp = NULL;
   if(this -> first == NULL)          //LL is empty
    {
        return;
    } 
    else if(this -> first->next ==NULL)  //LL contain one node  
    {
        delete this->first;
        this -> first  =NULL;

    }
    else                                //LL contatin more than one node
    {
        temp = this -> first;

        while(temp ->next -> next != NULL)
        {
            temp = temp ->next;
        }

        delete temp ->next ;
        temp -> next = NULL;
    }
    this ->iCount--; 
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteAtPos
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete At any position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;
  if((pos<1)|| pos>iCount)
  {
    cout<<"Invalid position";
    return;
  }
  
  if(pos == 1)
  {
    this ->DeleteFirst();
  }
  else if(pos == iCount)
  {
    this->DeleteLast();
  }
  else
  {
    temp = this ->first;

    for(iCnt= 1;iCnt <pos -1;iCnt++)
    {
        temp = temp -> next;
    }

    temp ->next = temp -> next ->next;
    delete temp ->next ->prev;

    temp ->next ->prev =temp;

     this ->iCount--;
  }
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Display
// Input           :Nothing
//Output           :Nothing
// Description     :Used to display all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
void  DoublyLLL <T>::Display()
{
    DoublyLLLnode <T> *temp = NULL;
    
    temp = this-> first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp ->data<<"|<=>";
        temp = temp ->next;
    }

    cout<<"NULL\n";


}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Count number of nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template <class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;   
}



////////////////////////////////////////////////////////////////
// Doubly  Linear LinkedList using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>

class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode <T>* next;
        DoublyCLLnode <T>* prev;


    DoublyCLLnode(T no)
    {
        this -> data = no;
        this -> next = NULL;
        this -> prev = NULL;
    }    
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode <T> *first;
        DoublyCLLnode <T> *last;
        int iCount;
    
    public:
        DoublyCLL();
        
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);

        void Display();
        int Count();

};

template<class T>
DoublyCLL <T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created successfully\n";
    this ->first = NULL;
    this ->last = NULL;
    this -> iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :InsertFirst
// Input           : Data of node
//Output           :Nothing
// Description     :Used to insert first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////



template<class T>
void DoublyCLL <T>:: InsertFirst(T no)
{
    DoublyCLLnode <T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this -> first ==  NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }

    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    this -> iCount++;


}


//////////////////////////////////////////////////////////////////////
//
// Function name   :InsertLast
// Input           : Data of node
//Output           :Nothing
// Description     :Used to insert Last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL <T>:: InsertLast(T no)
{
    DoublyCLLnode <T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        this -> last -> next = newn;
        newn -> prev  = this -> last;
        this -> last = newn;

    }
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    this -> iCount++;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteFirst
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL <T>:: DeleteFirst()
{
    DoublyCLLnode <T> * temp = NULL;

    if((this -> first == NULL) && (this -> last == NULL))
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete(this -> first);
        this -> first  = NULL;
        this -> last = NULL;
    }
    else
    {
        temp = this -> first;
        this -> first = this -> first -> next;
        delete(temp);


        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }
    this -> iCount--;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :DeleteLast
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Delete last position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL <T>:: DeleteLast()
{
    DoublyCLLnode <T> *temp = NULL;

    if(this -> first == NULL && this -> last == NULL)
    {
        return;
    }
    else if(this -> first == this -> last)
    {
        delete(this -> first);
        this -> first = NULL;
        this -> last = NULL;
    }
    else
    {
        this -> last = this -> last -> prev;
        delete(this -> last -> next);

        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }
    this -> iCount--;

}


//////////////////////////////////////////////////////////////////////
//
// Function name   :InsertAtPos
// Input           : Data of node
//Output           :Nothing
// Description     :Used to insert At any  position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL <T>:: InsertAtPos(T no ,int pos)
{
    DoublyCLLnode <T> * temp = NULL;
    DoublyCLLnode <T> *newn = NULL;
    int iCnt = 0;

 

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position";
        return ;
    }

    if(pos == 1)
    {
       this -> InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
       this -> InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
        temp = this -> first;

        for(iCnt = 1 ; iCnt > pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> prev=temp -> next ;
        temp-> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;


    }

}


//////////////////////////////////////////////////////////////////////
//
// Function name   :InsertFirst
// Input           : Data of node
//Output           :Nothing
// Description     :Used to insert first position
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL <T>::DeleteAtPos(int pos)
{
    DoublyCLLnode <T> * temp = NULL;
    int iCnt = 1;

    if((pos < 1) || (pos >  iCount+1))
    {
        return;
        cout<<"Invalid position";
    }

    if(pos == 1)
    {
       this -> DeleteFirst();
    }
    else if(pos == iCount)
    {
       this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next->next;
        delete(temp -> next -> prev);

        temp -> next -> prev = temp;

    }

}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Display
// Input           :Nothing
//Output           :Displaying all nodes
// Description     :Used to display all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void  DoublyCLL <T>::Display()
{
    DoublyCLLnode <T> * temp = NULL;
    
    temp = this-> first;

   
    for(int i =0;i < this -> iCount;i++)
    {
        cout<<"| "<<temp -> data<<" |<=>";
        temp = temp -> next;
    }

    cout<<"\n";

}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Nothing
//Output           :Count all nodes
// Description     :Used to Display count of all nodes
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
int DoublyCLL <T>:: Count()
{
    return iCount;
}


////////////////////////////////////////////////////////////////
//  Stack using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next ;
    
    Stacknode(T no)
    {
        this -> data = no;
        this ->next = NULL;
    }    


};

template<class T>
class Stack
{

    private:
        Stacknode <T> *first;
        int iCount;
    
    public:
        Stack();
        
        void push(T); 
        T pop();      
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T>::Stack()
{
    cout<<"Stack gets created succeessfully...\n";
    this ->first = 0;
    this ->iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :push
// Input           :node
//Output           :Nothing
// Description     :Used to push(Insertfirst)  node in stack
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
void Stack<T>:: push(T no)
{
    Stacknode <T>*newn = NULL;

    newn = new Stacknode<T>(no);

    newn -> next = this->first;
    this ->first = newn;

    this -> iCount++;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :pop
// Input           :Nothing
//Output           :Nothing
// Description     :Used to pop(DeleteFirst,delete)  node  in stack
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
T Stack<T>:: pop()
{
    T Value = 0;
    Stacknode <T>*temp = this ->first;


    if(this -> first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    Value = this -> first -> data;
    this -> first = this -> first ->next;

    delete temp;
    this ->iCount--;

    return Value;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :peep
// Input           :Nothing
//Output           :Nothing
// Description     :Used to point  nodes in stack
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
 T  Stack<T>:: peep()
{
    T Value = 0;

    if(this -> first == NULL)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    Value = this -> first -> data;

    return Value;
   
}

//////////////////////////////////////////////////////////////////////
//
// Function name   :Display
// Input           :Nothing
//Output           : Nothing
// Description     :Used to Display  all node in stack
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T>:: Display()
{
    Stacknode <T>* temp = this->first;

    if(this -> first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp ->next;
    }
}

//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Count the all nodes in stack
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
int Stack<T>::Count()
{
    return this->iCount;
}


////////////////////////////////////////////////////////////////
//  Queue using generic Appoach
/////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode <T> *next ;
    
    Queuenode(T no)
    {
        this -> data = no;
        this ->next = NULL;

    }    


};

template<class T>
class Queue
{

    private:
        Queuenode<T> *first;
         Queuenode <T> *last;
        int iCount;
    
    public:
        Queue();
        
        void enqueue(T); 
        T dequeue();     
       
        void Display();
        int Count();
};


template<class T>
Queue<T>::Queue()
{
    cout<<"Queue gets created succeessfully...\n";
    this ->first = NULL;
    this->last = NULL;
    this ->iCount = 0;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :enqueue
// Input           :node
//Output           :Nothing
// Description     :Used to insert the node in queue
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>:: enqueue (T no)
{
  Queuenode<T> *newn = NULL;


    newn = new Queuenode<T>(no);
    if(this ->first == NULL&&(this ->last==NULL))
    {
        this -> first = newn;
        this ->last = newn;
    }
    else
    {
        this->last -> next =newn;
        this ->last = this -> last->next;

    }   
    this -> iCount++;
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :dequeue
// Input           :Nothing
//Output           :Nothing
// Description     :Used to delete the node in queue
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////


template<class T>
T Queue<T>:: dequeue()
{
    T Value = 0;
   Queuenode<T> *temp = this ->first;


    if(this -> first == NULL&&(this ->last== NULL))
    {
        cout << "Queue is empty\n";
        return -1;
    }

    Value = this -> first -> data;
    this -> first = this -> first ->next;

    delete temp;
    this ->iCount--;

    return Value;


}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Display
// Input           :Noting
//Output           :Nothing
// Description     :Used to Display the all nodes in queue
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////



template<class T>
void Queue<T>:: Display()
{
    Queuenode <T>* temp = this->first;

    if(this -> first == NULL&&(this -> last== NULL))
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp ->next;
    }
    cout<<"\n";
}


//////////////////////////////////////////////////////////////////////
//
// Function name   :Count
// Input           :Nothing
//Output           :Nothing
// Description     :Used to Count the all nodes in queue
// Author          : Chaitany Dilip Belambkar
// Name            : 6 Jan 2026
//
//////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>::Count()
{
    return this->iCount;
}


//////////////////////////////////////////End of Library////////////////////////////////////////////////////////
int main()
{

    SinglyLLL <int> *obj= new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->InsertLast(101);
    obj->InsertLast(121);
    obj->InsertLast(131);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->InsertAtPos(105,4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    delete obj;

    //////////////////////////////////////////////////////////////////////


    SinglyCLL <float> *fobj =  new SinglyCLL<float>();
    
    int fRet = 0;

    fobj->InsertFirst(11.7f);
    fobj->InsertFirst(21.8f);
    fobj->InsertFirst(51.9f);

    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";

    fobj -> InsertLast(10.3f);
    fobj -> InsertLast(20.4f);
    fobj -> InsertLast(30.5f);

    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";

    fobj -> DeleteFirst();

    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";

    fobj -> DeleteLast();
    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";


    fobj -> InsertAtPos(105.3f,4);
    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";

    fobj -> DeleteAtPos(4);

    fobj->Display();
    fRet = fobj -> Count();
    cout<<"Total number of nodes are"<<fRet<<"\n";

    delete fobj;
    ////////////////////////////////////////////////////////////////////

    DoublyLLL <char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    dobj ->InsertLast('X');
    dobj ->InsertLast('Y');
    dobj ->InsertLast('Z');

    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    dobj ->DeleteFirst();

    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    dobj ->DeleteLast();

    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    dobj -> InsertAtPos('$',4);
    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    dobj ->DeleteAtPos(4);

    dobj ->Display();
    cout<<"No of elements are :"<<dobj->Count()<<"\n";

    delete dobj;

    ////////////////////////////////////////////////////////////////


    DoublyCLL <double> *lobj =  new DoublyCLL<double>();
    
    int dRet = 0;

    lobj->InsertFirst(11.123);
    lobj->InsertFirst(21.6987);
    lobj->InsertFirst(51.2358);

    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";

    lobj -> InsertLast(10.2356);
    lobj -> InsertLast(20.789);
    lobj -> InsertLast(30.234);

    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";

    lobj -> DeleteFirst();
    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";

    lobj -> DeleteLast();

    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";


    lobj -> InsertAtPos(105.0321,4);

    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";

    lobj -> DeleteAtPos(4);

    lobj->Display();
    dRet = lobj -> Count();
    cout<<"Total number of nodes are"<<dRet<<"\n";

    delete lobj;
    ////////////////////////////////////////////////////////////////////

    Stack <char>*sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();

    cout<<"No of elements in Stack :"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is"<<sobj->peep()<<"\n";
    sobj->Display();

    cout<<"No of elements in Stack :"<<sobj->Count()<<"\n";

    cout<<"Popped element is "<<sobj->pop()<<"\n";
    sobj->Display();

    cout<<"No of elements in Stack :"<<sobj->Count()<<"\n";

    cout<<"Popped element is "<<sobj->pop()<<"\n";
    sobj->Display();

    cout<<"No of elements in Stack :"<<sobj->Count()<<"\n";

    sobj -> push('E');
    sobj->Display();

    cout<<"No of elements in Stack :"<<sobj->Count()<<"\n";
    delete sobj;


    ////////////////////////////////////////////////////////////////////


    Queue <double>*qobj = new Queue<double>();

    qobj->enqueue(11.3645);
    qobj->enqueue(21.5689);
    qobj->enqueue(51.5689);
    qobj->enqueue(101.5689);

    qobj->Display();

    cout<<"No of elements in Queue :"<<qobj->Count()<<"\n";

    cout<<"Removed element is "<<qobj->dequeue()<<"\n";
    qobj->Display();

    cout<<"No of elements in Queue :"<<qobj->Count()<<"\n";

    qobj -> enqueue(121.5689);
    qobj->Display();

    cout<<"No of elements in Queue :"<<qobj->Count()<<"\n";
    delete qobj;

    return 0;
}