#include <iostream>
using namespace std;

#define size 10

void duplicate(int a[],int n)
{
    int i,j,count=0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
       if(a[i]==a[j]){
         cout<<"\nDuplicate element:"<<a[i];
         count++;
         break;
        }
       }
    }
    if(!count)
     cout<<"\nNo duplicates";
}


int main() {
	int a[size],i,n;
	
	cout<<"\nEnter the size of an array";
	cin>>n;
    
	cout<<"\nEnter elements of an array\n";
	for(i=0;i<n;i++)
	  cin>>a[i];
		
	duplicate(a,n);
	
	return 0;
}
