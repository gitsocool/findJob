#include"../Utilities/BinaryTree.h"
#include<string>
using std::string;
bool DoesTree1HaveTree2(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2);

bool HasSubtree(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
     bool result=false;
     
    if(pRoot1!=NULL && pRoot2!=NULL)
    {
        if(pRoot1->value == pRoot2->value)
            result=DoesTree1HaveTree2(pRoot1,pRoot2);

        if(!result)
            result= HasSubtree(pRoot1->pLeft,pRoot2);
         if(!result)
            result= HasSubtree(pRoot2->pRight,pRoot1);
    }
   
   return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
      if(pRoot2==NULL)
         return true;
      if(pRoot1==NULL)
        return  false;
     
      if(pRoot1->value!=pRoot2->value)
          return false;
       
   
    return DoesTree1HaveTree2(pRoot1->pLeft,pRoot2->pLeft) 
                 &&
                 DoesTree1HaveTree2(pRoot1->pRight,pRoot2->pRight) ; 
}

void forTest(string testName,BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
   cout<<"--------"<<testName<<"-----------"<<endl;
   
   if(HasSubtree(pRoot1,pRoot2))
    cout<<" YES "<<endl;
   else
     cout<<" NO " <<endl;
  DestroyTree(pRoot1);
  DestroyTree(pRoot2);

}

void test1()
{

    BinaryTreeNode * pNode1=CreateBinaryTreeNode(8);
    BinaryTreeNode * pNode2=CreateBinaryTreeNode(8);
    BinaryTreeNode * pNode3=CreateBinaryTreeNode(7);
    BinaryTreeNode * pNode4=CreateBinaryTreeNode(9);
    BinaryTreeNode * pNode5=CreateBinaryTreeNode(2);
    BinaryTreeNode * pNode6=CreateBinaryTreeNode(4);
    BinaryTreeNode * pNode7=CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,pNode5);
    ConnectTreeNodes(pNode5,pNode6,pNode7);

    BinaryTreeNode * pNode8=CreateBinaryTreeNode(8);
    BinaryTreeNode * pNode9=CreateBinaryTreeNode(9);
    BinaryTreeNode * pNode10=CreateBinaryTreeNode(2);
 
    ConnectTreeNodes(pNode8,pNode9,pNode10);
   
    forTest("test1",pNode1,pNode8);   
  
}

void test2()
{
 BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    forTest("test2",pNodeA1,pNodeB1);

    
}

void test3()
{
   BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
    ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
    ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
    ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
    ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

   forTest("test3",pNodeA1,pNodeB1);

   
}
void test9()
{
    forTest("test9",NULL,NULL);

}
int main()
{
test1();
test2();
test3();
test9();
return 0;
}


