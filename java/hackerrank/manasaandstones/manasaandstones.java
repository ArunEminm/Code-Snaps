import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class manasaandstones {

		
		public static void main(String args[]) throws IOException
		{
			BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
			PrintWriter output=new PrintWriter(System.out);
		
			int TestCount=Integer.parseInt(input.readLine());
			int a,b,n;
			while(TestCount-->0)
			{
				n=Integer.parseInt(input.readLine());
				a=Integer.parseInt(input.readLine());
				b=Integer.parseInt(input.readLine());
				if(a<b)
				{
					output.println(solution(n,a,b));
				}
				else if(a==b)
				{
					output.println((n-1)*a);
				}
				else
				{
					output.println(solution(n,b,a));
				}
				
			}
			output.flush();
		}
		
		public static String solution(int n,int a,int b)
		{
			String res="";
			for(int i=0;i<n;i++)
			{
				res+=(n-1-i)*a+i*b+" ";
			}
			return res;
		}
	
}
