#include"../Utilities/BinaryTree.h"
#include <exception>
BinaryTreeNode * ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder)
{
      /* to find the root of the tree */                   
      int rootValue =startPreorder[0];
      BinaryTreeNode *root=new BinaryTreeNode();
      root->value=rootValue;
      root->pLeft=NULL;
      root->pRight=NULL;
    
      if(startPreorder==endPreorder)
      {
            if(startInorder==endInorder && *startPreorder== *startInorder )
                 return root;
            else
              throw  
               //  std::exception("invalid input");
               std::exception();
      }
 

     //find the root in the inorder
     int *rootInorder =startInorder;
 //     while(*rootInorder!=rootValue && rootInorder!=endInorder) ++rootInorder;
         while(rootInorder < endInorder && *rootInorder != rootValue)
               ++ rootInorder;   
  
     // if(*rootInorder!=rootValue)
       if(rootInorder == endInorder && *rootInorder != rootValue)
            throw
            // std::exception("invalid input");   
            std::exception();
    int leftLength=rootInorder-startInorder;
    int *leftPreorderEnd=startPreorder+leftLength;
   
     if(leftLength>0)
       {   //build the left tree of root
           root->pLeft=ConstructCore(startInorder+1,leftPreorderEnd,startInorder,rootInorder-1);       
       }
     
     if(leftLength<endPreorder-startPreorder)
      {
            //build the right tree of root
           root->pRight=ConstructCore(leftPreorderEnd+1,endInorder,rootInorder+1,endInorder); 
      }
                                
       return root;     
}

BinaryTreeNode *Construct(int *startPreorder,int *startInorder,int length)
{
         if(startPreorder==NULL||startInorder==NULL)return NULL;
          return ConstructCore(startPreorder,startPreorder+length-1,startInorder,startInorder+length-1);
}


void test1()
{
        BinaryTreeNode *pNode1=   CreateBinaryTreeNode(11);
        BinaryTreeNode *pNode2=   CreateBinaryTreeNode(22);
        BinaryTreeNode *pNode3=   CreateBinaryTreeNode(33);
        BinaryTreeNode *pNode4=   CreateBinaryTreeNode(44);
        BinaryTreeNode *pNode5=   CreateBinaryTreeNode(55);

        ConnectTreeNodes(pNode1,pNode2,pNode3);
        ConnectTreeNodes(pNode2,pNode4,pNode5);
        PrintTree(pNode1);
        DestroyTree(pNode1);
        cout << "----after destroy the tree---"<<endl;
        PrintTree(pNode1);


}

void test2()
{  
   const int  length=8;
   int preorder[length]={1, 2, 4, 7, 3, 5, 6, 8};
   int inorder[length]={4, 7, 2, 1, 5, 3, 8, 6};
   
   try
      {
       BinaryTreeNode * root = Construct(preorder,inorder,length);        
       PrintTree(root);
       DestroyTree(root);
       }catch (std::exception& exception )
       {
       // cout <<"invalid input"<<endl;
       cout <<exception.what()<<endl; 
       }
     
}

int main()
{
test2();
return 0;
}
