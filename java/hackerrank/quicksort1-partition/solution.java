
import java.util.*;
public class solution 
{
static void partition(int[] ar) 
	{
		int[] res=new int[ar.length];
		int first=ar[0];
		int index=0;
		for(int i=1;i<ar.length;i++)
		{
			if(ar[i]<first)
			{
				res[index]=ar[i];
				index++;
			}
		}
		res[index]=first;
		index++;
		for(int i=1;i<ar.length;i++)
		{
			if(ar[i]>first)
			{
				res[index]=ar[i];
				index++;
			}
		}
			printArray(res);
	}   

	static void printArray(int[] ar) 
	{
		for(int n: ar)
		{
			System.out.print(n+" ");
		}
			System.out.println("");
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ar = new int[n];
		for(int i=0;i<n;i++)
		{
			ar[i]=in.nextInt(); 
		}
		partition(ar);
	}    
}

