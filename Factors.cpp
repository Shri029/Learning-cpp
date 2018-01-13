//Displaying Factors of a number

#include<iostream>
#include<cmath>
using namespace std;

void factor(int n)                                   //O(n)
{
  int i;
  cout<<"\nFactors:";
 
  for(i=1;i<=n;i++)
   if(n%i==0)
    cout<<i<<"\t";
   
  
}

void divisors(int n)							 //O(sqrt(n))
{
  int i;
  cout<<"\nDivisors:";
 
  for(i=1;i<sqrt(n)+1;i++)
  {
   if(n%i==0)
    {
	 if(n/i==i)
	  cout<<i<<"\t";
	 else
	  cout<<i<<"\t"<<(n/i)<<"\t";
    }   
  }  
  
}

void primefactors(int n)
{
  int i;
  cout<<"\nPrime Factors:";
  
  while(n%2==0)
  {
   if(n%2==0)
    cout<<2<<" ";
   n=n/2;
  }                                    //n is odd now.
  
  for(i=3;i<=sqrt(n);i+=2)             //only odd divisors need to be tested.
  {
   while(n%i==0)
   { 
    if(n%i==0)
     cout<<i<<" ";
    n=n/i;
   }
  } 
  if(n>2)                             //In case n is greater than 2.
  cout<<n;
}
int main()
{
 int n;
 cout<<"\nEnter the number:";
 cin>>n;
 
 factor(n);
 
 divisors(n);
 
 primefactors(n);
 return 0;
} 

