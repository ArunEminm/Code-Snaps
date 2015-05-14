import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class isfibo {
	
	private static class ll{
		long value;
		ll next;
		
		ll(long fib)
		{
			this.value=fib;
			this.next=null;
		}
		
		
	}


    public static void main(String[] args) throws IOException
	{
		long a=1l,b=1l,c=1;
		
		ll fibll= new ll(a);
		fibll.next=new ll(b);
		ll current=fibll.next;
		long limit=10000000000l;
		while(c<limit)
		{
			
			c=a+b;
			current.next=new ll(c);
			a=b;
			b=c;
			current=current.next;
		}
		BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output=new PrintWriter(System.out);
	
		int TestCount=Integer.parseInt(input.readLine());
	
		while(TestCount-->0)
		{
			output.println(isFib(Long.parseLong(input.readLine()),fibll));
		}
		output.flush();
    }
    
    public static String isFib(long n,ll list){
		ll temp= list;
		while(temp!=null)
		{
			if(temp.value==n)
				return "IsFibo" ;
			temp=temp.next;
		}
		return "IsNotFibo";
    }
	
}
