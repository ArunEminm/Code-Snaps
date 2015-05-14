import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class lovelettermystery {

		
		public static void main(String args[]) throws IOException
		{
			BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
			PrintWriter output=new PrintWriter(System.out);
		
			int TestCount=Integer.parseInt(input.readLine());
		
			while(TestCount-->0)
			{
				output.println(palindrome((input.readLine())));
			}
			output.flush();
		}
		
		public static int palindrome(String s)
		{
			int steps=0;
			int k=s.length();
			for(int i=1;i<=k/2;i++)
			{
				steps+=Math.abs((int)s.charAt(i-1)-(int)s.charAt(k-i));
			}
			return steps;
		}
}
