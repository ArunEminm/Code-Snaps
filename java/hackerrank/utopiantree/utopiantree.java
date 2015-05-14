import java.io.*;

public class utopiantree
{
	
	public static void main(String args[]) throws IOException
	{
		BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output=new PrintWriter(System.out);
		
		int TestCount=Integer.parseInt(input.readLine());
		
		while(TestCount-->0)
		{
			output.println(lengthcount(Integer.parseInt(input.readLine())));
		}
		output.flush();
	}
	
	public static long lengthcount (int n)
	{
		long initial=1;
		int i=1;
		while(i<=n)
		{
			if(i%2!=0)
				initial*=2;
			else
				initial+=1;
			i++;
		}
		return initial;
	}
}
