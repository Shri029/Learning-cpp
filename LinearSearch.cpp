#include<iostream>
using namespace;

int Liner_search(int a[],int i,int s,int n)
{
  int flag=0;
  for(i=0;i<n;i++)
   if(a[i]==s)
   {
    flag=1;
    break;
   }
  if(flag==1)
   return i;
  else 
   return 0;
}
int main()
{
	int a[10],i,n,s;
	cout<<"\nEnter the number of elements:";
	cin>>n;

	cout<<"\nEnter the array:\n";
 
	for(i=0;i<n;i++)
	 cin>>a[i];
   
  cout<<"\nEnter the element to be searched:";
  cin>>s;
	i=Linear_search(a,0,s,n-1);
  
  if(i)
	cout<<"Element found at position:"<<i+1;
  else
   cout<<"Element not found!!";
    
	return 0;
}
