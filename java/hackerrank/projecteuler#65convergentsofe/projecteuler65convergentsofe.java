import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class projecteuler65convergentsofe {

	static int[] tn=new int[30001];
    public static void main(String[] args) throws IOException
    {
    	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new FileReader("input"));
		PrintWriter pw=new PrintWriter(System.out);
		//PrintWriter pw=new PrintWriter("output");
		
		tn[0]=2;
		for(int i=1;i<30001;i++)
		{
			tn[i]=(i+1)%3==0?(i+1)*2/3:1;
		}
		int n=Integer.parseInt(br.readLine());
		//System.out.println(tn(n));
		BigInteger numer=numerator(n);
		//System.out.println(numer);
		System.out.println(digitsum(numer));
		
    }
    
    public static BigInteger numerator(int N)
    {
    	BigInteger a,b,c;
    	b=BigInteger.valueOf(tn[N-1]);
    	c=new BigInteger("1");
    	while(N>1)
    	{
    		
    		a=BigInteger.valueOf(tn[--N-1]);
    		//System.out.println("a="+a);
    		BigInteger tempb=b;
    		b=(b.multiply(a)).add(c);
    		//System.out.println("b="+b);
    		c=tempb;
    		
    	}
    	return b;
    	
    }
    
    public static BigInteger digitsum(BigInteger b)
    {
    	String s=b.toString();
    	BigInteger sum=new BigInteger("0");
    	for(int i=0;i<s.length();i++)
    	{
    		
    		sum=sum.add(new BigInteger(s.substring(i,i+1)));
    		//System.out.println(sum);
    	}
    	return sum;
    }
}
