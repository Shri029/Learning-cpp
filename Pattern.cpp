//Program to print pyramid using *

#include <iostream>
using namespace std;

int main() {
	int i,j;
	char ch='A';

//--------------------------Half Pyramids--------------------------	

	for(i=0;i<=5;i++){                                 //Stars
	    for(j=0;j<=i;j++)
	    cout<<"*"<<"\t";
	    cout<<endl;
	}
	cout<<"\n\n\n";
	
    for(i=1;i<=5;i++){                                 //Digits
	    for(j=1;j<=i;j++)
	    cout<<j<<"\t";
	    cout<<endl;
	}
	cout<<"\n\n\n";	

    for(i=1;i<=5;i++){                                 //Alphabets
	    for(j=1;j<=i;j++)
	    cout<<ch<<"\t";
	    ++ch;
	    cout<<endl;
	}
	cout<<"\n\n\n";		
	
	for(i=5;i>0;--i){                                 //Inverted using Stars
	    for(j=i;j>0;--j)
	    cout<<"*"<<"\t";
	    cout<<endl;
	}
	cout<<"\n\n\n"; 
	
	return 0;
}
