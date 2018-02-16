//Computing GCD iteratively

#include<iostream>
using namespace std;

int main()
{
	int x,y,r;
	cout<<"\nEnter a number:";
	cin>>x;
	cout<<"\nEnter another number:";
	cin>>y;

    r=x%y;
	while(r!=0)
	{	x=y;
     	y=r;
		r=x%y;
	}
	cout<<"\nGcd of no is:"<<y;
	
	return 0;
}