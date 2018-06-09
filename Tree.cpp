#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define MAX 1000

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
//	int height;
	
	BSTree(){
		root=0;
//		height=-1;
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
	void iterative_pre();
	void iterative_post();
	void iterative_in();
	void height();
	int height(BSTnode<T>*);
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

//-----------------------------TRAVERSALS-------------------------
template <class T>
void BSTree<T>::preorder(){                                 //Recursive Preorder 
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

template <class T>                                         //Recursive Inorder 
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

template <class T>                                         //Recursive Postorder 
void BSTree<T>::postorder(){
	postorder(root);
}

template <class T>
void BSTree<T>::postorder(BSTnode<T> *p){
	if(p!=0){
		postorder(p->left);
		postorder(p->right);
		cout<<p->info<<" ";
	}
}	

template <class T>                                         //BreadthFirst
void BSTree<T>::breadthfirst(){
	
	queue<BSTnode<T>*> q;
	BSTnode<T> *p=root,*v;
	
	q.push(p);
	
	if (root == 0)
      return;
      
	while(!q.empty()){
		v=q.front();
		q.pop();
		
		cout<<v->info<<" ";
		
		if(v->left!=0)
		 q.push(v->left);   
		if(v->right!=0)
		 q.push(v->right); 
   }
}

template <class T>                                      //Iterative Preorder
void BSTree<T>::iterative_pre(){
	
	stack<BSTnode<T>*> q;
	BSTnode<T> *p=root,*v;
	
	q.push(p);
	
	if (root == 0)
      return;
      
	while(!q.empty()){
		v=q.top();
		q.pop();
		cout<<v->info<<" ";
		
		if(v->right!=0)
		 q.push(v->right); 
		if(v->left!=0)
		 q.push(v->left);   
   }
}

template <class T>                                      //Iterative Postorder
void BSTree<T>:: iterative_post(){
    
    stack<BSTnode<T>*> s;
    BSTnode<T> *p=root, *q=root;
    
    while(p!=0){
        for(;p->left!=0;p=p->left)
            s.push(p);
        
        while(p!=0 && (p->right==0 || p->right==q)){
            
            cout<<p->info<<" ";
            q=p;
            if(s.empty())
             return;
            p=s.top(); 
            s.pop();
        }
        s.push(p);
        p=p->right;
    }
}

template <class T>                                      //Iterative Inorder
void BSTree<T>:: iterative_in(){
    
    stack<BSTnode<T>*> s;
    BSTree<T> *p=root;
    
    while(p!=0){
        
        while(p!=0){
            if(p->right)
              s.push(p->right);
            s.push(p);
            p=p->left;
        }
        
        p=s.top();
        s.pop();
        
        while(!s.empty() && p->right==0){
          cout<<p->info<<" ";
          p=s.top();
          s.pop();
        }
        cout<<p->info<<" ";
        if(!s.empty()){
            p=s.top();
            s.pop();
        }
        else
          p=0;  
    }
}

//--------------------------------------------------------------
template<class T>
void BSTree<T>::height(){
    int h=height(root);
    cout<<"\nHeight of tree: "<<h;
}

template<class T>
int BSTree<T>::height(BSTnode<T> *node){
    
    if(node==0)
     return 0;
    else{
        int hleft=height(node->left);
        int hright=height(node->right);
        
        if(hleft>hright)
            return (hleft+1);
        else 
            return (hright+1);
    }
}

int main(){
	BSTree<int> t1,t2;
	int x;
	char c;
	do{
	cin>>x;                     //Element
	t1.insertion(x);
	cin>>c;                     //Continue
	}
	
	while(c=='y');
	
	//----------------------Tree traversals----------------------"
	cout<<"\nBreadthFirst: ";           t1.breadthfirst(); 
	cout<<"\n\nRecursive Inorder: ";    t1.inorder();
    cout<<"\nIterative Inorder: ";      t1.inorder();
    cout<<"\n\nRecursive Preorder: ";   t1.preorder();
	cout<<"\nIterative Preorder: ";     t1.iterative_pre();
	cout<<"\n\nRecursive Postorder: ";  t1.postorder();
	cout<<"\nIterative Postorder: ";    t1.iterative_post();
	
	t1.height();
	
	return 0;
}
