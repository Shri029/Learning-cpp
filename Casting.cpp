//Casting

#include<iostream>
using namespace std;

int main()
{
 int i;float f;
 cout<<"\nEnter a float number:";
 cin>>f;
 
 i=static_cast<int>(f);
 
 cout<<"Number after casting:"<<i;
  
 return 0; 
}

