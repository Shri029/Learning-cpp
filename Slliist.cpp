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
    T deletefromhead();
    T deletefromtail();
    sllist<T> reverse();
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

template <class T>
T sllist<T>::deletefromhead(){
    
    node<T> *temp;
    T x=head->info;
    
    if(!isempty()){
        
        if(head==temp){
            delete head;
            head=tail=0;
        }
        else{
            temp=head;
            head=head->next;
            delete temp;
        }
        
        return x;
    }
    else
    cout<<"\nList is already empty";
}
 
template <class T>
T sllist<T>::deletefromtail(){
    
    node<T> *temp;
    T x=head->info;
    
    if(!isempty()){
        
        if(head==temp){
            delete head;
            head=tail=0;
        }
        else{
            temp=head;
            while(temp->next!=tail)
                temp=temp->next;

            delete tail;
            tail=temp;
            tail->next=0;
        }
        
        return x;
    }
    else
    cout<<"\nList is already empty";
} 
 
template <class T>
sllist<T> sllist<T>::reverse(){
    sllist<T> o1;
    node<T> *temp=head;
   
    while(temp!=0){
      o1.addtohead(temp->info);
      temp=temp->next;
    } 
    
    return o1;
}     

int main() {
    
    sllist<int> l1,l2;
    int a,ch,e;
    char c;
    
    do{
        cout<<"\nEnter your choice:";
        cin>>ch;
        
        switch(ch){
        case 1: do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l1.addtohead(a);
                 
                 cout<<"\nWant to insert more?";
                 cin>>c;
                }while(c=='y');
                
                cout<<"\nElements of list is:";
                l1.display();
                break;
                
        case 2: do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l1.addtotail(a);
                 
                 cout<<"\nWant to insert more?";
                 cin>>c;
                }while(c=='y');
                cout<<"\nElements of list is:";
                l1.display();
                break;
                
        case 3: do{
                 e=l1.deletefromhead();
                 
                 cout<<"\nDeleted element:"<<e;
                 cout<<"\nWant to delete more?";
                 cin>>c;
                }while(c=='y');
                break;
        
        case 4: do{
                 e=l1.deletefromtail();
                 
                 cout<<"\nDeleted element:"<<e;
                 cout<<"\nWant to delete more?";
                 cin>>c;
                }while(c=='y');
                break; 
                
        case 5: l2=l1.reverse();
                cout<<"\nReversed list:";
                l2.display();
                break;
                
        }        
       cout<<"\nWant to continue?";
       cin>>c; 
    }while(c=='y');
    
    cout<<"\nElements of list 1 is:";
    l1.display();
	
	return 0;
}
