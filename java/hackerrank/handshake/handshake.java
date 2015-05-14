import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class handshake {

    public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		
		int T=Integer.parseInt(br.readLine());
		int t;
		
		while(T-->0)
		{
			t=Integer.parseInt(br.readLine());
			pw.println(t*(t-1)/2);
		}
		pw.flush();
    }
}
