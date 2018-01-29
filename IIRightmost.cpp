//Finding Second rightmost digit
#include<iostream>
using namespace std;

int main()
{ 
	int x1; float x;

	cout<<"\n Enter a number \t";
	cin>>x;

	x1=x/10;
	x1=x1%10;

	cout<<"\n Second rightmost digit of the integral portion of the floating point number:\t"<<x1;
	return 0;
}
    

