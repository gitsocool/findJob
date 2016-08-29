#include<iostream>
#include<string>
using namespace std;
bool Find(int *matrix,int rows,int columns,int objNum)
{
      bool find=false;

      if(matrix!=0 && rows>0 && columns>0)
      {   int row=0,column=columns-1;
          while(row<rows && column>=0)
             {
               if(matrix[row*columns+column]==objNum)
                 {  find=true;
                   break;
                 }
               else if(matrix[row*columns+column]>objNum)
                    --column;
             else
                 ++row;

              }


       }
      return find;
}
void fortest(string testName,int *matrix,int rows,int columns,int objNum){
    cout <<"---------"<<testName<<"---------"<<endl;
    bool find =  Find(matrix,rows,columns,objNum);

     if(find)
      cout<<" zhao dao le "<< endl;
      else
      cout<<"mei zhao dao "<<endl;

}
void test1()
{
   int a;
   cout <<" please input the number you want to find "<<endl;
   cin >>a ;
    int matrix[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    fortest("test1",(int*)matrix,4,4,a);
  }

int test7(){
    fortest("test7",0,0,0,16);
   
}
int main()
{
test1();
test7();
return 0;
}

