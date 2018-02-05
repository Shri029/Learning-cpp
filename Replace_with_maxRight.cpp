// C++ code to Segregate 

#include <iostream>
using namespace std;

#define max_size 10

void display(int [],int);

void max_frm_right1(int a[],int n){
    
    int i,j,k,max=a[0];
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
           if(a[j]>max){
               max=a[j];
           }
        }
        if(a[i]!=max)
           a[i]=max;
        max=-1;
    }
    a[n-1]=-1;
    
    cout<<"\nArray after replacement:";
    display(a,n);
}

void max_frm_right2(int a[],int n){
    
    int i,temp,max=a[n-1];
    
    a[n-1]=-1;
    
    for(i=n-2;i>=0;i--){
    
        temp=a[i];
        a[i]=max;
        
        if(max<temp)
         max=temp;
    }
    
    cout<<"\nArray after replacement:";
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
	 
//	 max_frm_right1(arr,n);
     max_frm_right2(arr,n);
     
	return 0;
}
