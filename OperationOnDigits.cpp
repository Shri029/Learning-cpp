//Sum and Product of Digits

# include<iostream>
using namespace std;

void main()
{ 
  int d1, d2, d3, x, x1, sum, prod;
 
  cout<<"\n Enter a 3 digit number:";
  cin>>x;
  
  d1= x%10;
  
  x1=x/10;
  cout<<"\n first Digit is:\t"<<d1;
   d2= x1%10;
  cout<<"\n Second Digit is:\t"<< d2;

   x1=x1/10;
   d3=x1%10;
  cout<<"\n Third digit is:\t"<<d3;

  sum= d1+d2+d3;
  cout<<"\n sum of digits is\t"<<sum;
 
  prod=d1*d2*d3;
  cout<<"\n product of digits is\t"<<prod<<"\n";

}
