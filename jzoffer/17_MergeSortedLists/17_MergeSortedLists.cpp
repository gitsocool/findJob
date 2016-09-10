#include"../Utilities/List.h"
#include<string>
using std::string;
/*ListNode* mergeList_1(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1==NULL && pHead2==NULL) return NULL;

     ListNode* pMergeHead=NULL;
     
     while(pHead1!=NULL || pHead2!=NULL)   
       {
          if(pHead1->value<pHead2-value)
                pMergeHead=pHead1; 
    
       }
   
}
*/

ListNode* mergeList_2(ListNode* pHead1,ListNode* pHead2)
{
     if(pHead1==NULL)
          return pHead2;
     else 
       if(pHead2==NULL) 
         return pHead1;
     ListNode * pMergeHead=NULL;
     if(pHead1->value < pHead2->value) 
        {
                pMergeHead=pHead1;
                pMergeHead->next= mergeList_2(pHead1->next,pHead2);
        }    

    else
     {
        pMergeHead=pHead2;
        pMergeHead->next= mergeList_2(pHead1,pHead2->next);

     }
 
 return pMergeHead;
}

void forTest(string testName,ListNode* pHead1,ListNode* pHead2){
   
    cout <<"-----"<<testName<<"-------"<<endl;

    ListNode* merge= mergeList_2(pHead1,pHead2);
         
    PrintList(merge);
    DestroyList(merge);

}
void test1(){
   
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    ConnectListNodes(pNode5, pNode7);


    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode8 = CreateListNode(8);
 
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);   
    ConnectListNodes(pNode6, pNode8);
  
   forTest("test1",pNode1,pNode2);
   
}

void test2()
{
  
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
    ConnectListNodes(pNode5, pNode7);


    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(7);
 
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);   
    ConnectListNodes(pNode6, pNode8);

    forTest("test2",pNode1,pNode2);
}
void test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
      forTest("test3",pNode1,pNode2); 
  
}

void test4()
{

     ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);
   forTest("test4",pNode1,NULL);

}
void test5()
{
forTest("test5",NULL,NULL);

}


int main()
{
test1();
test2();
test3();
test4();
test5();
return 0;
}
