import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class halloweenparty {

		
		public static void main(String args[]) throws IOException
		{
			BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
			PrintWriter output=new PrintWriter(System.out);
		
			int TestCount=Integer.parseInt(input.readLine());
			long cut;
		
			while(TestCount-->0)
			{
				cut=Long.parseLong(input.readLine());
				output.println(((cut/2)*(cut-cut/2)));
			}
			output.flush();
		}
	
}
