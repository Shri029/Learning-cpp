// C++ code to Segregate 

#include <iostream>
using namespace std;

#define max_size 10

void display(int [],int);

//--------------------------------------Even & ODD-----------------------------------------

void SegregateEvenOdd(int a[],int n){                     
    
    int i=0,j=n-1,temp;
    
    while(i<j){
        
        while(a[i]%2==0 && i<j)             // Increase left index untill even no's is being encountered
           i++;
        while(a[j]%2==1 && i<j)             // Decrease right index untill odd no's is being encountered
           j--;
           
        if(i<j){                            // Case odd and even no's needs to be exchanged
           temp=a[i];
           a[j]=a[i];
           a[j]=temp;
           i++;j--;
        } 
    }
    cout<<"\nArray after segregateion using method 2:";
    display(a,n);
}

//--------------------------------------0's and 1's-----------------------------------------
                           //--------Method 1       O(n)----------
void Segregate01_1(int a[],int n){                     
    
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

                        //---------Method 2       O(n)----------
void Segregate01_2(int a[],int n){                     
    
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
	 
	 SegregateEvenOdd(arr,n);

	return 0;
}
