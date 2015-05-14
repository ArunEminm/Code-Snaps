import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class insertionsortpart2 
{
    
    

    public static void insertIntoSorted(int[] arr) 
	{
		int swap,shifts=0;
		for(int i=0;i<arr.length-1;i++)
		{
			for(int j=i;j>=0;j--)
			{
				if(arr[j]>arr[j+1])
				{
					swap=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=swap;
					shifts+=1;
				}
				
			}
			//printArray(arr);
		}
		//printArray(arr);
		System.out.println(shifts);
		
    }
    
    

     public static void main(String[] args) 
	 {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int[] ar = new int[s];
         for(int i=0;i<s;i++){
            ar[i]=in.nextInt(); 
         }
         insertIntoSorted(ar);
    }
    
    
    private static void printArray(int[] arr) 
	{
      for(int n:arr){
         System.out.print(n+" ");
      }
        System.out.println("");
   }
    
    
}

