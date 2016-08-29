#include<iostream>
#include<string>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;
void ReplaceBlank(char str[],int length)
{
      if(str==NULL||length<=0) return;
    
       int original=0;
       int blankNum=0;

      for(int i=0;str[i]!='\0';i++)
          {  ++original;
             if(str[i]==' ')
              ++ blankNum;
          }
    
      int newLen=original+blankNum*2;
      if(newLen>length) return ;
     
      int indexOfOri=original;
      int indexOfNew=newLen;

       while(indexOfOri>=0 && indexOfOri<indexOfNew)
       {

           if(str[indexOfOri]==' ')
            {
                str[indexOfNew--]='0';
                str[indexOfNew--]='2';
                str[indexOfNew--]='%';
            }
              else 
             { 
                str[indexOfNew--]=str[indexOfOri];
              }
              -- indexOfOri;
       }
     

}
void forTest(string testName,char str[], int length)
{
     cout << testName <<endl;
     ReplaceBlank(str,length);     
     
     cout<< " the result is : "<<endl;
      
     for(int i=0;str[i]!='\0';i++)
     {
       cout <<str[i] ;
     }
    cout <<endl;
 }     
void test1()
  {   const int length=100;
      char str[100],ch;
      cout <<" please input the char string "<<endl;
       int i=0;
       
       while(cin >> str[i++]);
       str[i]='\0';
       forTest("test1",str,length);            
  }

int main()

{
 test1();
return 0;
}
