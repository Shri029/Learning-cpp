//Printing Fibonacci series

#include<iostream>
using namespace std;

int fib(int n)               //Recursive
{
 if(n==0 || n==1)
  return n;
  
 else 
  return fib(n-1)+fib(n-2);  
}

void iterative_fib(int n)          //Iterative
{
 int i, fn[100];
 
 fn[0]=0;
 fn[1]=1;
 
 cout<<0<<"\t";
 cout<<1<<"\t";
 for(i=2;i<n;i++)
 {
  fn[i]=fn[i-1]+fn[i-2];
  cout<<fn[i]<<"\t";
 } 
}

int main()
{
 int n,i,f;
 cout<<"\nEnter number of terms:";
 cin>>n;
 
 cout<<"\nFibnonacci series using recursive method:";
 for(i=0;i<n;i++)
 {
   f=fib(i);
   cout<<f<<"\t";
 } 
 cout<<"\nFibnonacci series using iterative method:";
 iterative_fib(n); 
 return 0;
} 

