#include"../Utilities/List.h"
ListNode * ReverseList(ListNode *pHead)
{
       if(pHead==NULL) return NULL;

        ListNode * pFront=NULL;
        ListNode * pCur=pHead;
        ListNode * pNext=NULL;

        while(pCur->next!=NULL)
        {
             pNext=pCur->next;
           
             pCur->next=pFront;
           
              pFront=pCur;
              pCur=pNext;     
        }
      pCur->next=pFront;

    return pCur;

}
ListNode*  forTest(ListNode* pHead)
{
 
     cout<<" the original list is :"<<endl;
     PrintList(pHead);
     cout<<" after reverse the  list:"<<endl;     
     ListNode* pReverse=  ReverseList(pHead);  
     PrintList(pReverse);
     return  pReverse;
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
   
   ListNode* pReverse= forTest(pNode1);   
    DestroyList(pReverse);
}

void test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pReverse= forTest(pNode1);
   DestroyList(pReverse);
}

void test3()
{
   forTest(NULL);
} 
int main()
{
test1();
test2();
test3();
return 0;
}
