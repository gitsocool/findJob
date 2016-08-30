#include <iostream>
#include <cstdlib>
//using namespace std;
using std::cin;
using std::endl;
using std::cout;

struct ListNode 
{
    int value;
    ListNode *next;
};

ListNode* CreateListNode(int value)
{
       ListNode* pNode=new ListNode();
       pNode->value=value;
       pNode->next=NULL;
      
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
/*void AddToTail2(ListNode *pHead,int value)
{
     ListNode* pNew=CreateListNode(value);
     if(pHead==NULL)
      pHead=pNew;
     else
       {
          ListNode *pNode=pHead;
          while(pNode->next!=NULL)
             pNode=pNode->next;
           pNode->next=pNew;
       }

}*/
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
void RemoveNode2(ListNode **pHead, int value)  //remove the first node which value equals to  the  given value
{
   if(pHead==NULL||*pHead==NULL) return;
   ListNode *pToBeDeleted=NULL;
   ListNode *pPre=*pHead;
   if( (*pHead)->value==value ) 
      {
       pToBeDeleted=*pHead;    
       *pHead=(*pHead)->next;  
     } 
   else 
     { 
  //     ListNode *pPre=*pHead;
       ListNode *pNode=(*pHead)->next;
        
        while(pNode->value!=value && pNode->next!=NULL) { pPre=pNode;pNode=pNode->next;}
        
         if( pNode->value==value )
           { 
                 pToBeDeleted=pNode;
                 if(pNode->next!=NULL)
                 {
                      pPre=pNode;
                      pNode=pNode->next;
                  }
          } 
       
      }
          if(pToBeDeleted!=NULL)
                {
               pPre->next=pToBeDeleted->next;
                delete pToBeDeleted;
                pToBeDeleted=NULL;
               }

}
void test1()
{
  cout << "-------------test1----------------"<<endl;
  ListNode* pNode1 = CreateListNode(100);
  ListNode* pNode2 = CreateListNode(200);
  ListNode* pNode3 = CreateListNode(300);
  ListNode* pNode4 = CreateListNode(400);
  ListNode* pNode5 = CreateListNode(500);
   ListNode* pNode6 = CreateListNode(600);
  
    delete pNode6;
 
   ConnectListNodes(pNode1,pNode2);
   ConnectListNodes(pNode2,pNode3);
   ConnectListNodes(pNode3,pNode4);
   ConnectListNodes(pNode4,pNode5);
   ConnectListNodes(pNode5,pNode6);
    
  
    PrintList(pNode1);

    DestroyList(pNode1);   
   
}
void test2()
{
   cout << "--------test2-------------"<<endl;

  ListNode* pNode1 = CreateListNode(10);
  ListNode* pNode2 = CreateListNode(20);
  ListNode* pNode3 = CreateListNode(30);
  ListNode* pNode4 = CreateListNode(40);
  ListNode* pNode5 = CreateListNode(50);


   ConnectListNodes(pNode1,pNode2);
   ConnectListNodes(pNode2,pNode3);
   ConnectListNodes(pNode3,pNode4);
   ConnectListNodes(pNode4,pNode5);

   AddToTail(&pNode1,88);
   PrintList(pNode1);
   DestroyList(pNode1);  

}
/*void test3()
{
     cout << "--------test3-------------"<<endl; 
    ListNode* pNode1 = CreateListNode(10);
 //      delete pNode1;
   AddToTail2(pNode1,88);
   PrintList(pNode1);
   DestroyList(pNode1);

}
*/

void test4()
{
  cout << "-------------test4----------------"<<endl;
  ListNode* pNode1 = CreateListNode(11);
  ListNode* pNode2 = CreateListNode(22);
  ListNode* pNode3 = CreateListNode(33);
  ListNode* pNode4 = CreateListNode(44);
  ListNode* pNode5 = CreateListNode(55);
    
   ConnectListNodes(pNode1,pNode2);
   ConnectListNodes(pNode2,pNode3);
   ConnectListNodes(pNode3,pNode4);
   ConnectListNodes(pNode4,pNode5);


    PrintList(pNode1);
 
    RemoveNode(&pNode1,33); 
  cout <<"print again:"<<endl;
   PrintList(pNode1);
 
  
    DestroyList(pNode1);

}


 int main() 
{
   test1();
 //  test2();
 // test3();
 test4();
   return 0;
}
