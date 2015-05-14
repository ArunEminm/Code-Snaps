import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class sherlockandgcd {

		
		public static void main(String args[]) throws IOException
		{
			BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
			//BufferedReader input= new BufferedReader(new FileReader("input.txt"));
			PrintWriter output=new PrintWriter(System.out);
		
			int TestCount=Integer.parseInt(input.readLine());
			int length;
			int[] arr;
			String[] s;
			while(TestCount-->0)
			{
				length=Integer.parseInt(input.readLine());
				arr=new int[length];
				s=input.readLine().split(" ");
				for(int i=0;i<length;i++)
				{
					arr[i]=Integer.parseInt(s[i]);
				}
				output.println(solve(arr));
			}
			output.flush();
		}
		
		public static boolean ifgcdone(int a,int b)
		{
			int c;
			  while(a!=0 && b!=0)
			  {
			     c = b;
			     b = a%b;
			     a = c;
			  }
			  
			  return (a+b==1)?true:false;
		}
		public static String solve(int[] a)
		{
			int k=a.length;
			for(int i=0;i<k;i++)
			{
				for(int j=i+1;j<k;j++)
				{
					if(ifgcdone(a[i],a[j])==true)
						return "YES";
				}
			}
			return "NO";
		}
	
}
