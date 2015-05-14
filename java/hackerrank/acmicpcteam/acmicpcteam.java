import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class acmicpcteam {

    public static void main(String[] args) throws IOException
    {
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	String[] s=in.readLine().split(" ");
	String s2;

	int arraylength=Integer.parseInt(s[1]);
	int people=Integer.parseInt(s[0]);

	int[][] know= new int[people][arraylength];
	int[] sum=new int[arraylength];
	for(int i=0;i<people;i++)
	{
	  s2=in.readLine();
	  for(int j=0;j<arraylength;j++)
	  {
		  know[i][j]=Character.getNumericValue(s2.charAt(j));
	  }
	}

	int newlength=(arraylength-1)*arraylength/2;
	int[][] newarray=new int[newlength][arraylength];

	int sweep=0;
	{
	  for(int i=0;i<people;i++)
	  {
		  for(int j=i+1;j<people;j++)
		  {
			  for(int span=0;span<arraylength;span++)
			  {
				  newarray[sweep][span]=know[i][span]|know[j][span];
			  }
			  sweep++;
		  }
	  }

	}

	int[] newarrayspansum=new int[newlength];
	for(int fill=0;fill<newlength;fill++)
	{
	  newarrayspansum[fill]=0;
	  for(int span=0;span<arraylength;span++)
	  {
		  newarrayspansum[fill]+=newarray[fill][span];
		  
	  }
	}
	Arrays.sort(newarrayspansum);

	int max=newarrayspansum[newlength-1];
	int i=newlength-1;
	int count=0;
	do
	{
	  count++;
	  i--;
	}while(max==newarrayspansum[i]);

	System.out.println(max);
	System.out.println(count);

	}
}
