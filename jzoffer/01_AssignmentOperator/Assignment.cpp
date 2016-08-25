#include<iostream>
#include<cstring>

using namespace std;
class CMyString{
 public:
//   CMyString (); 
   CMyString ( char * pData=0);
   CMyString (const CMyString & str);
   ~CMyString(); 
    CMyString  operator = (const CMyString & str);

   void print();

  private:
    char * m_pData; 
};
//CMyString::CMyString(){

//}
CMyString::CMyString (char * pData){
      if(pData==0){
        m_pData=new char[1];
        m_pData[0]='\0';        
        }
      else{

       m_pData=new char(strlen(pData)+1);
       strcpy(m_pData,pData);        
           }

}
CMyString::CMyString(const CMyString &str){
            int len=strlen(str.m_pData);
            m_pData= new char[len+1];
            strcpy(m_pData,str.m_pData);

}
CMyString::~CMyString(){
   delete [] m_pData;
}


void CMyString::print(){
    cout<<m_pData<<endl;

}

CMyString CMyString::operator = (const CMyString & str){
       if(this!=&str){
         CMyString strTemp(str);       
         char * pre=strTemp.m_pData;
         strTemp.m_pData=m_pData;
         m_pData=pre;                       
        }

  return *this;
}
void test1(){
      cout <<"-----------test1 begin--------------"<<endl;
    char *text="waeiuhgih";
   CMyString str1(text);
   cout <<" str1 print: "; 
  str1.print();

    CMyString str2; 
    str2=str1;
    cout <<" str2 print: ";
    str2.print();
}

void test2(){
   cout <<"-----------------test2 begin-------------"<<endl;

    char *text="waeiuhg22222";
   CMyString str1(text);
   cout <<" str1 print: ";
   str1.print();
 
   str1=str1; 
   cout <<" str1 print after assign to itself: ";
   str1.print();
}

void test3(){
cout <<"-----------------test3 begin-------------"<<endl;
    char *text="waeiuhgih33333";
   CMyString str1(text),str2,str3;
   str3=str2=str1;
    cout <<" str1 print: ";
   str1.print();
   cout <<" str2 print: ";
   str2.print();
   cout <<" str3 print: ";
   str3.print();

}


int main(){
test1();
test2();
test3();
return 0;
}

