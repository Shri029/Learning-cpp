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

int main() {
	int A[] = {1, 4, 45, 6, 10, 8};
    int n = 9;
    
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    // Function calling
    printPairs(A, arr_size, n);

	return 0;
}
