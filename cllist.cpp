#include<iostream>
using namespace std;

template <class T>
class cnode{
	
	public:
	T info;
	cnode<T> *next;
	cnode(T x,cnode<T> *n=0){
		info=x;
		next=n;
	}
};

template <class T>
class cllist{
	cnode<T> *tail;
	
	public:
		cllist(){
			tail=0;
		}
	int isempty();
	void addtohead(T x);
	void addtotail(T x);
	void display();
	T deletefromhead();
	T deletefromtail();
};

template<class T>
int cllist<T>::isempty(){
	if(tail==0)
		return 1 ;
	else
		return 0 ;
}

template <class T>
void cllist<T>::addtohead(T x){
	
	cnode<T>*temp=new cnode<T>(x);
	
	if(tail==0){
		tail=temp;
		temp->next=tail;
	}
    else{
    	temp->next=tail->next;
    	tail->next=temp;
	}
}

template <class T>
void cllist<T>::addtotail(T x){
	
	cnode<T>*temp=new cnode<T>(x);
	
	if(tail==0){
		tail=temp;
		temp->next=tail;
	}
    else{
    	temp->next=tail->next;
    	tail->next=temp;
    	tail=temp;
	}
}

template <class T>
void cllist<T>::display(){

	cnode<T> *temp;
	if(!isempty()){
		temp=tail->next;
		
		do{
			cout<<temp->info;
			temp=temp->next;
		}while(temp!=tail->next);
	}
	else
	 cout<<"\nList is empty";
}

template <class T>
T cllist<T>::deletefromhead(){
	
	T x=tail->next->info;
	cnode<T> *temp;
	
	if(!isempty()){
		if(tail==tail->next){
			delete tail;
			tail=0;
		}
		else{
			temp=tail->next;
			tail->next=tail->next->next;
			delete temp;
		}
	}
    else
     cout<<"\nList is empty";
     
     return x;
}

template <class T>
T cllist<T>::deletefromtail(){
	
	T x=tail->next->info;
	cnode<T> *temp;
	
	if(!isempty()){
		if(tail==tail->next){
			delete tail;
			tail=0;
		}
		else{
			temp=tail->next;
			while(temp->next!=tail)
				temp=temp->next;
		    
		    temp->next=tail->next;
		    delete tail;
		    tail=temp;
		}
	}
    else
     cout<<"\nList is empty";
     
     return x;
}

int main(){
	
	cllist<int> c1,c2;
	int n,i,e;
	
	cout<<"\nNumber of characters you wan tto insert in cllist:";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cout<<"\nEnter the element to be added in list:";
		cin>>e;
	 	c1.addtotail(e);
	}	
	
	cout<<"\nList is";
	c1.display();
	
	c1.deletefromhead();
	c1.deletefromtail();
	
	cout<<"\nList is";
	c1.display();	
	return 0;
}

