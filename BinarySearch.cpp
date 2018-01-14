//Binary Search

#include<iostream>
using namespace std;

void binary_search(int a[],int n,int s)          //Iterative
{
 int first,mid,last;
 first=0;last=n-1;
 mid=(first+last)/2;
 
 while(first<=last)
 {
  if(a[mid]==s)
  {
    cout<<"\nElement found at position:"<<mid+1;
	break;
  }
  else if(a[mid]<s)
   first=mid+1;
  else
   last=mid-1;
   
  mid=(first+last)/2;  
 }
  if(first>last)
   cout<<"\nElement not found";
}

int rbinary_search(int a[],int f,int n,int s)        //Recursive
{
 int mid=(f+n)/2;
 if(f>n)
  return 0;
 else if(a[mid]==s)
  return mid;
 else if(a[mid]<s)
  return rbinary_search(a,mid+1,n,s);                //left subarray
 else 
  return rbinary_search(a,f,mid-1,s);                //right subarray
}
int main()
{
   int n,a[10],i,search;
   cout<<"\nEnter the number of elements for array:";
   cin>>n;

   cout<<"\nEnter the elements of an array\n";
	
   for(i=0;i<n;i++)
         cin>>a[i];

	cout<<"\nEnter the element to be searched:";
	cin>>search;
	binary_search(a,n,search);
	
	n=rbinary_search(a,0,n-1,search);
	
	if(n)
	 cout<<"\nElement found at position:"<<n+1;
	else
	 cout<<"\nElement not present";
	
    return 0;
}

