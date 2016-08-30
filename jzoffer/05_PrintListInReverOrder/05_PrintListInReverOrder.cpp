#include "../Utilities/List.h"
#include<stack>
void PrintListInReversing_Iteratively(ListNode *pHead)
{
     if(pHead==NULL)return ;
      ListNode * pNode=pHead;
      std::stack<ListNode*>  nodes;
     while(pNode!=NULL) 
      {
         nodes.push(pNode);  
         pNode=pNode->next; 
      }    
    
      while(!nodes.empty())
      {  
         pNode=nodes.top();        
        cout << pNode->value <<" ";
        nodes.pop();
      }
      cout<<endl;
    
}
void PrintListInReversing_Recursively(ListNode* pHead)
{
    if(pHead!=NULL)
      {
         if(pHead->next!=NULL)  PrintListInReversing_Recursively(pHead->next);        
         cout <<pHead->value<<" ";
       }
    cout<<endl; 
}
void test1()
{
  cout << "-------------test1----------------"<<endl;
  ListNode* pNode1 = CreateListNode(100);
  ListNode* pNode2 = CreateListNode(200);
  ListNode* pNode3 = CreateListNode(300);
  ListNode* pNode4 = CreateListNode(400);
  ListNode* pNode5 = CreateListNode(500);
  
   ConnectListNodes(pNode1,pNode2);
   ConnectListNodes(pNode2,pNode3);
   ConnectListNodes(pNode3,pNode4);
   ConnectListNodes(pNode4,pNode5);
 
    PrintListInReversing_Iteratively(pNode1);   
    PrintListInReversing_Recursively(pNode1); 
    DestroyList(pNode1);   
   
}
void test2()
{
     cout << "-------------test2----------------"<<endl;
     ListNode* pNode1 = CreateListNode(99);
    
      PrintListInReversing_Iteratively(pNode1);
      PrintListInReversing_Recursively(pNode1);
      DestroyList(pNode1);

}

void test3()
{
      cout << "-------------test3----------------"<<endl;
      ListNode* pNode1 = NULL;
 
      PrintListInReversing_Iteratively(pNode1);
      PrintListInReversing_Recursively(pNode1);
      DestroyList(pNode1);

}
int main()
{
     test1(); 
     test2();
     test3();
     return 0;

}
