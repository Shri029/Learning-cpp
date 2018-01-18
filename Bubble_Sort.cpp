# include<iostream>
using namespace std;

void bubble_sort( int a[],int n)                //Iterative
{  
 int i,j,temp;

 for(i=0;i<n-1;i++)
 {
	 for(j=0;j<n-(i+1);j++)      //Last i elements are already sorted or for(j=n;j>i;j--)
       if(a[j+1]<a[j])
	   {  
	     temp= a[j];
	     a[j]= a[j+1];
	     a[j+1]=temp;
	   }
 }
 cout<<"\nArray after Bubble sort:";
 for(i=0;i<n;i++)
	 cout<<a[i]<<"\t";
}

void rbubble_sort(int a[],int n)            //Recursive
{
    int i,temp;
    if(n==1)                  //Array size 1
     return;
     
    for(i=0;i<n-1;i++)        //Moving largest element of subarray at last.
    {
        if(a[i+1]<a[i])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=a[i];
        }
    }
    
    rbubble_sort(a,n-1);
}

int main()
{  
    int i,a[10],n;
    
	cout<<"\nEnter the size of an array:";
	cin>>n;
	
	cout<<"\nEnter the array elements";
	for(i=0;i<n;i++)
	cin>>a[i];
	
	bubble_sort(a,n);                        
	
	rbubble_sort(a,n);
	
	cout<<"\nArray after Recursive Bubble sort:";
	for(i=0;i<n;i++)
	 cout<<a[i]<<"\t";
	
	return 0;
}