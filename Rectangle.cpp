//Area and Perimeter of Rectangle

#include<iostream>
using namespace std;

int main()
{ 
	float len,bre;

	cout<<"\n Enter the lenght of the rectangle\t";
	cin>>len;
	cout<<"\n  Enter the breadth of rectangle\t";
        cin>>bre;

	cout<<"\n Area of rectangle is\t"<<len*bre;
	cout<<"\n Perimeter of rectangle is\t"<<2*(len+bre)<<"\n";
        
        return 0;
}