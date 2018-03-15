//Add integers using stack
#include<iostream>
#include <stack>
using namespace std;

int main(){
    
    stack<int> s1,s2,s3;
    int i,x,y,result;
    
 //---------------Input----------------------   
    cout<<"\nEnter the integers of the 1st number:";
    for(i=1;i<=5;i++){
	 cin>>x;
     s1.push(x);
    }
    
    cout<<"\nEnter the integers of the 2nd number:";
    for( i=1;i<=5;i++){
	 cin>>y;
	s2.push(y);
    }

//---------------Addition----------------------    
	while((s1.size()!=0) || (s2.size()!=0 )){	
		if((s1.size()!=0)){
			x=s1.top();
			s1.pop();
		}			 
		else
		 x=0; 
		if((s2.size()!=0)){
			y=s2.top();
			s2.pop();
		}
		else
		 y=0;  

		result=result+x+y;
		s3.push(result%10);
		result=result/10; 		 
	}	
	if(result!=0)
	 s3.push(result);

//---------------Display----------------------	
	cout<<"\nSum is:";
    for(int i=s3.size();i>=1;i--){
     cout<<s3.top();
     s3.pop();
    }
    return 0;
}

	


