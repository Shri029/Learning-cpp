#include <iostream>
using namespace std;

#define max_size 10

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
  cout<<"\nArray after circuar left rotatin usning method 1:";
  display(a,n);
}

void left_rotate2(int a[],int r,int n){   //Method 2- Storing firts r elements in a temporary array 

    int temp[max_size],i=0,j,k=0;         //and storing at the end after performing shift on rest elements
    
    while(i<r){                           
        temp[i]=a[i];
        i++;
    }
    

    for(j=0,i=0;j<n;j++,i++){            //shifting
        
        if(j<n-r){
         a[j]=a[r+i];
        } 

        else{
         a[j]=temp[k];
         k++;
        } 
    } 
    cout<<"\nArray after circular left rotation usning method 2:";
    display(a,n);
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
  cout<<"\nArray after circular right rotation usning method 1:";
  display(a,n);
}

void right_rotate2(int a[],int r,int n){   //Method 2- Storing last r elements in a temporary array 

    int temp[max_size],i=n-r,j=0;        //and storing at first after performing shift on rest elements
    
    while(i<n){
        temp[j]=a[i];
        i++;j++;
    }

    for(j=n-1,i=n-r;j>=0;j--){
        
        if(j>=r){                     //shifting
         a[j]=a[i-1];
         i--;
        }

        else{
         i++;
         a[j]=temp[r-i];
        } 
    } 
    cout<<"\nArray after circular right rotation usning method 2:";
    display(a,n);
}
void display(int a[],int n){          //display
  int i;
  for(i=0;i<n;i++)
   cout<<"\t"<<a[i];  
}

int main() {
	int arr[max_size];
	int i,n,r;
	
	cin>>n;                       //Actual size of array
	
	for(i=0;i<n;i++)
	 cin>>arr[i];
	
	cin>>r;                       //Number of rotation bits
	
	left_rotate1(arr,r,n);
	right_rotate1(arr,r,n);
	
	left_rotate2(arr,r,n);
	right_rotate2(arr,r,n);

	return 0;
}
