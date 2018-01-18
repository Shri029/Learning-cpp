//Selection Sort 

#include <iostream>
using namespace std;

int minm(int a[],int i,int n) //Finding Minimun
{
    if(i==n)
     return i;
    
    int k=minm(a,i+1,n);
    
    if(a[i]<a[k])
     return i;
    else
     return k;
}

void swap(int &a, int &b)   //Swapping
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void rselection_sort(int a[],int i,int n)   //Recursive
{
  if(i==n)
   return;
   
  int mini=minm(a,i,n);  
   
  if(mini!=i)
   swap(a[mini],a[i]);
   
  rselection_sort(a,i+1,n);
}

void sel_sort( int a[],int n)          //Iterative
{    
   int i,j,index=0,min;
	
	for(i=0;i<n;i++)
	{
	 min=a[i];
	 index=i;
	 for(j=i+1;j<n;j++)
	 {
	  if(min>a[j])
	  {
	   min=a[j];
	   index=j;
	  }
	 }
	 if(index!=i)
	  swap(a[index],a[i]);
	}
	
	cout<<"\nSorted array:";
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
}

int main()
{
	int a[10],i,n;
	cout<<"\nEnter the number of elements:";
	cin>>n;

	cout<<"\nEnter the array:\n";
 
	for(i=0;i<n;i++)
	 cin>>a[i];
	 
	sel_sort(a,n); 
    
    rselection_sort(a,0,n-1);
	
	cout<<"\nArray after recursie selection sort:";
	
	for(i=0;i<n;i++)
	 cout<<a[i]<<"\t";
	
	return 0;
}