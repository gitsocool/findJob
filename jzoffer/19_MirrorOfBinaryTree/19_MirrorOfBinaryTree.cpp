#include"../Utilities/BinaryTree.h"
#include<string>
#include<stack>
using std::string;
using std::stack;
//way1
void MirrorRecursively(BinaryTreeNode* pRoot)
{
     if(pRoot==NULL) return;
      
     BinaryTreeNode* pLeft=pRoot->pLeft;
     BinaryTreeNode* pRight=pRoot->pRight;
     
     pRoot->pLeft=pRight;
     pRoot->pRight=pLeft;   
    
      MirrorRecursively(pLeft);
      MirrorRecursively(pRight); 
}
//way2
void MirrorIteratively(BinaryTreeNode* pRoot)
{
      if(pRoot==NULL) return;
     stack<BinaryTreeNode *>  stackTreeNode;
     stackTreeNode.push(pRoot);

   while(stackTreeNode.size()>0)
       {
           BinaryTreeNode* pNode=stackTreeNode.top(); 
           stackTreeNode.pop();
            BinaryTreeNode* temp=pNode->pLeft;
            pNode->pLeft=pNode->pRight;
            pNode->pRight=temp;
       
          if(pNode->pLeft)
                stackTreeNode.push(pNode->pLeft);
     
          if(pNode->pRight)
               stackTreeNode.push(pNode->pRight);
       } 
 
}
void forTest(string testName,BinaryTreeNode* pRoot)
{
    cout<<"--------------------------"<<testName<<"----------------------------------"<<endl;
    cout<<"before Mirror:"<<endl;
    PrintTree(pRoot);
     
    //way1
    // MirrorRecursively(pRoot);
     
    //way2
   MirrorIteratively(pRoot);   
     cout<<"after Mirror:"<<endl;
     PrintTree(pRoot);   
  
}
//        8
//     6      10
//   5  7    9  11
void test1()
{
   BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
   
    forTest("test1",pNode8);  
    
}

//            8
//          7   
//        6 
//      5
//   4
void test2()
{
     BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, NULL);
    ConnectTreeNodes(pNode7, pNode6, NULL);
    ConnectTreeNodes(pNode6, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode4, NULL);

    forTest("test2",pNode8);

}
//            8
//                  7   
//                       6 
//                          5
//                             4
void test3()
{

   BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, NULL, pNode7);
    ConnectTreeNodes(pNode7, NULL, pNode6);
    ConnectTreeNodes(pNode6, NULL, pNode5);
    ConnectTreeNodes(pNode5, NULL, pNode4);
    
   forTest("test3",pNode8);

}

// NULL tree
void test4()
{
  forTest("test4",NULL);

}

void test5()
{
   BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
   forTest("test5",pNode8);

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
