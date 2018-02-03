//Calculating Minimum no of engineers required to defuse a network of explosives using vertex cover

#include <iostream>
using namespace std;

class Bstnode                                          //Bstnode
{
	public:
		int info;
		int level;
		Bstnode *left,*right;
		Bstnode (int x,Bstnode *l=0,Bstnode *r=0)
		{
			info=x;
			left=l;
			right=r;
			level=0;
		}
};

class Bstree                                           //BSTREE
{
	public:
	    Bstnode *root;
		int height;
		Bstree()
		{
			root=0;
			height =-1;
		}
		
		void insertion(int x);
		void VCover();
		int VCover(Bstnode*);
		int min(int x, int y) { return (x < y)? x: y; }
		
};		

void Bstree::insertion(int x)                          //INSERTION
{
	Bstnode *temp=new Bstnode(x);
	Bstnode *p=root,*prev;
	prev=0;
	while(p!=0)
	{
		prev=p;
		if(p->info>x)
			p=p->left;
		else
			if(p->info<x)
			p=p->right;
	}
	if(prev==0)
		root=temp;
	else if(prev->info>x)
		prev->left=temp;
	else
		prev->right=temp;
}

void Bstree::VCover(){
  
      cout<<"\nMinimum number of engineers required:"<<  VCover(root);
}

int Bstree::VCover(Bstnode *root)
{
    // The size of minimum vertex cover is zero if tree is empty or there
    // is only one node
    if (root == 0)
        return 0;
    if (root->left == 0 && root->right ==0)
        return root->info;
 
    // Calculate size of vertex cover when root is part of it

    int size_incl= VCover(root->left) + VCover(root->right);
 
    // Calculate size of vertex cover when root is not part of it
    int size_excl=0;
    if (root->left)
      size_excl += VCover(root->left->left) + VCover(root->left->right);
    if (root->right)
      size_excl +=  VCover(root->right->left) + VCover(root->right->right);
      
 
    // Return the minimum of two sizes
    if(size_incl)
    return min(size_incl, size_excl);
    else
    return size_excl;
}

int main()
{
	Bstree t1;
	int x;
	char c;
	
	do{
	cout<<"\nEnter explosive number:";
	cin>>x;
	t1.insertion(x);
	cout<<"\nDo you add more explosive:";
	cin>>c;
	}
	while(c=='y');
	
    t1.VCover();
	
	return 0;
}	