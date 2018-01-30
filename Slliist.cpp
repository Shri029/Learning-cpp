
//Single Linked List
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
class sllist{							    //List class
    
    node<T> *head,*tail;
    
    public:
    sllist(){
        
        head=tail=0;
    }
    
    int isempty();
    void addtohead(T);
    void addtotail(T);
    void insert_in_middle(int, T);
    int isinlist(T);
    T deletefromhead();
    T deletefromtail();
    void deletenode(T);
    void deleteinode(int);
    void deletelist();
    sllist<T> reverse();
    void reverse_one_pass();
    sllist<T> operator+(sllist);
    int r_length(node<T>*);
    void search(T);
    int r_search(node<T>*,T,T);
    void display();
    void nth_node(int);
    void middle_elt(); 
    void occurence_count(T);
};

template <class T>
int sllist<T>::isempty(){					    //Function to check whether list is empty or not
    
    if(head==0)
     return 1;
    else
     return 0;
}

template <class T>
void sllist<T>::display(){					    //Function to display content and length of list
    
    node<T> *temp=head;
    int len=0;
    
    while(temp!=0)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
        len++;
    }
    cout<<"\nLength (Recursively) of list is:"<<(r_length(head));   //Finding length recursively
    cout<<"\nLength (Iterative) of list is:"<<len;
}

template <class T>
void sllist<T>::addtohead(T x){                                     //Function to add element at head
    
    node<T> *temp=new node<T>(x);
    
    if(isempty())
        head=tail=temp;
    else{
        temp->next=head;
        head=temp;
    }  
}

template <class T>
void sllist<T>::addtotail(T x){                                     //Function to add element at tail
    
    node<T> *temp=new node<T>(x);
    
    if(isempty())
     head=tail=temp;
    else{
     tail->next=temp;
     tail=temp;
    }
}

