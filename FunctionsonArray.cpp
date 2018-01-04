#include<iostream>
using namespace std;

void concat(char a[],char b[])
{ 
	int i,j,k;
	for(i=0;a[i]!='\0';i++)
		;
	for(j=i,k=0;b[k]!='\0';j++,k++)
		a[j]=b[k];
    	a[j]='\0';
		cout<<a<<"\n";
		cout<<b;
}
void compare(char a[],char b[])
{ 
	int i,j,flag=0;
	for(i=0,j=0;a[i]!='\0' && b[j]!='\0';)
			if(a[i]!=b[j])
			{ 
				flag=1;
			    break;
			}
		   else
		   {i++;
		    j++;
		   } 
	if(flag==1)
		cout<<"\nstrings do not match";
	else
		cout<<"\nstring match";
}
  int length(char z[10])
  {
	  for(int i=0;z[i]!='\0';i++)
		  ;
		  return i;
  }
  void uptolow(char z[10])
  { 
	  int i;
	  { for(i=0;z[i]!=0;i++)
	  
		  if (z[i]>='A'&&z[i]<='Z')
			  z[i]=z[i]+32;
	  }
	 
		  cout<<z<<"\n";
  }
  void lowtoup(char z[10])
  {
	  int i;
	  for(i=0;z[i]!=0;i++)
	  {
		  if(z[i]>='a'&&z[i]<='z')
			  z[i]=z[i]-32;
	  
	  }
     
	  cout<<z;
  }
  void countadd(char z[10])
  {
	  int i;

	  for(i=0;z[i]!=0;i++)
	  {
		  cout<<(int *)&z[i];
		  cout<<endl;
	  }
  }

  void strconcatenate(char y[10],char z[10])
  {
	  strcat(y,z);
	  cout<<y<<" "<<z;
  }
  void vowels( char z[10])
  {
	  int vowel=0,i;
	  for(i=0;z[i]!=0;i++)
		  switch(z[i])
	  {
		  case 'a':
		  case 'e':
		  case 'i':
		  case 'o':
		  case 'u':vowel++;
	  }
	  cout<<"\n no of vowel is"<<vowel<<endl;
  }
void lengthusingpointers(char y[10])
{
	char *p=y;
	int i;
	for(i=0;*p!='\0';p++,i++);
		cout<<i<<endl;
}

void main()
{
	int ch;
	char a[10];
    char b[10];

	cout<<"enter two array\n";
	cin>>a;
	cin>>b;
	cout<<"\n\t\t menu\n";
	cout<<"\n1 concenate two strings\n";
	cout<<"\n2 compare two strings\n";
	cout<<"\n3calculate length of string\n";
	cout<<"\n4convert all lowercase character to uppercase\n";
	cout<<"\n5convert all uppercase character to lowercase\n";
	cout<<"\n6count no of vowels\n";
	cout<<"\n7to calculate address of each character\n";
	cout<<"\n8to concatenate two strings using stract\n";
	cout<<"\n9to calculate length of a string using pointers\n";
	cin>>ch;
	switch(ch)
	{
	case 1: concat(a,b);
		    break;

	case 2: int p,q;
		    q=length(a);
			p=length(b);

			if(p==q)
				compare(a,b);
			else 
				cout<<"\nstrings do not match\n";

		    break;
	
	case 3: 
	    	q=length(a);
		    cout<<"\n length of string is\n"<<q;
		     p=length (b);
		    cout<<"length of string is"<<p;
       		break;

	case 4:  uptolow(a);
		    uptolow(b);
		    break;

	case 5: lowtoup(a);
		    lowtoup(b); 
		    break;

	case 6: vowels(a);
		    vowels(b);
			break;

	case 7: countadd(a);
		    break;
	
	case 8: strconcatenate(a,b);
		     break;
			
	 case 9: 
		 cout<<"\n length of one string";
		 lengthusingpointers(a);
		 cout<<"\nlength of second string";
		 lengthusingpointers(b);

	}
	

}
