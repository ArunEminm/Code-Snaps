import java.io.*;
import java.util.*;

class minimumno 
{
	public static String MIN(String a,String b)
	{
		if(a.length()<b.length())
			return a;
		else if(a.length()>b.length())
			return b;
		else
		{
			int i=0;
			int len=a.length();
			while(i<len)
			{
				if(a.charAt(i)<b.charAt(i))
					return a;
				else if(a.charAt(i)>b.charAt(i))
					return b;
				i++;
			}
			return a;
		}
	}

	public static String Solution(int l,int h,int k,String val)
	{
		if(k==0)
			return val.substring(l,h+1);
		else if(k==h-l+1)
			return "";
		else
			return MIN(val.charAt(l)+Solution(l+1,h,k,val),Solution(l+1,h,k-1,val));
	}

	public static void main(String[] args)
	{
		String val;
		Scanner s=new Scanner(System.in);
		val=s.nextLine();
		int n=val.length();
		int k=s.nextInt();
		System.out.print(Solution(0,n-1,k,val)+"\n");
	}
}
