// STL based C++ program to find k-th smallest element.

//#include<bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

#define MAX 100

void ksmallest(int a[],int n,int k){
    
    set<int> s;						//Storing elements in decreasing order.
    int i;
    set<int>::iterator it;
    
    //or  auto it=s.begin(); Initiallization and declaration 
    
    
   for(i=0;i<n;i++)
    s.insert(a[i]);
    
  it=s.begin();
    
   for (int i = 0; i < k - 1; i++)
        it++;
   cout<<"\nk'th smallest:"<<*it; 
}

void klargest(int a[],int n,int k){
    
    set<int,greater<int>> s;				//To store elements in increasing order.
    int i;
    set<int>::iterator it;
    
    //or  auto it=s.begin(); Initiallization and declaration 
    
    
   for(i=0;i<n;i++)
    s.insert(a[i]);
    
   it=s.begin();
    
   for (int i = 0; i < k-1; i++)
        it++;
   cout<<"\nk'th largest:"<<*it; 
}


int main() {
    
    int a[MAX];
    int i,n,k;
    
    cin>>n;
    
    for(i=0;i<n;i++)
    cin>>a[i];
    
    cin>>k;
    
    ksmallest(a,n,k);
    klargest(a,n,k);
    
	return 0;
}
