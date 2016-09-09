#include"../Utilities/List.h"

void DeleteNode(ListNode ** pHead,ListNode *pToBeDeleted)
{
   if(pHead==NULL || pToBeDeleted==NULL) return;

   if(pToBeDeleted->next!=NULL)  
       {
              ListNode* pNext=pToBeDeleted->next;
              pToBeDeleted->value=pNext->value;
              pToBeDeleted->next=pNext->next;

               delete pNext;
               pNext=NULL;
       }

   else if (*pHead==pToBeDeleted)
      {
                 delete pToBeDeleted;
                 pToBeDeleted==NULL;       
                 *pHead=NULL;    
      }
    else
      {
             ListNode *pNode=*pHead;
             while(pNode->next!=pToBeDeleted)
                    pNode=pNode->next;
             pNode->next=NULL;
             delete pToBeDeleted;           
             pToBeDeleted=NULL;       
      }

}

void fortest(ListNode* pHead,ListNode* pToBeDeleted)
{
    
     cout <<"before delete node:"<<endl;
     PrintList(pHead);
   
     cout <<"after delete node:"<<endl;
     DeleteNode(&pHead,pToBeDeleted);
     PrintList(pHead);
    cout <<"----------------------"<<endl;
}
void test1()
{
     ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    fortest(pNode1,pNode1);
}

void test2()
{
   ListNode* pNode1 = CreateListNode(1);

   fortest(pNode1,pNode1);  
}
 
void test3(){

    fortest(NULL,NULL);     
   
}
int main(){
test1();
test2();
test3();
return 0;
}
