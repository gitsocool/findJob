#include "iostream"
using namespace std;
int main(void){
    int E,S,W,N;//东南西北四个边界 
    int i,j,x,n;
    while(cin>>n){
        N = W = 0;
    E = S = n-1;
    int a[n][n];
    x = 1;
    while(N!=S && W!=E){
        
         for(i=N,j=W;j<=E;) a[i][j++] = x++;
         N++;
         if(N==S && W==E) break;
        
         for(i=N,j=E;i<=S;) a[i++][j] = x++;
         E--;
         if(N==S && W==E) break;
        
         for(i=S,j=E;j>=W;) a[i][j--] = x++;
         S--;
         if(N==S && W==E) break;
        
         for(i=S,j=W;i>=N;) a[i--][j] = x++;
         W++;
         if(N==S && W==E) break;
    }
    a[N][W] = x;
for(i=0;i<=n-1;i++){
    for(j=0;j<=n-2;j++){
    cout<<a[i][j]<<" "; //千万不要用ends，搞了半天通不过是因为这个。。。
    }
    cout<<a[i][n-1]<<endl;//最后一个直接换行
}
    cout<<endl;
}
    return 0;
}
