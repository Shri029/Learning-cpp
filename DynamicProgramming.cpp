#include <iostream>
#include<algorithm> 
#include <cstring>
using namespace std;

int max(int a,int b){
    
    if(a>b)
        return a; 
    else
        return b;
}

int min1(int a, int b){
    return a < b ? a : b; 
}

int min(int a,int b,int c){
    
    return min(min(a,b),c);
}

int lcs(char *x, char *y,int m,int n){                      //Recursive Longest Common Subsequence
    
    if(m==0 || n==0)
        return 0;
        
    if(x[m-1]==y[n-1])
        return 1 + lcs(x, y, m-1,n-1);
        
    else
        return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
}

string lcsPrint(char *x, char *y,int m,int n){              //Recursive Longest Common Subsequence Print
    
    if(m==0 || n==0)
        return " ";
        
    if(x[m-1]==y[n-1])
        return lcsPrint(x, y, m-1,n-1) + x[m-1];
        
    if(lcsPrint(x,y,m,n-1)> lcsPrint(x,y,m-1,n))
        return lcsPrint(x,y,m,n-1);
        
    else
       return lcsPrint(x,y,m-1,n);
}

int lcsI(char *x, char *y,int m,int n){                      //Iterative Longest Common Subsequence
    
    int Opt[m+1][n+1];
    int i,j;
    
    for(i=0;i<=m;i++){
     for(j=0;j<=n;j++){
        
        if(i==0 || j==0)
         Opt[i][j]=0;
        
        else if(x[i-1]==y[j-1])
         Opt[i][j]= 1 + Opt[i-1][j-1];
         
        else
         Opt[i][j]= max(Opt[i][j-1], Opt[i-1][j]); 
      }
    }  
    
    return Opt[m][n];
}

// No of opertaions(Insert,Remove,Replace) required to make two strings similar

int editDistance(char *x, char *y,int m,int n){
    
    int Opt[m+1][n+1];
    int i,j;
    
    for(i=0;i<=m;i++){
     for(j=0;j<=n;j++){
        
        if(i==0 ) //Minimum J operations 
            Opt[i][j]=j;
         
        else if(j==0)  //Minimum i operations
            Opt[i][j]=i;
            
        else if(x[i-1]==y[j-1])
            Opt[i][j]= 1 + Opt[i-1][j-1];
         
        else
            Opt[i][j]= min(Opt[i][j-1],     //Insert
                           Opt[i-1][j],     //Remove
                           Opt[i-1][j-1]);  //Replace
      }
    }  
    
    return Opt[m][n];
}

unsigned long int catalanNum(unsigned int n){           //Catalan Numbers
    
    unsigned long int cat[n+1];
    int i,j;
    
    cat[0]=cat[1]=1;
    
    for(i=2;i<=n;i++){
        cat[i]=0;
        for(j=0;j<i;j++)
            cat[i]+=cat[j]*cat[i-j-1];
            
    //       cout<<cat[i]<<" ";                                 Output: 1,1,3,5,14,42..
    }
    
    return cat[n];
}

int main() {

    char x[]="ACGTGGACTACGT";
    char y[]="TGGACACGT";
    int m,n;
   
    m=strlen(x);
    n=strlen(y);
    
    cout<<"\nLongest Common Subsequence : "<<lcsPrint(x,y,m,n);
    cout<<"\nLongest Common Subsequence Length: "<<lcs(x,y,m,n);
    cout<<"\nLongest Common Subsequence Length: "<<lcsI(x,y,m,n);
    
    cout<<"\nMinimum Operations required: "<<editDistance(x,y,m,n);
    
    cout<<"\nCatalan Number: "<<catalanNum(5);
    
    
    
	return 0;
}
