#include <iostream>
#include<stack>
using namespace std;


bool finddupliacte(string str){
    
    stack<char> stk;
    int counto=0,countc=0;
    char ch,top;
    
    for( char ch: str){
        stk.push(ch);
        if(ch=='(')
         counto++;
        if(ch==')')
         countc++;
    }
     
    
    for(int i=0,ch=str[0];ch!='\0';i++){
        
        if(ch=='('){
            top = stk.top();
            stk.pop();
            
            if (top == ')'){
             counto--;countc--;
            }
            else{
                while (top != ')'){
                    top = stk.top();
                    stk.pop();
                }
            }
        }
        
        else if(counto!=countc && ch=='\0')
                return true;
        else if(counto==countc && ch=='\0')
                return true;
           return false;
        ch=str[i];
    }
}

int main() {
    
    string str = "(a+(b+(c+d)))";
 
    if (finddupliacte(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";
	
	return 0;
}
