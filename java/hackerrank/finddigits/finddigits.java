import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class finddigits {

		public static void main(String args[]) throws IOException
		{
			BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
			PrintWriter output=new PrintWriter(System.out);
		
			int TestCount=Integer.parseInt(input.readLine());
		
			while(TestCount-->0)
			{
				output.println(find(Integer.parseInt(input.readLine())));
			}
			output.flush();
		}
    
	public static int find(int N)
	{
		int res=0;
		int Orig=N;
		while(N>0)
		{
			int m=N%10;
			if(m!=0)
			{
				if(Orig%m==0)
				{
					res+=1;
				}
				
			}
			N=N/10;
			
		}
		return res;
	}
}
