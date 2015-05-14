import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class fillingjars {

    public static void main(String[] args) throws IOException
    {
  	  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	  
	  String[] s=in.readLine().split(" ");
	  long jars=Long.parseLong(s[0]);
	  int op=Integer.parseInt(s[1]);
	  long a,b,k;
	  long candies=0;
	  for(int i=0;i<op;i++)
	  {
		  s=in.readLine().split(" ");
		  a=Long.parseLong(s[0]);
		  b=Long.parseLong(s[1]);
		  k=Long.parseLong(s[2]);
		 // System.out.println(a+"-"+b+"-"+k);
		  candies+=(b-a+1)*k;
		  //System.out.println(candies);
		  
		  
	  }
	  long average=candies/jars;
	  System.out.println(average);
    }
}
