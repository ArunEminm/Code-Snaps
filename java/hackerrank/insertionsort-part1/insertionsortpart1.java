import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class insertionsortpart1 
{
    
    

    public static void insertIntoSorted(int[] arr) 
	{
		int s=arr[arr.length-1];
		int i;
		for(i=arr.length-1;i>0;i--)
		{
			if(s<arr[i-1])
			{
				arr[i]=arr[i-1];
				printArray(arr);
			}
			else
			{
				arr[i]=s;
				printArray(arr);
				break;
			}
			
		}
		if(i==0)
		{
			arr[0]=s;
			printArray(arr);
		}
		
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

