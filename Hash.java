/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.HashSet;
import java.util.HashMap;

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
    
    static int maxLen(int a[],int n){
        
        HashMap<Integer,Integer> HM=new HashMap<Integer,Integer>();
        
        int i,sum=0,maxlen=0;
        
        for(i=0;i<n;i++){
           
           sum+=a[i];

           if(a[i]==0 && maxlen==0)
                maxlen=1;
           
           if(sum==0)    
            maxlen=i+1;
            
           Integer previ=HM.get(sum);
            
           if(previ!=null)
             maxlen=Math.max(maxlen,i-previ);
           else
             HM.put(sum,i);
             
            
        }
        return maxlen;
    }
    
    static void printDistinct(int a[],int k){
        
        HashMap<Integer,Integer> hM=new HashMap<Integer,Integer>();
        int dCount=0,count=0,i;
        
        System.out.println("\nDistnict Count");
        for(i=0;i<k;i++){
            if(hM.get(a[i])==null){
                hM.put(a[i],1);
                dCount++;
            }
            else{
               count=hM.get(a[i]);
               hM.put(a[i],count+1);
            }
        }
        
        System.out.println(dCount);         //Count of first Window
        
        for(i=k;i<a.length;i++){
            
            if(hM.get(a[i-k])==1){
                hM.remove(a[i-k]);
                dCount--;
            }
            else{
                count=hM.get(a[i-k]);
                hM.put(a[i-k],count-1);
            }
            
            if(hM.get(a[i])==null){
                hM.put(a[i],1);
                dCount++;
            }
            else{
               count=hM.get(a[i]);
               hM.put(a[i],count+1);
            }
          System.out.println(dCount);         //Count of current Window  
        }
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		int a1[]={2,4,5,7,9,1,6,5,6};
		int a2[]={5,2,4,9,1,6};
		int a3[]={0,2,4,-6,-10,9,1};
		int m=a1.length;
		int n=a2.length;
		int l=a3.length;
		
		
		if(isSubset(a1,a2,m,n))
		  System.out.println("\nSubset");
		else
		  System.out.println("\nNot Subset");
		  
		int res=maxLen(a3,l);  
	    System.out.println("\nMaximum sum length: "+res);  
	    
	    printDistinct(a1,4);
	}
}
