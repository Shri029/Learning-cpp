// C Program for pattern matching

#include <iostream>
#include <cstring>
using namespace std;

void match(char *pStr, char *tStr){                       //Naive way
	
	int m=strlen(pStr);
	int n=strlen(tStr);
	
	
	for(int i=0;i<=m-n; i++){
		cout<<"\nPattern found";
		for(int j=0;j<n;j++){
			
			if(pStr[i+j]!=tStr[j])
			 break;
			 
		if(j==n)
		 cout<<"\nPattern found at "<<i+1<<"th position";
		  	 
		}
	}
}

int main()
{
    char txt[] = "ThisworlsisThis";
    char pat[] = "This";
    match(pat, txt);
    return 0;
}
