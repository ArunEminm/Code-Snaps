import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class coinchange
{

	public static void main(String[] args) throws IOException
	{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintWriter pw=new PrintWriter(System.out);
	//coins will be entered comma separated
	String[] s=br.readLine().split(",");
	int[] coins=new int[s.length+1];
	for(int i=0;i<s.length;i++)
	{
		//will replace non-digit in the string will "" 
		coins[i+1]=Integer.parseInt(s[i].replaceAll("[\\D]", ""));
	}
	//sum to be changed will be entered here
	//will replace non-digit in the string will "" 
	int n=Integer.parseInt(br.readLine().replaceAll("[\\D]", ""));
	System.out.println(count(n,coins));
	}

	public static long count(int n,int[] D)
	{
		long[][] table=new long[n+1][D.length];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<D.length;j++)
			{
				if(i==0)
					table[i][j]=1;
				else if(j==0)
					table[i][j]=0;
				else if(D[j]>i)
					table[i][j]=table[i][j-1];
				else
					table[i][j]=table[i-D[j]][j]+table[i][j-1];
			} 
		}
		return table[n][D.length-1];
	}
}
