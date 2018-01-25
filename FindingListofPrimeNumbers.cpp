//Displaying Prime Numbers

#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

#define max_size 100

void prime(int n)                                   //O(n)
{
  int i,j,flag,count=0;
  cout<<"\nPrime numbers:";
 
  for(i=2;i<=n;i++)
  {
   flag=1;
   for(j=2;j<i;j++)
   {    
    if(i%j==0)
	{
	 flag=0;
	 break;
	} 
   } 	 
   if(flag==1)
   {	
	 cout<<i<<" ";
	 count++;
   }   
} 
   
  cout<<"\nTotal:"<<count;
}

void primeSoE(int n)
{
 bool prime[max_size];
 int i,p;
 memset(prime,1,sizeof(prime));
 
 for(p=2;p<=sqrt(n);p++)
 {
   if(prime[p]==1)
   {
    for(i=2*p;i<=n; i=i+p)
	  prime[i]=0;
   } 
 }
  cout<<"\nPrime numbers using SieveOfEratosthenes";
  for(p=2;p<=n;p++)
   if(prime[p])
	 cout<<p<<"\t";
	
}

int main()
{
 int n;
 cout<<"\nEnter the number:";
 cin>>n;
 
 prime(n);
 
 primeSoE(n);
 
 return 0;
} 

