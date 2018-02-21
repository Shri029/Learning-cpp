//Program to print pyramid using *

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i,j,n=5,k;
	char ch='A';

//--------------------------Half Pyramids--------------------------	

	for(i=0;i<=5;i++){                                 //Stars
	    for(j=0;j<=i;j++)
	    cout<<"*"<<"\t";
	    cout<<endl;
	}
	cout<<"\n\n\n";
	
	for(i=0;i<=5;i++){                                 //Stars
	
	    for(k=5;k>=i;k--)
	     cout<<" "; 
	    for(j=0;j<=i;j++)
	     cout<<"*";
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
	
	for(i=0;i<=5;i++){                                 //Stars
	
	    for(k=0;k<=i;k++)
	     cout<<" "; 
	    for(j=5;j>=i;j--)
	     cout<<"*";
	     cout<<endl;
	}
	cout<<"\n\n\n";

    for(i=1;i<=5;i++){                                 //Pyramid
    
        cout<<setw((n+1)-i);
	    for(j=1;j<=(2*i-1);j++)
	    cout<<"*";
	    cout<<endl;
	}
	cout<<"\n\n\n";	
	
	for(i=1;i<=5;i++){                                 //Pyramid
    
        for(int space = 1; space <= 5-i; space++)
         cout <<"\t";
	    for(j=1;j<=(2*i-1);j++)
	    cout<<j<<"\t";
	    cout<<endl;
	}
	cout<<"\n\n\n";	
	
	int rows=10, coff = 1;


    for(int i = 0; i < rows; i++){                     //Pascal's triangle
        for(int space = 1; space <= rows-i; space++)
            cout <<"  ";

        for(int j = 0; j <= i; j++){
            if (j == 0 || i == 0)
                coff = 1;
            else
                coff = coff*(i-j+1)/j;
            cout << coff << "   ";
        }
        cout << endl;
    }
   	
	return 0;
}
