//Reversing Queue using Stack

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> s1, s2;   
        void push(int x) {
            
                 s1.push(x);
        }

        void pop() {
            
            int x;
            if(s1.empty() && s2.empty())
               return ;
            
            if(s2.empty()){
             while(!s1.empty()){  
                x=s1.top();
                s1.pop();
                s2.push(x);
             }    
            }
            x=s2.top();                 //Removing top element
            s2.pop();
        }

        int front() {
        
            int x;
            if(s1.empty() && s2.empty())
                return -1;
            
            if(s2.empty()){
               while(!s1.empty()){  
                x=s1.top();
                s1.pop();
                s2.push(x);
             }   
            }
            x=s2.top();               //Accessing top element
            return x;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
