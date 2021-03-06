#include <iostream>
using namespace std;

template <class T ,int size=10>
class stack{
    T arr[size];
    int top;
    
    public:
    stack(){
        top=-1;
    }
    
    int isfull();
    int isempty();
    void push(T);
    T pop();
    void display();
    void clear();
    int topel();
    void r_reverse();
    void insert_reversed(T);
};

template <class T,int size>
int stack<T,size>::isfull(){
    
    if(top==size-1)
      return 1;
    else
      return 0;
}

template <class T,int size>
int stack<T,size>::isempty(){
    
    if(top==-1)
      return 1;
    else
      return 0;
}

template <class T,int size>
void stack<T,size>::push(T x){
    
    if(isfull())
     cout<<"\nStack is full";
    else
     arr[++top]=x;
}

template <class T,int size>
T stack<T,size>::pop(){
    
    T x;
    if(isempty()){
      cout<<"\nStack is empty";
      return(T)(-1);
    }
     
    else{
        x=arr[top--];
        return x;
    }
}

template <class T,int size>
int stack<T,size>::topel(){
    
    return arr[top];
}

template <class T,int size>
void stack<T,size>::clear(){
    
    top=-1;
    
}

template <class T,int size>
void stack<T,size>::r_reverse(){
    
    if(top>-1){
     int x=topel();
     
    pop();
    r_reverse();
    
    insert_reversed(x);
 }
}


template <class T,int size>
void stack<T,size>::insert_reversed(T x){
    
    if(top==-1)
     push(x);
    else{
     int e=topel();
     
     pop();
     insert_reversed(x);
    
     push(e);
    }
}

template <class T,int size>
void stack<T,size>::display(){
    
    int i;
    
    if(!isempty()){
        for(i=top;i>-1;i--)
         cout<<arr[i]<<"\t";
    }
    else
    cout<<"\nStack is empty";
}

int main() {
    
    stack<int,5> l1,l2;
    int a,ch,e,i;
    char c;
    
    do{
        cout<<"\nEnter your choice:";
        cin>>ch;
        
        switch(ch){
        case 1: do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l1.push(a);
                 
                 cout<<"\nWant to insert more?";
                 cin>>c;
                }while(c=='y');
                
                cout<<"\nElements of Stack is:";
                l1.display();
                break;
                
                
        case 2: do{
                 e=l1.pop();
                 
                 cout<<"\nDeleted element:"<<e;
                 cout<<"\nWant to delete more?";
                 cin>>c;
                }while(c=='y');
                break;
                
        case 3: l1.r_reverse();
                break; 
                
        case 4: l1.topel();
                break;        
        
        case 5: l1.clear();
                break;
        }        
       cout<<"\nWant to continue?";
       cin>>c; 
    }while(c=='y');
    
    cout<<"\nElements of stack is:";
    l1.display();
	
	return 0;
}
