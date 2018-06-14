#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define MAX 1000

template <class T>
class BSTnode{
	
	public: 
	T info;
	BSTnode *left, *right;
	
	BSTnode(T x,BSTnode *l=NULL,BSTnode *r=NULL){
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
		root=NULL;
//		height=-1;
	}
	
    int isempty(){
    	if(root==NULL)
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
	void spiral_traversal();
	void reverse_traversal();
	void specific_Order();
	void specific_OrderUtil(BSTnode<T> *,stack<BSTnode<T>*>);
	void diagonal_Print();
	void diagonal_PrintUtil(BSTnode<T> *n,int d,map<int,vector<int>> &dp);
};

//-----------------------------Insertion-------------------------
template <class T>
void BSTree<T>::insertion(T x){
	
	BSTnode<T> *temp=new BSTnode<T>(x);
	BSTnode<T> *p=root,*prev;
	
	prev=0;
	
	while(p!=NULL){
		prev=p;
		
		if(p->info>x)
		 p=p->left;
		else if(p->info<x)
		 p=p->right; 
	}
		
	if(prev==NULL)
	 root=temp;
	else if(prev->info>x)
	 prev->left=temp;
	else
	 prev->right=temp; 	
}

//-----------------------------TRAVERSALS-------------------------

template <class T>                                         //BreadthFirst
void BSTree<T>::breadthfirst(){
	
	queue<BSTnode<T>*> q;
	BSTnode<T> *p=root,*v;
	
	q.push(p);
	
	if (root == NULL)
      return;
      
	while(!q.empty()){
		v=q.front();
		q.pop();
		
		cout<<v->info<<" ";
		
		if(v->left!=NULL)
		 q.push(v->left);   
		if(v->right!=NULL)
		 q.push(v->right); 
   }
}

template <class T>                                         //Reverse Traversal
void BSTree<T>::reverse_traversal(){
	
	queue<BSTnode<T>*> q;
	stack<BSTnode<T>*> s;
	BSTnode<T> *p=root,*v;
	
	q.push(p);
	
	if (root == NULL)
      return;
      
	while(!q.empty()){
		v=q.front();
		q.pop();
		
		cout<<v->info<<" ";
		
		if(v->right!=NULL)
		 q.push(v->right);
		if(v->left!=NULL)
		 q.push(v->left);   
		 
   }
   while(!s.empty()){
       v=s.top();
       cout<<v->info<<" ";
       q.pop();
   }
}

template <class T>                                         //Spiral Traversal
void BSTree<T>:: spiral_traversal(){
	
	stack <BSTnode<T>*> s1,s2;
	BSTnode<T> *p=root;
	
	if(root==0)
	 return;
	
	s1.push(p); 
	
	while(!s1.empty()|| !s2.empty()){
		
		while(!s1.empty()){
			p=s1.top();
			s1.pop();
			
			cout<<p->info<<" ";
			
			if(p->right)
			 s2.push(p->right);
			if(p->left)
			 s2.push(p->left); 
		}
		while(!s2.empty()){
			p=s2.top();
			s2.pop();
			
			cout<<p->info<<" ";
			
			if(p->left)
			 s1.push(p->left); 
			if(p->right)
			 s1.push(p->right);		
		}
	}
}
/*
template <class T>                                         //Specific Order Utility
void BSTree<T>::specific_OrderUtil(BSTnode<T>* root,stack<BSTnode<T>*> s){
    
    queue<BSTnode<T>*> q;
	BSTnode<T> *p=root,*v,*first=NULL,*second=NULL;
	
	if (root == NULL)
      return;
  
    q.push(v->left);   
    q.push(v->right);
		 
   while(!q.empty()){
       
       first=q.front();
       q.pop();
       second=q.front();
       q.pop();
       
       s.push(second->left);
       s.push(first->right);
       s.push(second->right);
       s.push(first->left);
       
       if(first->left->left!=NULL){
           q.push(first->right);
           q.push(second->left);
           q.push(first->left);
           q.push(second->right);
       }
   }
   
}

template <class T>                                         //Specific Order
void BSTree<T>::specific_Order(){

	stack<BSTnode<T>*> s;
	BSTnode<T> *p=root,*v;
	
	s.push(p);
	
	if (root->left!=NULL){
		 s.push(v->right);
		 s.push(v->left);   
	}
   
   
    if (root->left->left!=NULL)
	    specific_OrderUtil(root,s);
	    
    while(!s.empty()){
       v=s.top();
       cout<<v->info<<" ";
       s.pop();
    }
}
*/

template <class T>
void BSTree<T>::preorder(){                                 //Recursive Preorder 
	preorder(root);
}

template <class T>
void BSTree<T>::preorder(BSTnode<T> *p){
	if(p!=NULL){
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
	if(p!=NULL){
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
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<p->info<<" ";
	}
}	


template <class T>                                      //Iterative Preorder
void BSTree<T>::iterative_pre(){
	
	stack<BSTnode<T>*> q;
	BSTnode<T> *p=root,*v;
	
	q.push(p);
	
	if (root == NULL)
      return;
      
	while(!q.empty()){
		v=q.top();
		q.pop();
		cout<<v->info<<" ";
		
		if(v->right!=NULL)
		 q.push(v->right); 
		if(v->left!=NULL)
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

template <class T>                                      //Diagonal Print Utility
void BSTree<T>::diagonal_PrintUtil(BSTnode<T> *n, int d,map<int,vector<int>> &dp){

    if(n==NULL)
        return;
    
    dp[d].push_back(n->info);
    diagonal_PrintUtil(n->left,d+1,dp);
    diagonal_PrintUtil(n->right,d,dp);
}

template <class T>                                      //Diagonal Print
void BSTree<T>::diagonal_Print(){
    
    map<int,vector<int>> dp;
    
    diagonal_PrintUtil(root,0,dp);
    
    for(auto it=dp.begin(); it!=dp.end();it++){
        for(auto itr=it->second.begin(); itr!=it->second.end();it++)
            cout<<*itr<<" ";
        cout<<endl;
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
	cout<<"\nReverseTraversal: ";       t1.reverse_traversal();
	cout<<"\nSpiral Traversal: ";       t1.spiral_traversal();	
	cout<<"\n\nRecursive Inorder: ";    t1.inorder();
    cout<<"\nIterative Inorder: ";      t1.inorder();
    cout<<"\n\nRecursive Preorder: ";   t1.preorder();
	cout<<"\nIterative Preorder: ";     t1.iterative_pre();
	cout<<"\n\nRecursive Postorder: ";  t1.postorder();
	cout<<"\nIterative Postorder: ";    t1.iterative_post();
//	cout<<"\nSpecial Order: ";          t1.specific_Order();
    cout<<"\nDiagonal Print: ";         t1.diagonal_Print();
	
	t1.height();
	
	return 0;
}
