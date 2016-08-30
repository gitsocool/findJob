#include <iostream>
#include <cstdlib>
using std::cin;
using std::endl;
using std::cout;
struct ListNode
{
    int   value;
    ListNode* next;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
   pNode->value = value;
    pNode->next = NULL;

    return pNode;
}
void  ConnectListNodes(ListNode * pCurrent,ListNode * pNext)
 {
      if(pCurrent==NULL||pNext==NULL){
          cout <<" error to add two listnodes " <<endl;          
          exit(1);
        } 

       pCurrent->next=pNext;
 }
void PrintListNode(ListNode * pNode)
{
         if(pNode==NULL)
             cout <<"the node is null "<<endl;
          else
          cout <<" the value of the node is: "<<pNode->value<<endl;
}
 
 void  PrintList(ListNode * pHead)
 {
      cout <<"start to print List"<<endl;
      ListNode * pNode=pHead;

      while(pNode!=NULL)
      {
            cout <<pNode->value<<" ";
            pNode=pNode->next;
      }   
     cout <<endl;      

 }
void DestroyList(ListNode *pHead)
{
     ListNode *pNode=pHead;
    while(pNode!=NULL)
    {
       pHead=pHead->next;
       delete pNode;
       pNode=pHead;
    } 

}
void AddToTail(ListNode **pHead,int value)
{
     ListNode* pNew=CreateListNode(value);
     if(*pHead==NULL)     
      *pHead=pNew;
     else
       { 
          ListNode *pNode=*pHead;
          while(pNode->next!=NULL)
             pNode=pNode->next;   
           pNode->next=pNew;
       }
    
}
void RemoveNode(ListNode **pHead, int value)  //remove the first node which value equals to  the  given value
{
   if(*pHead==NULL||pHead==NULL)return;
   ListNode *pToBeDeleted=NULL;
   if( (*pHead)->value==value)
    {
          pToBeDeleted=*pHead;
          *pHead=(*pHead)->next;
    }
   else 
   {
       ListNode *pNode=*pHead;
     
       while(pNode->next!=NULL && (pNode->next)->value!=value)
             pNode=pNode->next;
      if(pNode->next!=NULL && (pNode->next)->value==value)
       {
           pToBeDeleted=pNode->next;
           pNode->next=(pNode->next)->next;
       }
   }
   
  if( pToBeDeleted!=NULL )
   {
           delete  pToBeDeleted;
       pToBeDeleted==NULL;
   }

}

