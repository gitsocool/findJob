#include "../Utilities/BinaryTree.h"
#include<deque>
using std::deque;
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
      if(pRoot==NULL) return;
       deque<BinaryTreeNode*> deq;
       deq.push_back(pRoot);

      while(!deq.empty())
      {
          BinaryTreeNode* pNode=deq.front();
          deq.pop_front();
            
         cout<<pNode->value<<endl;

          if(pNode->pLeft!=NULL)
              deq.push_back(pNode->pLeft);
      
            if(pNode->pRight!=NULL)
              deq.push_back(pNode->pRight);   
     
       }
    
}

void forTest()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);
    PrintTreeNode(pNode10);
    cout<<"The nodes from top to bottom, from left to right are:"<<endl; 
    PrintFromTopToBottom(pNode10);    
}

int main()
{
forTest();
return 0;
}

