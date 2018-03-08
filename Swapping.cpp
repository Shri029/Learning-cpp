#include <iostream>
using namespace std;

//-------------------Swapping technique1(temporary variables)------------------

void swapp(int* num1,int* num2){ 			//Using pointers
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;	
}

void swapref(int &num1,int &num2){ 			//Call by reference
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;	
}


//--------------------Swapping technique2 (Addition)------------------

void swapadd(int num1,int num2){
	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;
	cout<<"\nAddition:"<<num1<<" "<<num2;
}

void swapaddp(int* num1,int* num2){
	*num1=*num1+*num2;
	*num2=*num1-*num2;
	*num1=*num1-*num2;
}


//--------------------Swapping technique3 (XOR)------------------

void swapx(int num1,int num2){
	num1=num1^num2;
	num2=num1^num2;
	num1=num1^num2;
	cout<<"\nXOR:"<<num1<<" "<<num2;
}

void swapxp(int* num1,int* num2){
	*num1=*num1^*num2;
	*num2=*num1^*num2;
	*num1=*num1^*num2;
}

int main(){
	
	int x1,x2;
	cout<<"\nEnter firt number:";
	cin>>x1;
	cout<<"\nEnter second number:";
	cin>>x2;
	
	cout<<"\n----------Swapping technique1------------\n";
	swapp(&x1,&x2);
	cout<<"\nUsing Pointers:"<<x1<<" "<<x2;
	swapref(x1,x2);
	cout<<"\nCall by reference:"<<x1<<" "<<x2;
	
	cout<<"\n\n--------Swapping technique2------------\n";
	swapadd(x1,x2);											//Changes in the local function won't be reflected in the main function
	swapaddp(&x1,&x2);
	cout<<"\nUsing Pointers:"<<x1<<" "<<x2;
	
	cout<<"\n\n----------Swapping technique3----------\n";
	swapx(x1,x2);											//Changes in the local function won't be reflected in the main function
	swapxp(&x1,&x2);
	cout<<"\nUsing Pointers:"<<x1<<" "<<x2;

	
	return 0;
}

