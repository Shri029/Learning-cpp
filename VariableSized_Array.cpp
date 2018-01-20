//Pointers to arrays of various sizes

#include <iostream>
using namespace std;


int main() {
    int i,j,k,q,n;
    
    cin>>n>>q;                              //Array pointers
    
    int **outer_array=new int*[n];
    
    for(i=0;i<n;i++){
      cin>>j;                              //Number of indices in jth array
        
      outer_array[i]=new int[j];           //Array of length 'j'
        
      for(k=0;k<j;k++)
         cin>>outer_array[i][k];          
    }  
    
    while(q>0){                           //Queries
      cin>>i>>j;
           
      cout<<outer_array[i][j]<<endl;     //Displaying array element
      --q;
    }
    
    return 0;
}