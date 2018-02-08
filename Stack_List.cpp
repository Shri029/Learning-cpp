
//Stack

#include <iostream>
using namespace std;

template <class T>
class node{                                                         //Node class
    
    public:
    int info;
    node *next;
    
    node(T x, node *n=0){
        info=x;
        next=n;
    }
};

template <class T>
class stack{							    //Stack class
    
    node<T> *top;
    
    public:
    stack(){
        
        top=0;
    }
    
    int isempty();
    void push(T);
    T pop();
    void display();
    int isinstack(T);
    void clear();
    void topel();
};

template <class T>
int stack<T>::isempty(){					    //Function to check whether list is empty or not
    
    if(top==0)
     return 1;
    else
     return 0;
}

template <class T>
void stack<T>::display(){					    //Function to display content and length of list
    
    node<T> *temp=top;
    int len=0;
    
    while(temp!=0)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
}

template <class T>
void stack<T>::push(T x){                       //Function to push element to stack
    
    node<T> *temp=new node<T>(x);
    
    if(isempty())
        top=temp;
    else{
        temp->next=top;
        top=temp;
    }  
}

template <class T>
T stack<T>::pop(){                                     //Function to delete element from head
    
    node<T> *temp;
    T x=top->info;
    
    if(!isempty()){
        
        if(top==temp){
            delete top;
            top=0;
        }
        else{
            temp=top;
            top=top->next;
            delete temp;
        }
        
        return x;
    }
    else
    cout<<"\nStack is already empty";
}
 
template <class T>
int stack<T>:: isinstack(T x)
{
    node<T> *temp=top;
    
    while(temp!=0){
        if(temp->info==x)
         return 1;
        else 
         temp=temp->next;
    }
    return 0;
}

template <class T>
void stack<T>:: clear(){                                  //Deleting whole list
    
    node<T> *temp=top;
    
    while(top!=0){
        temp=top->next;
        delete top;
        top=temp;
    }
}

template <class T>
void stack<T>::topel(){
    
    cout<<"top element is:"<<top->info;
}

int main() {
    
    stack<int> l1,l2;
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
                
                cout<<"\nElements of list is:";
                l1.display();
                break;
                
                
        case 2: do{
                 e=l1.pop();
                 
                 cout<<"\nDeleted element:"<<e;
                 cout<<"\nWant to delete more?";
                 cin>>c;
                }while(c=='y');
                break;
                
        case 3: cout<<"\nEnter the element you want to search:";
                cin>>a;
                
                e=l1.isinstack(a);
                
                if(e==1)
                 cout<<"\nElement found";
                else
                 cout<<"\nElement not found";
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
