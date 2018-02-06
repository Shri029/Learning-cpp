#include <iostream>
using namespace std;

#define max_size 10

void display(int[],int);

void swap(int &a, int &b){                    //Swap Function

    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int a[],int s,int n){
    
    int j,i=s-1,x=a[n];
    
    for(j=s;j<n;j++){
        
        if(a[j]<=x){
            i=i+1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[n]);
    return (i+1);
}

void quicksort(int a[],int i,int n){
    
    if(i<n){
        
        int p=partition(a,i,n);
    
        quicksort(a,i,p-1);
        quicksort(a,p+1,n);
    }
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
	
	quicksort(arr,0,n-1);
	
	cout<<"\nSorted array:";
	display(arr,n);

	return 0;
}
