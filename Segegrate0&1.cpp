// C++ code to Segregate 0s and 1s in an array

#include <iostream>
using namespace std;

#define max_size 10

void display(int [],int);

void Segregate01_1(int a[],int n){                      //Method 1       O(n)
    
    int i,j=0,count=0;
    
    for(i=0;i<n;i++){
        if(a[i]==0){                                   // Loop fills the arr with 0 until count
            a[j++]=0;
            count++;                                   // Counts the no of zeros in array
        }
    }
    
    for(i=count;i<n;i++){                              // Loop fills remaining array space with 1
        a[i]=1;
    }
    
    cout<<"\nArray after segregateion using method 1:";
    display(a,n);
}

void Segregate01_2(int a[],int n){                      //Method 2      O(n)
    
    int i=0,j=n-1;
    
    while(i<j){
        
        while(a[i]==0 && i<j)                          // Increase left index untill 0 is being encountered
           i++;
        while(a[j]==1 && i<j)                          // Decrease right index untill 1 is being encountered
           j--;
           
        if(i<j){                                       // Case when 0 & 1 needs to be exchanged
           a[i]=0;
           a[j]=1;
           i++;j--;
        } 
    }
    cout<<"\nArray after segregateion using method 2:";
    display(a,n);
}

void display(int a[],int n){          //display
  int i;
  for(i=0;i<n;i++)
   cout<<"\t"<<a[i];  
}

int main() {
	int arr[max_size];
	int i,n,r;
	
	cin>>n;                       //Actual size of array
	
	for(i=0;i<n;i++)              //Input Array
	 cin>>arr[i];
	 
	 Segregate01_1(arr,n);
	 Segregate01_2(arr,n);

	return 0;
}
