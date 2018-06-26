#include <bits/stdc++.h>

using namespace std;

bool isPair(char a, char b){                                                    //Function to check matching pair
    
    if(a=='(' && b==')')
        return true;
    else if(a=='{' && b=='}')
        return true;
    else if(a=='[' && b==']')
        return true;
    else 
        return false;
}

/* Traverses the given expression to check matching parenthesis */
bool areBalanced(string expression){
    
    stack<char> s;
    int i=0;
    char ch,c;
    
    while(expression[i]){
        
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')      //Push start expression
            s.push(expression[i]);
        if(expression[i]==')' || expression[i]==']' || expression[i]=='}'){     //Pop ending parenthe and if its matching
            if(s.empty())
                return false; 
            else if(s.top()){
                c=s.top();s.pop();
                if(!isPair(c, expression[i])) 
                    return false;
            }               
        }
        i++; 
  }
    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    int t;
    string expression;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {   
        getline(cin, expression);

    if(areBalanced(expression))
        cout<<"YES";
    else
        cout<<"NO";
      
    cout<<"\n";
    } 
    return 0;
}

/* 
    Sample Input
    3
    {[()]}
    {[(])}
    {{[[(())]]}}
*/    
