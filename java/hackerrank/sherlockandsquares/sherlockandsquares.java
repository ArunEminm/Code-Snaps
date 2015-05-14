import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class sherlockandsquares {

    public static void main(String[] args) throws IOException
    {
  	  //BufferedReader in = new BufferedReader(new FileReader("SherlockandSquaresinput.txt"));
	  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	  
	  PrintWriter pw=new PrintWriter(System.out);
	  String[] s;
	  int test=Integer.parseInt(in.readLine());
	  int a,b;
	  int sqrta,sqrtb,answer;
	  for(int i=0;i<test;i++)
	  {
		  answer=0;
		  s=in.readLine().split(" ");
		  a=Integer.parseInt(s[0]);
		  b=Integer.parseInt(s[1]);
		  sqrta=(int)Math.sqrt(a);
		  sqrtb=(int)Math.sqrt(b);
		  if(sqrta*sqrta==a)
			  answer+=1;
		  //System.out.println(sqrta+" "+sqrtb);
		  answer+=(sqrtb-sqrta);
		  pw.println(answer);
		  
	  }
	  pw.flush();
	 
}
}
