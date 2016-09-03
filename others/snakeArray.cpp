#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
   cout<<" please input the size for the two dimension array :"<<endl;
   int n;
   while(cin >> n){
   int arr[n][n],rowMax=n-1,rowMin=0,columnMax=n-1, columnMin=0;
   int row=0,column=0,change=1;
   int assValue=1;     

    while( assValue<=n*n &&(rowMin<=rowMax) &&(columnMin<=columnMax) )
   
    { 
        switch(change)
          {
            case 1:
                 {  
                 for(;column<=columnMax;column++)
                     arr[row][column]= assValue++;
    
                      rowMin++;   
                      row++; 
                      column--;
                      change=2;
                 }
                break;
            case 2:
                 {
                     for(;row<=rowMax;row++)
                         arr[row][column]= assValue++;         
                      
                       columnMax--;
                       column--;
                       row--;
                       change=3 ;      
               }      
              break;
            case 3:      
                  {
                       for(;column>=columnMin;column--)
                        arr[row][column]= assValue++;
                    
                       rowMax--;
                       row--;
                       column++;
                       change=4;
                
                  }        
                  break; 
            case 4:           
                {
                        for(;row>=rowMin;row--)
                          arr[row][column]= assValue++;
                        
                        columnMin++;
                        column++;      
                        row++;            
                        change=1;
 
                    }
                      
                      break;
          }
    }
     
     for(int i=0;i<n;i++)
      {
         for(int j=0;j<n-1;j++)
              cout<<arr[i][j]<<" ";     
      
          cout <<arr[i][n-1]<<"\n";
       }
     cout <<endl;    
   }
return 0;    
}
