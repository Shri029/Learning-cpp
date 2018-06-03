#include <iostream>
using namespace std;

#define max_size 10

int gcd(int,int);
void swap(int[],int,int,int);
void reverse(int [],int,int);
void display(int[],int);

//-------------------------------LEFT ROTATIONS ----------------------------------

void left_rotate1(int a[],int r,int n){   //Method 1

  int i,j,temp;                         
   
  for(i=1;i<=r;i++){                      //r shifts
      temp=a[0];
      for(j=0;j<n-1;j++)                  //shifting by one bit
       a[j]=a[j+1];
      
      a[n-1]=temp;
      
  }
  cout<<"\nArray after circular left rotatin using method 1:";
  display(a,n);
}

void left_rotate2(int a[],int r,int n){   //Method 2- Storing firts r elements in a temporary array 

    int temp[max_size],i,j=0;            //and storing at the end after performing shift on rest elements
    
    for(i=0;i<n;i++){
	    
        if(i<r){
         temp[i]=a[i];
         a[i]=a[i+r];
        } 
        else
         a[i]=a[i+r];
         
        if(i>=n-r){
         a[i]=temp[j];
         j++;
        }
    }
    cout<<"\nArray after circular left rotation using method 2:";
    display(a,n);
}

//-------------------------------REVERSAL ALGORTHM O(n)------------------------------------


void left_rotate3(int a[],int r,int n){//Method 3- Reversing and merging subarrays before & after the partition
   
    reverse(a,0,r-1);                  //Partition created on the basis of no of elements required to rotate
    reverse(a,r,n-1);
    
    
    reverse(a,0,n-1);                 //Reversing the merged array
    
    cout<<"\nArray after circular left rotation using method 3:";
    display(a,n);
}

void left_rotate4(int a[],int r,int n){ //Dividing array into blocks [size=(gcd(n,r))] and moving i'th element
    int temp,j,i,k=0,x;                 //of block 
    int d=gcd(n,r);
    
    for(i=0; i<d; i++){
        temp=a[i];
        
        for(j=0,x=i; j<=n/d; j++){      // moving i-th values of blocks 
            k=x+r;
            
            if(k>=n)
             k=k-n;
             
            if(k==i)
             break;
             
            a[x]=a[k];
            x=k;
        }
        a[x]=temp;
    }
     cout<<"\nArray after circular left rotation using method 4:";
    display(a,n);    
    
  
}
 
//-------------------------------BLOCK SWAP O(n)------------------------------------
void left_rotate5(int a[],int r,int n){   
    
    if(r==0 || n==0)
        return;
    if(n-r==r){
        swap(a,0,n-r,r);
        return;
    }
    
    if(r<n-r){                              //If r is shorter than n-r 
        swap(a, 0, n-r, r);
        left_rotate5(a, r, n-r);
    }
    else{                                   //No of bits to be rotated is greater than rest of array
        swap(a, 0, r, n-r);                    //As n-d is shorter;so swap with width n-d
        left_rotate5(a+n-r, 2*r-n, r);
    }
    
}
    
//------------------------------ RIGHT ROTATINONS----------------------------------

void right_rotate1(int a[],int r,int n){   //Method 1

  int i,j,temp;                         
   
  for(i=1;i<=r;i++){                      //r shifts   
      
      temp=a[n-1];
      for(j=n-1;j>=0;j--)                //Shift by one bit
       a[j]=a[j-1];
       
      a[0]=temp; 
  }
  cout<<"\nArray after circular right rotation using method 1:";
  display(a,n);
}

void right_rotate2(int a[],int r,int n){   //Method 2- Storing last r elements in a temporary array 

    int temp[max_size],i=n-r,j=0;        //and storing at first after performing shift on rest elements
    
    while(i<n){
        temp[j]=a[i];
        i++;j++;
    }

    for(j=n-1,i=n-r;j>=0;j--){
        
        if(j>=r){                       //Shifting
         a[j]=a[i-1];
         i--;
        }

        else{
         i++;
         a[j]=temp[r-i];
        } 
    } 
    cout<<"\nArray after circular right rotation using method 2:";
    display(a,n);
}

void right_rotate3(int a[],int r,int n){//Method 3- Reverse whole array and reverse partitioned array
   
    reverse(a,0,n-1);                  //Reversing the array
    reverse(a,0,r-1);                  //Partition created on the basis of no of elements required to rotate
    reverse(a,r,n-1);
    
    
    cout<<"\nArray after circular right rotation using Reversal algo:";
    display(a,n);
}

//--------------------------------UTILITY FUNCTIONS----------------------------------

int gcd(int a,int b){                   //Recursive Method to find gcd
    
    if(b==0)
     return a;
    else 
     return gcd(b,a%b);
}

void swap(int a[],int s,int l,int d){  //Array, start address , last address to swap, width to swap
    
    int i,temp;
    for(i=0;i<d;i++){
        temp=a[s+i];
        a[s+i]=a[l+i];
        a[l+i]=temp;
    }
}


void reverse(int a[],int s,int l){   //Reverse 
    
 int i,temp=0;                          
 for(i=s;i<l;i++,l--){
     temp=a[i];
     a[i]=a[l];
     a[l]=temp;
 }
}
void display(int a[],int n){            //Display function 
  int i;
  for(i=0;i<n;i++)
   cout<<"\t"<<a[i];  
}

//--------------------------------DRIVER PROGRAM----------------------------------

int main() {
	int arr[max_size];
	int i,n,r;
	
	cin>>n;                       //Actual size of array
	
	for(i=0;i<n;i++)              //Input Array
	 cin>>arr[i];
	
	cin>>r;                       //Number of rotation bits

	left_rotate1(arr,r,n);
	right_rotate1(arr,r,n);
	
	left_rotate2(arr,r,n);
	right_rotate2(arr,r,n);
	
	left_rotate3(arr,r,n);
	right_rotate3(arr,r,n);
	
	left_rotate4(arr,r,n);
	
    left_rotate5(arr,r,n);
    cout<<"\nArray after left rotation using block swap:";
    display(arr,n);
    
	return 0;
}
