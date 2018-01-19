#include <iostream>
using namespace std;

#define size 10

void i_reverse(int a[],int n)                  //Iterative
{
    int i;
    
    for(i=0;i<=n;i++,n--)
      swap(a[i],a[n]);
        
}

void r_reverse(int a[],int s,int n)           //Recursive
{
  if(s>=n)                                   //Indices overlap
   return;
  
  swap(a[s],a[n]);
  
  r_reverse(a,s+1,n-1);                      //Recursing for remaining elements
}

void p_reverse(int a[],int n)                //Iterative
{
    int temp;
    int *s;
    int *l=a+n;
    
    for(s=a;s<=l;s++,l--)
      swap(*s,*l);
        
}
void swap(int &a, int &b)                    //Swap Function
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void display(int a[],int n)                 //Display Function
{
   int i;
   
   for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
}

int sum(int a[], int n)
{
  int i,sum=0;    
  
  for(i=0;i<n;i++)
   sum+=a[i];                                //Adding element of position i at each iteration.
   
  cout<<"\nSum of elements:"<<sum; 
}

int main() {
	int a[size],i,n;
	int *p;
	
	cout<<"\nEnter the size of an array:\t:";
	cin>>n;
    
	cout<<"\nEnter elements of an array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
		
	p=a;                                     //Assigining address of array a
	
	sum(a,n);
	
	i_reverse(a,n-1);
	cout<<"\nArray after iterative reverse:";   
	display(a,n);
	i_reverse(a,n-1);
	
	r_reverse(a,0,n-1);
	cout<<"\nArray after reversing recursively:";
	display(a,n);
	r_reverse(a,0,n-1);
	
	p_reverse(a,n-1);
	cout<<"\nArray after reversing using pointers:";
	display(a,n);
	
	return 0;
}
