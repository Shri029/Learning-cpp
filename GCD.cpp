//Computing GCD iteratively

#include<iostream>
using namespace std;

int gcd(int a,int b){  //Recursive Method
    
   	if(b==0)
     	 return a;
    	else 
      	 return gcd(b,a%b);
}

int main()
{
	int x,y,r;
	cout<<"\nEnter a number:";
	cin>>x;
	cout<<"\nEnter another number:";
	cin>>y;

   	r=x%y;
	while(r!=0){
	  x=y;
     	  y=r;
	  r=x%y;
	}
	cout<<"\nGcd of no is:"<<y;
	cout<<"\nGcd of no is:"<<gcd(x,y);  //Recursive
	return 0;
}
