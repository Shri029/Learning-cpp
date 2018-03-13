#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
class BSTnode{
	
	public: 
	T info;
	BSTnode *left, *right;
	
	BSTnode(T x,BSTnode *l=0,BSTnode *r=0){
		info=x;
		left=l;
		right=r;
	}
};

template <class T>
class BSTree{
	
	BSTnode<T> *root;
	
	public:
	int height;
	
	BSTree(){
		root=0;
		height=-1;
	}
	
    int isempty(){
    	if(root==0)
    	 return 1;
    	else
		 return 0; 
	}
	
	void insertion(T X);
	void preorder();
	void preorder(BSTnode<T>*);
	void inorder();
	void inorder(BSTnode<T>*);
	void postorder();
	void postorder(BSTnode<T>*);
	void breadthfirst();
};

//-----------------------------Insertion-------------------------
template <class T>
void BSTree<T>::insertion(T x){
	
	BSTnode<T> *temp=new BSTnode<T>(x);
	BSTnode<T> *p=root,*prev;
	
	prev=0;
	
	while(p!=0){
		prev=p;
		
		if(p->info>x)
		 p=p->left;
		else if(p->info<x)
		 p=p->right; 
	}
		
	if(prev==0)
	 root=temp;
	else if(prev->info>x)
	 prev->left=temp;
	else
	 prev->right=temp; 	
}

//-----------------------------Display-------------------------
template <class T>
void BSTree<T>::preorder(){
	preorder(root);
}

template <class T>
void BSTree<T>::preorder(BSTnode<T> *p){
	if(p!=0){
		cout<<p->info<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}	

template <class T>
void BSTree<T>::inorder(){
	inorder(root);
}

template <class T>
void BSTree<T>::inorder(BSTnode<T> *p){
	if(p!=0){
		preorder(p->left);
		cout<<p->info<<" ";
		preorder(p->right);
	}
}	

template <class T>
void BSTree<T>::postorder(){
	postorder(root);
}

template <class T>
void BSTree<T>::postorder(BSTnode<T> *p){
	if(p!=0){
		preorder(p->left);
		preorder(p->right);
		cout<<p->info<<" ";
	}
}	

template <class T>
void BSTree<T>::breadthfirst(){
	
	queue<BSTnode<T>*> q;
	BSTnode<T> *v=root;
	
	q.enqueue(p);
	
	while(!q.isempty()){
		v=q.dequeue();
		
		cout<<v->info<<" ";
		
		if(v->left!=0)
		 q.enqueue(v->left);   
		if(v->right!=0)
		 q.enqueue(v->right); 
   }
}

int main(){
	BSTree<int> t1,t2;
	int x;
	char c;
	do{
	cout<<"\nenter a no for tree:";
	cin>>x;
	t1.insertion(x);
	cout<<"\ndo you want to continue:";
	cin>>c;
	}
	while(c=='y');
	cout<<"\ntree is:";
	
	t1.breadthfirst();
	
	return 0;
}
