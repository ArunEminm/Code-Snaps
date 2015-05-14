import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class chocolatefeast {

    public static void main(String[] args) throws IOException
    {
  	  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	  PrintWriter pw=new PrintWriter(System.out);
	  String[] s;
	  int test=Integer.parseInt(in.readLine());
	  int n,c,m;
	  int chocolates,wrappers;
	  for(int i=0;i<test;i++)
	  {
		  s=in.readLine().split(" ");
		  n=Integer.parseInt(s[0]);
		  c=Integer.parseInt(s[1]);
		  m=Integer.parseInt(s[2]);
		  chocolates=0;wrappers=0;
		  while(n>=c || wrappers>=m)
		  {
			  n-=c;
			  chocolates++;
			  wrappers++;
			  if(wrappers==m)
			  {
				  wrappers=0;
				  chocolates++;
				  wrappers++;
			  }
			  
		  }
		  pw.println(chocolates);
		  
	  }
	  pw.flush();
	 
}
}
