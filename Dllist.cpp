#include <iostream>
using namespace std;

template <class T>
class dnode{
	
	public:
		T info;
		dnode *prev,*next;
		
		dnode(T x, dnode *p=0, dnode *n=0){
			info=x;
			prev=p;
			next=n;
		}	
};

template <class T>
class dllist{
	
	dnode<T> *head,*tail;
	
	public:
		dllist(){
			head=tail=0;
		}
		
    int isempty();
    void addtohead(T);
    void addtotail(T);
    void display();
    T deletefromhead();
    T deletefromtail();
    dllist<T> reverse();
};

template <class T>
int dllist<T>::isempty(){
	
	if(head==0)
	  return 1;
	else
	  return 0;  
}

template <class T>
void dllist<T>::addtohead(T x){
	
	dnode<T> *temp=new dnode<T>(x);
	
	if(isempty())
	 head=tail=temp;
	else{
	 temp->next=head;
	 head->prev=temp;
	 head=temp;	
	}
}

template <class T>
void dllist<T>:: addtotail(T x){
	
	dnode<T> *temp=new dnode<T>(x);
	
	if(isempty())
	 head=tail=temp;
	else{
	 tail->next=temp;
	 temp->prev=tail;
	 tail=temp;	
	}	
}

template <class T>
void dllist<T>::display(){
	
	dnode<T> *temp=head;
	if(!isempty()){
		while(temp!=0){
			cout<<temp->info;
			temp=temp->next;
		}		
	}
	else
	 cout<<"\nList is empty!!!";
}

template <class T>
T dllist<T>::deletefromhead(){
	
	T x=head->info;
	
	if(!isempty()){
		if(head==tail){
			head=tail=0;
			delete head;
		}	
		else{
			head=head->next;
			delete head->prev;
			head->prev=0;
		}
		return x;		
	}
	else
	 cout<<"\nList is empty!!!";
}	

template <class T>
T dllist<T>::deletefromtail(){
	
	T x=tail->info;
	
	if(!isempty()){
		if(head==tail){
			head=tail=0;
			delete tail;
		}	
		else{
			tail=tail->prev;
			delete tail->next;
			tail->next=0;
		}
		return x;		
	}
	else
	 cout<<"\nList is empty!!!";
}

template <class T>
dllist<T> dllist<T>::reverse(){
	
	dllist<T> d1;
	dnode<T> *temp=head;
	if(!isempty()){
		while(temp!=0){
			d1.addtohead(temp->info);
			temp=temp->next;
		}		
	}
	else
	 cout<<"\nList is empty!!!";
	 
	return d1; 
}

int main(){
	
	dllist<int> d1,d2;
	int n,i,e;
	
	cout<<"\nNumber of characters you wan tto insert in dllist:";
	cin>>n;
/*	
	for(int i=1;i<=n;i++){
		cout<<"\nEnter the element to be added in list:";
		cin>>e;
	 	d1.addtohead(e);
	}
*/	
	for(int i=1;i<=n;i++){
		cout<<"\nEnter the element to be added in list:";
		cin>>e;
	 	d1.addtotail(e);
	}
	cout<<"\nList is:";
	d1.display();
	
//	d1.deletefromhead();
//	d1.deletefromtail();
	
	d2=d1.reverse();
	cout<<"\nList is:";
	d2.display();
	
	return 0;
}
