import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class sherlockandthebeast {

    public static void main(String[] args) throws IOException
    {
  	  //BufferedReader in = new BufferedReader(new FileReader("SherlockandSquaresinput.txt"));
	  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	  
	  PrintWriter pw=new PrintWriter(System.out);
	  int test=Integer.parseInt(in.readLine());
	  String sfives=new String(new char[100000]).replace("\0", "5");
	  String sthrees=new String(new char[100000]).replace("\0", "3");
	  int n,fives,threes;
	  for(int i=0;i<test;i++)
	  {
		  String s="";
		  n=Integer.parseInt(in.readLine());
		  if(n%3==0)
		  {
			  fives=3*(2*n-5*n/3);
			  threes=n-fives;
		  }
		  else
		  {
			  fives=3*(2*n-5*(n/3+1));
			  threes=n-fives;
		  }
		  if(threes >=0 && fives>=0)
			  s=sfives.substring(0,fives)+sthrees.substring(0,threes);
		  else
			  s="-1";
		  pw.println(s);
		  
	  }
	  pw.flush();
  }
 /* public static String create(String a)
  {
	  String s=a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a;
	  s=s+s+s+s+s;
	  while(s.length()!=100000)
	  {
		  s+=s;
	  }
	  return s;
  }*/
}
