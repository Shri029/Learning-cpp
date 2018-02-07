//Merger Sort

#include <iostream>
using namespace std;

#define max_size 10

void display(int[],int);

void merge(int a[],int l,int mid,int n){         //Merging sorted subarrays
    
    int i,j,k,c[max_size];
    
    i=l;                                        //Start index of left sub-array
    k=l;
    j=mid+1;                                    //Start index of right sub-array
    
    while(i<=mid && j<=n){                      //Coping smallest element from both subarrays
        
        if(a[i]<a[j]){
            c[k]=a[i];
            i++;k++;
        }
        else{
            c[k]=a[j];
            j++;k++;
        }
    }
    
    //Coping the remaining elements out of one subarray, if there exists 
    
    while(i<=mid){
        c[k]=a[i];
        i++;k++;
    }
    
    while(j<=n){
        c[k]=a[j];
        j++;k++;
    }
    
    for(i=l;i<k;i++)                        //Coping sorted array to the actual array
     a[i]=c[i];
}

void mergesort(int a[],int l,int n){
    
    if(l<n){                                            
        
        int mid=l+(n-l)/2;
        
        mergesort(a,l,mid);                 //Sorting for first half
        mergesort(a,mid+1,n);               //Sorting for second half
        
        merge(a,l,mid,n);                   //Merging two halves
    }
}

void display(int a[],int n){               //Display
  int i;
  for(i=0;i<n;i++)
   cout<<"\t"<<a[i];  
}

int main() {
	int arr[max_size];
	int i,n,r;
	
	cin>>n;                              //Actual size of array
	
	for(i=0;i<n;i++)                    //Input Array
	 cin>>arr[i];
	
	mergesort(arr,0,n-1);
	
	cout<<"\nSorted array:";
	display(arr,n);

	return 0;
}
