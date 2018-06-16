/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.HashSet;

/* Name of the class has to be "Main" only if the class is public. */
class subset
{
    
    static boolean isSubset(int a1[],int a2[],int m,int n){
        
        HashSet<Integer> hset= new HashSet<>();
        int i;
        
        for(i=0;i<m;i++)
            if(!hset.contains(a1[i]))
                hset.add(a1[i]);
        for(i=0;i<n;i++)
            if(!hset.contains(a2[i]))
                return false;
        return true;        
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		int a1[]={2,4,5,7,9,1,6,5,6};
		int a2[]={5,2,4,9,1,6};
		int m=a1.length;
		int n=a2.length;
		
		if(isSubset(a1,a2,m,n))
		  System.out.println("\nSubset");
		else
		  System.out.println("\nNot Subset");
	}
}
