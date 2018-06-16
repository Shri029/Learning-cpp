#include <iostream>
using namespace std;

#define max_size 10

void display(int[],int);
int pivot(int a[],int n);

bool sum_pair(int a[],int n,int sum){
    
    int i,l,u;
    
    i=pivot(a,n);
    l=(i+1);
    u=i;
    
    for(i=0;i<n;i++){
        if(a[l]+a[u]==sum){
            cout<<"lower and upper limit:"<<l<<" "<<u;
            return true;
        }    
        else if(a[l]+a[u]<sum)
           l=(l+1)%n;
        else
           u=(n+u-1)%n;  
    }
    
    return false;
}


int pivot(int a[],int n){           //Finding pivot lowest element index
    
    int i;
    for(i=0;i<n;i++){                   
        if(a[i]>a[i+1])
        return i;
    }
}

void display(int a[],int n){       //Display function 
  int i;
  for(i=0;i<n;i++)
   cout<<"\t"<<a[i];  
}

int main() {
	int arr[max_size];
	int i,n,r;
	bool x;
	
	cin>>n;                       //Actual size of array
	
	for(i=0;i<n;i++)              //Input Array
	 cin>>arr[i];
	
	cin>>r;                       //Sum required
	
    x=sum_pair(arr,n,r);
    
    if(x)
        cout<<"\nPair Exists";
    else
        cout<<"\nPair does not exists";

	return 0;
}
