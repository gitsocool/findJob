#include "../Utilities/List.h"
ListNode *FindKthToTail(ListNode * pHead,unsigned int k)
{
     if(pHead==NULL or k<=0 )  return NULL;
      
      auto p1=pHead,p2=pHead;
      for(int i=1;i!=k;i++)
         { if(p1->next!=NULL)
               p1=p1->next;
           
           else
             return NULL;
          }
     
     for(;p1->next!=NULL;p1=p1->next)
          p2=p2->next;
 

    return p2;      
}

void forTest()
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
 
    cout <<" print the list :"<<endl;
    PrintList(pNode1);
   
    unsigned int k;
    cout <<" input the Kth to tail that you want"<<endl;
    while(cin>>k)
    {
    ListNode* pFind=  FindKthToTail(pNode1,k);  
    //ListNode* pFind=  FindKthToTail(NULL,k);
    PrintListNode(pFind);
    }
   
    
}
int main()
{
 forTest();
 return 0;
}
