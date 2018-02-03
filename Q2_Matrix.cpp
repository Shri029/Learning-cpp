//Coin Problem
/*Approach: Since 1 insertion captures the whole row and column only diagonal elements needs to be filled.
The player with who succeds to fill maximum number of diagonal elements will win.
*/

#include <iostream>
using namespace std;

#define size 10


int main() {
   int m[size][size];
   int i,j,n;
   int count_1=0,count_2=0;
   char ch[10];
   
   cout<<"\nEnter the name of king who will donate first:- Alexander or Porus:";
   cin>>ch;
   
   cout<<"\nEnter size of matrix:";
   cin>>n;
   
   for(i=1,j=1;i<=n,j<=n;){
       
       if(i==j){                    //Filling diagonal matrix only
           m[i][j]=i;
           count_1++;
           i++;j++;
           
           if(i<=n & j<=n){
             m[i][j]=i;
             count_2++;
             i++;j++; 
           }
       }
   }
	
	if(ch=="Alexander"){
	 cout<<"\nNo of Gold coins won by Alexander is:"<<count_1;
	 cout<<"\nNo of Gold coins won by Porus is:"<<count_2;
	}
	else{
	 cout<<"\nNo of Gold coins won by Alexander is:"<<count_2;
	 cout<<"\nNo of Gold coins won by Porus is:"<<count_1;
	}
	 
	return 0;
}
