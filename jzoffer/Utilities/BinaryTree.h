#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;
struct BinaryTreeNode
{
     int value;
     BinaryTreeNode *pLeft;
     BinaryTreeNode *pRight;
};
BinaryTreeNode * CreateBinaryTreeNode(int value)
{
         BinaryTreeNode *pNode=new BinaryTreeNode();
         pNode->value=value;
         pNode->pLeft=NULL;
         pNode->pRight=NULL;
   
          return  pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent,BinaryTreeNode *pLeft,BinaryTreeNode *pRight)
{
           if(pParent!=NULL)
                { 
                     pParent ->pLeft=pLeft;
                     pParent ->pRight=pRight;
                }
}

void PrintTreeNode(BinaryTreeNode *pNode)
{
       if(pNode!=NULL)
          {
           cout <<" the value of this node is :"<<pNode->value<<endl;

            if(pNode->pLeft!=NULL)  
               cout <<" the value of its left child is : "<< (pNode->pLeft)->value <<endl;
            else  
                   cout<<" left child is NULL "<<endl;

             if(pNode->pRight!=NULL)
               cout <<" the value of its right child is : "<< pNode->pRight->value <<endl;
             else
                   cout<<" right child is NULL "<<endl;
         
          }
         else
           {
             cout<<" this tree node is NULL...... "<<endl;
           }
       cout <<endl;
}
void PrintTree(BinaryTreeNode *pRoot)
{     
      PrintTreeNode(pRoot);
      if(pRoot!=NULL)
          { 
             if(pRoot->pLeft!=NULL) PrintTree(pRoot->pLeft);
             if(pRoot->pRight!=NULL) PrintTree(pRoot->pRight);
          }    

}
void DestroyTree(BinaryTreeNode *pRoot)
{
      if(pRoot!=NULL) 
        {
           BinaryTreeNode *pLeft=pRoot->pLeft;
           BinaryTreeNode *pRight=pRoot->pRight;
            delete pRoot;
            pRoot=NULL;
            DestroyTree(pLeft);
            DestroyTree(pRight);
        } 

     
}

