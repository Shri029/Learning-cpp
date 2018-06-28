#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printPairs(int a[],int n,int sum){

    unordered_set<int> s;
    int i,temp;
    
    for(i=0;i<n;i++){
        temp=sum-a[i];
        
        if(s.find(temp)!=s.end())   
            cout<<"\nPair: "<<temp<<" & "<<a[i];
        s.insert(a[i]);    
    }
}
/*

There is only 1 difference between the arrays. 
First array has one element extra added in between. 
Find the index of the extra element.

int findExtra(int a[],int b[],int n){
    
    int l=0, h=n-1, mid=0, i=n;
    
    while(l<=h){
        
        mid=(l+h)/2;
        
        if(a[mid]==b[mid])
            l=mid+1;
            
        else{
            i=mid;
            h=mid-1;
        }
    }
    return i;
    
}
*/
int main() {
	int A[] = {1, 4, 45, 6, 10, 8};
    int n = 9;
    
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    // Function calling
    printPairs(A, arr_size, n);

	return 0;
}
