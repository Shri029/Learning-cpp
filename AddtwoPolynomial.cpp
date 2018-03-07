//Adding two polynomials using linked lists

#include <iostream>
using namespace std;

template <class T>
class node{
	public:
		T info;
		int power;
		node *next;
		
		node(T x, int p,node *n=0){
			info=x;
			power=p;
			next=n;
		}
};

template <class T>
class poly{
	
	node<T> *head,*tail;
	
	public:
	poly(){
		head=tail=0;
	}
	
	int isempty(){
		if(head==0)
		 return 1;
		else
		 return 0;
	}
	
	void insert(T x,int p);
	void display();
	poly<T> addpoly(poly<T>);
};

template <class T>
void poly<T>::insert(T x,int p){
	
	node<T> *temp=new node<T>(x,p);
	
	if(isempty())
	  head=tail=temp;
	else{
		
		tail->next=temp;
		tail=temp;
	} 
}

template <class T>
void poly<T>::display()
{
	node<T> *temp;
	temp=head;

	while(temp!=0)
	{
		cout<<temp->info<<"x^"<<temp->power<<"  ";
		temp=temp->next;
	}
}

template <class T>
poly<T> poly<T>::addpoly(poly<T> p1){
	
	node<T> *temp=head;
	node<T> *temp1=p1.head;
	
	poly<T> s;
	
	while(temp!=0 && temp1!=0){
		
		if(temp->power==temp1->power){
			s.insert(temp->info+temp1->info,temp->power);
			temp=temp->next;
	     	temp1=temp1->next;
		}			
		else if(temp->power>temp1->power){
			s.insert(temp->info,temp->power);
			temp=temp->next;
		}
		else{
			s.insert(temp1->info,temp1->power);
			temp1=temp1->next;
		}	
	}
	
	if(temp!=0){
		while(temp!=0){
			s.insert(temp->info,temp->power);
			temp=temp->next;
		}
	}
	else if(temp1!=0){
		while(temp1!=0){
			s.insert(temp1->info,temp1->power);
			temp1=temp1->next;
		}
	}
	
	return s;
}

int main(){
	
	poly<int> p1,p2,p3;
	int x,a,i;
	
    cout<<"\n--------------Enter first Polynomail-------------------\n"	;
	for(i=1;i<=2;i++){
		cout<<"\nEnter base element:";
		cin>>x;
		cout<<"\nEnter power:";
		cin>>a;
		
		p1.insert(x,a);
	}
	
	cout<<"\n--------------First Polynomial--------------\n";
	p1.display();
	
	cout<<"\n--------------Enter second Polynomail-------------------\n"	;
	for(i=1;i<=3;i++){
		cout<<"\nEnter base element:";
		cin>>x;
		cout<<"\nEnter power:";
		cin>>a;
		
		p2.insert(x,a);
	}
	cout<<"\n--------------First Polynomial--------------\n";
	p1.display();
	
	cout<<"\n--------------Second Polynomial--------------\n";
	p2.display();
	
	
	p3=p1.addpoly(p2);
	
	cout<<"\n--------------Sum--------------\n";
	p3.display();
	
	return 0;
}
