//Linear Search

# include<iostream>
using namespace std;

void linear_search( int a[], int n,int search)                   //Iterative

{   
    int i,flag=0,pos=0;

	for(i=0;i<n;i++)
	{	if(a[i]==search)
		{	
                 pos=i;
		 flag=1;
		 break;
		}
	}
	if(flag==1)
	  cout<<"\nElement found at position "<<pos+1;
	else 
          cout<<"\nElement not found";
	cout<<endl;
}

int rlinear_search(int a[],int l, int n, int s)                   //Recursive
{
 if(l>n)
  return 0;
 else
  if(a[l]==s)
   return l;
 else
  return rlinear_search(a,l+1,n,s);     
}

int main()
{
	int n,a[10],i,search;

	cout<<"\nEnter the number of elements:";
	cin>>n;

	cout<<"\nEnter the elements of an array\n";
	
	for(i=0;i<n;i++)
         cin>>a[i];

	cout<<"\nEnter the element to be searched:";
	cin>>search;
	linear_search(a,n,search);
	
	n=rlinear_search(a,0,n-1,search);
	
	if(n)
	 cout<<"\nElement found at position:"<<n+1;
	else
	 cout<<"\nElement not present"; 
	
	return 0;
}

