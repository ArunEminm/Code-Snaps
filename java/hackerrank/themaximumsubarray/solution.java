import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class solution
{
	public static void main(String[] args) throws IOException
		{
			//BufferedReader in = new BufferedReader(new FileReader("input"));
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw=new PrintWriter(System.out);
			//PrintWriter pw=new PrintWriter("output");
			int testcase=Integer.parseInt(in.readLine());
			String[] s;
			int length;
			int[] input;
			while(testcase-->0)
			{
				length=Integer.parseInt(in.readLine());
				s=in.readLine().split(" ");
				input=new int[length];
				for(int i=0;i<length;i++)
				{
					input[i]=Integer.parseInt(s[i]);
				}
				
				pw.println(contiguous(input)+" "+non_contiguous(input));
			}
			pw.flush();
			
		}
		
		public static long contiguous(int[] a)
		{
			long max1,max2;
			max1=a[0];
			max2=max1;
			for(int i=1;i<a.length;i++)
			{
				max1=max(a[i],max1+a[i]);
				max2=max(max2,max1);
			}
			return max2;
		}
		
		public static long non_contiguous(int[] a)
		{
			int length=a.length;
			long sum=0l;
			long back;
			int max=a[0];
			for(int i=0;i<length;i++)
			{
				back=sum;
				sum+=a[i];
				if(sum<back)
					sum=back;
				if(max<a[i])
					max=a[i];	
			}
			if(sum==0) 
				return max;
			else 
				return sum;
		}
		
		public static long max(long a,long b)
		{
			if(a>b)
				return a;
			else
				return b;
		}
		 
}

