#include <iostream>
#include <cstring>

using namespace std;

#define maxlen 10

void ispalindrome(char str[]){
  
  int i,l;
  l=strlen(str)-1;
  
  for(i=str[0];i<l;i++,l--){
      if(str[i]!=str[l]){
        cout<<"\nNot palindrome";  
        return;
      }
  }
  cout<<"\nPalindrome";
    
}


int main() {
	char str[maxlen];
	
	cin>>str;                       //String 

    ispalindrome(str);

	return 0;
}
