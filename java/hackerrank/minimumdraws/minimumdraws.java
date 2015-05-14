import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class minimumdraws {

    public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		
		int T=Integer.parseInt(br.readLine());
		
		while(T-->0)
		{
			pw.println(Integer.parseInt(br.readLine())+1);
		}
		pw.flush();
    }
}
