import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class connectingtowns {

    public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		
		int t,n;
		long res;
		String[] spld;
		String s;
		t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			n=Integer.parseInt(br.readLine());
			s=br.readLine();
			spld=s.split("\\s+");
			res=1;
			for(int i=0;i<n-1;i++)
			{
				res*=Integer.parseInt(spld[i]);
				res=res%1234567;
			}
			pw.println(res);
		}
		pw.flush();
    }
}
