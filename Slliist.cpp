//Single Linked List

#include <iostream>
using namespace std;

template <class T>
class node{
    
    public:
    int info;
    node *next;
    
    node(T x, node *n=0){
        info=x;
        next=n;
    }
};

template <class T>
class sllist{
    
    node<T> *head,*tail;
    int c;
    
    public:
    sllist(){
        
        head=tail=0;
        c=-1;
    }
    
    int isempty();
    void addtohead(T);
    void addtotail(T);
    void display();
};

template <class T>
int sllist<T>::isempty(){
    
    if(head==0)
     return 1;
    else
     return 0;
}

template <class T>
void sllist<T>::display(){
    
    node<T> *temp=head;
    
    while(temp!=0)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
}

template <class T>
void sllist<T>::addtohead(T x){
    
    node<T> *temp=new node<T>(x);
    
    if(isempty())
        head=tail=temp;
    else{
        temp->next=head;
        head=temp;
    }  
}

template <class T>
void sllist<T>::addtotail(T x){
    
    node<T> *temp=new node<T>(x);
    
    if(isempty())
     head=tail=temp;
    else{
     tail->next=temp;
     tail=temp;
    }
}

int main() {
    
    sllist<int> l1;
    int a,ch;
    char c;
    
    
    
    
    do{
        cout<<"\nEnter your choice:";
        cin>>ch;
        
        switch(ch){
        case 1: do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l1.addtohead(a);
                }while(c=='y');
                break;
        case 2: do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l1.addtotail(a);
                }while(c=='y');
                break;
        }        
        
    }while(c=='y');
    
    cout<<"\nElements of list is:";
    l1.display();
	
	return 0;
}
