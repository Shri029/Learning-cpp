//Below code is reordering an array according to an index array

#include<iostream>
#include<ctime>

using namespace std;

#define size 10


void reorder(int a[],int in[],int n){
    
    int i,temp[size];
    
    for(i=0;i<n;i++)                          //Reordering in tempeorary array
      temp[in[i]]=a[i];
      
    for(i=0;i<n;i++)                         //Copying to original array
     a[i]=temp[i];
}

int main() {
	int a[size],in[size],i,n;
	int *p;
	
	cout<<"\nEnter the size of an array:\t:";
	cin>>n;
    
	cout<<"\nEnter elements of an array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	
	cout<<"\nEnter indices for array between 0-size\n";
	for(i=0;i<n;i++)
		cin>>in[i];
		
	reorder(a,in,n);
	
	cout<<"\nNew array\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}		
