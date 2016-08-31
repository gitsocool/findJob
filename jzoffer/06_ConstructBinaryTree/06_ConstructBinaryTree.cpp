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
      //          std::exception("invalid input");
                 std::exception();
     }
 

     //find the root in the inorder
     int *rootInorder =startInorder;
 //     while(*rootInorder!=rootValue && rootInorder!=endInorder) ++rootInorder;
         while(rootInorder <= endInorder && *rootInorder != rootValue)
               ++ rootInorder;   
  
     // if(*rootInorder!=rootValue)
       if(rootInorder == endInorder && *rootInorder != rootValue)
            throw
     //       std::exception("invalid input");   
           std::exception();
    int leftLength=rootInorder-startInorder;
    int *leftPreorderEnd=startPreorder+leftLength;
   
     if(leftLength>0)
       {   //build the left tree of root
           root->pLeft=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);       
       }
     
     if(leftLength<endPreorder-startPreorder)
      {
            //build the right tree of root
           root->pRight=ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder); 
      }
                                
       return root;     
}

BinaryTreeNode *Construct(int *startPreorder,int *startInorder,int length)
{
         if(startPreorder==NULL||startInorder==NULL)return NULL;
          return ConstructCore(startPreorder,startPreorder+length-1,startInorder,startInorder+length-1);
}


void test()
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

void fortest(const char *testName,int *preorder,int *inorder,int length)
{  
  cout<< testName<<endl;
   try
      {
       BinaryTreeNode * root = Construct(preorder,inorder,length);        
       PrintTree(root);
       DestroyTree(root);
       }catch (std::exception& exc)
       {
       // cout <<"invalid input"<<endl;
       cout <<exc.what()<<endl; 
       }
     
}

void test1()
{
    const int  length=8;
   int preorder[length]={1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length]={4, 7, 2, 1, 5, 3, 8, 6};
      fortest("---------test1------------",preorder,inorder,length);
 
}

 void test2()
  {
    const int length =5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    fortest("--------Test2-----------", preorder, inorder, length); 
 }

void test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    fortest("-------Test3------------", preorder, inorder, length);
}

void test4()
{
    const int length=1;
    int preorder[length]={5};
    int inorder[length]={5};
   fortest("-------test4--------",preorder,inorder,length);
 
}

void test5()
{
    const int length=7;
    int preorder[length]={1,2,4,5,3,6,7};
    int inorder[length]={4,2,5,1,6,3,7};
    fortest("-------test5--------",preorder,inorder,length);

}

void test6(){

      fortest("-------test6--------",NULL,NULL,0);

}
 void test7()
 {
     const int length=7;
    int preorder[length]={1,2,4,5,3,6,7};
     int inorder[length]={4,2,8,1,6,3,7};
    fortest("-------test7--------",preorder,inorder,length);
 
 }
 

int main()
{
 test1();
 test2();
 test3();
 test4();
 test5();
 test6();
 test7();
 return 0;
}
