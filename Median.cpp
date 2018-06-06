// Median of Stream of Running Integers using STL

//#include<bits/stdc++.h>
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

#define MAX 100

priority_queue<int> max_left;
priority_queue<int , vector<int>, greater<int>> min_right;


void cal_median(double x,double &median){
 
    if(max_left.size()>min_right.size()){
        
        if(x<median){
            min_right.push(max_left.top());
            max_left.pop();
            max_left.push(x);
        }
        else
            min_right.push(x);
        median= ((double)max_left.top()+(double)min_right.top())/2.0;
    }
    
    else if(max_left.size()==min_right.size()){
        if(x<median){
            max_left.push(x);
            median= (double)max_left.top();
        }
        else{
            min_right.push(x);
            median= (double)min_right.top();
        }
    }
    else{
        if(x<median){
            max_left.push(min_right.top());
            min_right.pop();
            min_right.push(x);
        }
        else
            max_left.push(x);
        median= ((double)max_left.top()+(double)min_right.top())/2.0;
        
    }
}

int main() {
    
    double a[MAX];
    int i,n;
    double median=0;
    
    cin>>n;
    
    for(i=0;i<n;i++)
        cin>>a[i];
    
    for(i=0;i<n;i++){
        
        cal_median(a[i],median);
        cout<<"\n Median "<<i+1<<": "<< setprecision(1) << fixed << median;
    }
    
	return 0;
}
