
//////////////////////////Generalised Data Structure Library////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
// Structure for Singly Linear and Singly Circular
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

////////////////////////////////////////////////////////////////////////////////////////////
// Structure for Doubly Linear and Doubly Circular
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

////////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Linear Linked List

template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////

//Class of Singly Circular Linked List

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Linear Linked List

template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Circular Linked List

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////

// Singly Linear Linklist

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"\n";
}
////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: Count()
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertAtPos(T no, int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;
        First = First -> next;
        delete temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position "<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        struct nodeS<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////

// Doubly Linear Linklist

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    Last = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn; 

        First = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;
    struct nodeD<T> * temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;   
        temp->next = newn;
        newn->prev = temp;      
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)  
    {
        return;
    }
    else if((First)->next == NULL) 
    {
        free(First);
        First = NULL;
    }
    else    
    {
        First = (First) -> next;
        free((First)->prev);               
        (First)->prev = NULL;              
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeD<T> * temp = First;

    if(First == NULL)  
    {
        return;
    }
    else if((First)->next == NULL) 
    {
        free(First);
        First = NULL;
    }
    else    
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    struct nodeD<T> * temp1 = NULL;
    struct nodeD<T> * temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      
        free(temp2);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> ::  Display()
{
    struct nodeD<T> * temp = First;

    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data <<"|<=> ";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> ::  Count()
{
    struct nodeD<T> * temp = First;

    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////

// Singly Circuler Linklist

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;
    
    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else
    {
        (Last)->next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * newn = NULL;
    struct nodeS<T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        //newn = (PNODE)malloc(sizeof(NODE));
        newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeS<T> * temp = First;
    cout<<"Elements of Linked List are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeS<T> * temp = First;
    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last)    
    {
        //free(*First);
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        //free(*First);
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while(temp->next != (Last))
        {
            temp = temp->next;
        }
        //free(temp->next);
        delete temp->next;

        Last = temp;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * temp1 = First;
    struct nodeS<T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1 -> next;
        
        temp1->next = temp2->next;
        //free(temp2);
        delete temp2;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

// Doubly Circuler Linklist

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
    (First)->prev = Last;
    (Last)->next = First;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        (Last)->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    (First)->prev = Last;
    (Last)->next = First;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int iPos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((iPos < 1) || (iPos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        (First) = (First)->next;
        delete((Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        (Last) = (Last)->prev;
        delete((First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
       DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeD<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    
    cout<<"Elements are Linked List are : "<<"\n";
    do
    {
        cout<<"|  "<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
///////////////////////////////////////////////////////////////////////////////////////////
    int iRet = 0;

///////////////////////////////////////////////////////////////////////////////////////////
    
    // Singly Lenear Linked List  S
    cout<<"------------------------------------------------------------------"<<"\n";
    cout<<"---------------------Singly Linear Linked List--------------------"<<"\n";
    
    SinglyLL <int>objSLL;

    objSLL.InsertFirst(51);
    objSLL.InsertFirst(21);
    objSLL.InsertFirst(11);
    objSLL.Display();

    objSLL.InsertLast(101);
    objSLL.Display();

    objSLL.InsertLast(111);
    objSLL.Display();

    objSLL.InsertLast(121);
    objSLL.Display();

    iRet = objSLL.Count();
    cout<<"Number of elelemnts are : "<<iRet<<"\n";

///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"------------------------------------------------------------------"<<"\n";
    cout<<"---------------------Singly Circuler Linked List------------------"<<"\n";
    
    // Singly Circuler Linked List S

    SinglyCL <float>objSCL;

    objSCL.InsertFirst(51.1);
    objSCL.InsertFirst(21.1);
    objSCL.InsertFirst(11.1);

    objSCL.InsertLast(101.1);
    objSCL.InsertLast(111.1);
    objSCL.InsertLast(121.1);

    objSCL.InsertAtPos(105.1,5);

    objSCL.Display();
    iRet = objSCL.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"------------------------------------------------------------------"<<"\n";
    cout<<"---------------------Doubly Linear Linked List--------------------"<<"\n";

    // Doubly Lenear Linked List  S

    DoublyLL <int>objDLL;
    

    objDLL.InsertFirst(51);
    objDLL.InsertFirst(21);
    objDLL.InsertFirst(11);
    objDLL.Display();

    objDLL.InsertLast(101);
    objDLL.Display();

    objDLL.InsertLast(111);
    objDLL.Display();

    objDLL.InsertLast(121);
    objDLL.Display();

    iRet = objDLL.Count();
    cout<<"Number of elelemnts are : "<<iRet<<"\n";

  
///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"------------------------------------------------------------------"<<"\n";
    cout<<"---------------------Doubly Circuler Linked List------------------"<<"\n";

    // Doubly Circuler Linked List  N

    DoublyCL <int>objDCL;

    objDCL.InsertFirst(51);
    objDCL.InsertFirst(21);
    objDCL.InsertFirst(11);

    objDCL.InsertLast(101);
    objDCL.InsertLast(111);
    objDCL.InsertLast(121);
    
    objDCL.Display();
    
    objDCL.InsertAtPos(105,5);

    objDCL.Display();

    objDCL.DeleteAtPos(5);
    iRet = objDCL.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
///////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}