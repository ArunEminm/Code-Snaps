import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class maximizingxor
{
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output=new PrintWriter(System.out);
		
		{
			output.println(calmaxxor(Integer.parseInt(in.readLine()),Integer.parseInt(in.readLine())));
		}
		output.flush();
	}
	
	public static int calmaxxor(int a , int b)
	{
		int max=0;
		int temp=0;
		for(int i=0;i<=(b-a);i++)
		{
			for(int j=0;j<=(b-a-i);j++)
			{
				temp=(a+i)^(b-j);
				if(max<temp)
					max=temp;
			}
		}
		return max;
	}
}
