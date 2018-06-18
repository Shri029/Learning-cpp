#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

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

void findMissing(int a[],int n,int min,int max){
    
   unordered_set<int> s;
   int i;
   
   for(i=0;i<n;i++){
       s.insert(a[i]);
   }
   
   for(i=min;i<=max;i++){
       if(s.find(i)==s.end())
       cout<<"\nMissing Element: "<<i;
   }
}


void symmetricPair(int a[][2],int r){
    
    unordered_map<int,int> hm;
    int i,first,sec;
    for(i=0;i<r;i++){
        first=a[i][0];
        sec=a[i][1];
    
    if(hm.find(sec)!=hm.end() && hm[sec]==first) 
      cout<<"\nSymmetric Pair: ("<<sec<<","<<first<<")";
    else
      hm[first]=sec;
    }
}

int main() {
	int A[] = {1, 4, 45, 6, 10, 8};
    int n = 9;
    int a1[]={6,7,8,10,12};
    int s=sizeof(a1)/sizeof(a1[0]);
    
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    // Function calling
    printPairs(A, arr_size, n);             //Print pairs with given Sum
    
    findMissing(a1,s,6,12);                 //Missing eement in a given Range
    
    int arr[5][2];
    arr[0][0] = 11;  arr[0][1] = 20;
    arr[1][0] = 30;  arr[1][1] = 40;
    arr[2][0] = 5;   arr[2][1] = 10;
    arr[3][0] = 40;  arr[3][1] = 30;
    arr[4][0] = 10;  arr[4][1] = 5;
    
    symmetricPair(arr,5);
	return 0;
}