template <class T>
T sllist<T>::deletefromhead(){                                     //Function to delete element from head
    
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
T sllist<T>::deletefromtail(){                                     //Function to delete element from tail
    
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
sllist<T> sllist<T>::reverse(){                                     //Function to reverse the list
    sllist<T> o1;
    node<T> *temp=head;
   
    while(temp!=0){
      o1.addtohead(temp->info);
      temp=temp->next;
    } 
    
    return o1;
}     

template <class T>
void sllist<T>:: deletenode(T x){                                     //Function to delete node of list
    
    if(!isempty()){
        if(head==tail && head->info==x){
            delete head;
            head=tail=0;
        }
        else if(head->info==x)
            deletefromhead();
        else{
            node<T> *prev,*cur;
            prev=head;
            cur=prev->next;
            
            while(cur!=0 && cur->info!=x){
                prev=cur;
                cur=cur->next;
            }
            
            if(cur!=0){
                prev->next=cur->next;
                if(tail==cur)
                 tail=prev;
                delete cur;
            }
            else
             cout<<"\nElement not found";
        }
    }
    else
     cout<<"\nList is empty";
}

template <class T>
void sllist<T>:: deleteinode(int x){
   int i=1; 
   node<T> *temp=head;
   
   while(temp!=0 && i!=x){
       i++;
       temp=temp->next;
   }
    if(i==x && temp!=0)
     deletenode(temp->info);
    else
     cout<<"\nElement does not exist";
}    

template <class T>
void sllist<T>:: insert_in_middle(int i,T x){
    
    int k=1;
    node<T> *temp=new node<T>(x);
    node<T> *prev=head;
    
    while(k!=(i-1) && prev!=0){
        k++;
        prev=prev->next;
    }
    
    if(prev!=0 && k==(i-1)){
        if(tail==prev){
            tail->next=temp;
            tail=temp;
        }
        else{
            temp->next=prev->next;
            prev->next=temp;
        }
    }
    else
     cout<<"\nPosition not found";
}

template <class T>
sllist<T> sllist<T>:: operator+(sllist<T> o1){
    
    node<T> *temp=o1.head;
    
    while(temp!=0){
        
        addtotail(temp->info);
        temp=temp->next;
    }
    return (*this);
}

template <class T>
void sllist<T>:: reverse_one_pass(){
    
    node<T> *temp1[10];
    node<T> *temp=head;
    int i,c=-1;
    
    while(temp!=0){
        temp1[++c]=temp;
        temp=temp->next;
    }
    
    for(i=c;i>0;i--)
        temp1[i]->next=temp1[i-1];
    
    temp1[i]->next=0;
    head=temp1[c];
}

template <class T>
void sllist<T>:: middle_elt(){             //Middle element
    
    node<T> *temp1[10];
    node<T> *temp=head;
    int i,c=-1;
    
    while(temp!=0){
        temp1[++c]=temp;
        temp=temp->next;
    }
    if(c%2!=0){
     for(i=c;i>c/2;i--);
      cout<<"\nMiddle element:"<<temp1[i]->info<<"\t"<<temp1[i+1]->info;
    }
    else
     for(i=c;i!=c/2;i--);
      cout<<"\nMiddle element:"<<temp1[i]->info;
}

template <class T>
int sllist<T>:: isinlist(T x)
{
    node<T> *temp=head;
    
    while(temp!=0){
        if(temp->info==x)
         return 1;
        else 
         temp=temp->next;
    }
    return 0;
}

template <class T>
int sllist<T>:: r_length(node<T> *head){                  //Finding length recursively
    
    if(head==0)
     return 0;
    else
     return 1+r_length(head->next);
    
}

template <class T>
void sllist<T>:: search(T x){
    int i;
    i=r_search(head,x,1);
    
    if(i==0)
     cout<<"\nElement not found";
    else
     cout<<"\nElement found at position:"<<i;
}

template <class T>
void sllist<T>:: nth_node(int n){    //Displaying nth element from last
    
    node<T> *temp=head;
    
    int len=r_length(head);
    
    for(int i=0;i<len-n;i++)
      temp=temp->next;
     
    cout<<"\nnth node from last is:"<<temp->info;  
}

template <class T>
void sllist<T>:: occurence_count(T x){                //Function to count occurence of an element.
    node<T> *temp=head;
    int count=0;
    
    while(temp!=0){
        if(temp->info==x)
         count++;
        temp=temp->next;
    }
    cout<<"\nElement occured "<<count<<" times.";
}

template <class T>
void sllist<T>:: deletelist(){                                  //Deleting whole list
    
    node<T> *prev=head;
    node<T> *cur=head->next;
    
    while(cur!=0){
        head=cur;
        delete(prev);
        prev=cur;
        cur=cur->next;
    }
    head=tail=0;
}
    
template <class T>
int sllist<T>:: r_search(node<T> *head, T x,T pos){   //Searching element recursively
    
    if(head==0)
     return 0;
    else if(head->info==x)
     return pos;
    else
     return r_search(head->next,x,pos+1);
    
}

int main() {
    
    sllist<int> l1,l2;
    int a,ch,e,i;
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
                
        case 6: cout<<"\nEnter the element you want to search:";
                cin>>a;
                
                e=l1.isinlist(a);
                
                if(e==1)
                 cout<<"\nElement found";
                else
                 cout<<"\nElement not found";
                break; 
        
        case 7: cout<<"\nEnter the element you want to delete:";
                cin>>a;
                l1.deletenode(a);
                break;
                
        case 8: cout<<"\nEnter the index of element you want to delete:";
                cin>>a;
                
                l1.deleteinode(a);
                break;
        
        case 9: cout<<"\nEnter the element and index where you want to insert:";
                cin>>a>>i;
                
                l1.insert_in_middle(i,a);
                break;
                
        case 10: cout<<"\nInsert in list 2";
                do{
                 cout<<"\nEnter the value:";
                 cin>>a;
                 l2.addtotail(a);
                 
                 cout<<"\nWant to insert more?";
                 cin>>c;
                }while(c=='y');
                
                l1=l1.operator+(l2);
                break;
                
        case 11:
                l1.reverse_one_pass();
                break;  
                
        case 12: cout<<"\nEnter element to be searched:";                       //Searching element
                 cin>>a;
                 l1.search(a);
                 break;
                 
        case 13: l1.middle_elt();                                               //Finding middle element
                 break;
                 
        case 14: cout<<"\nEnter the position of element from last:";            //Finding nth element from last
                 cin>>e;
                 l1.nth_node(e);
                 break;
                 
        case 15: l1.deletelist();                                               //Deleting List
                 break;
        case 16: cout<<"\nEnter the element whose occurence to be counted:";
                 cin>>e;
                 l1.occurence_count(e);
                 break;
        }        
       cout<<"\nWant to continue?";
       cin>>c; 
    }while(c=='y');
    
    cout<<"\nElements of list 1 is:";
    l1.display();
	
	return 0;
}
