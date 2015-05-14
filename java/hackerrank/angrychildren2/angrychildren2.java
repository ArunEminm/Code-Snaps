import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.*;

// The part of the program involving reading from STDIN and writing to STDOUT has been provided by us.

public class angrychildren2 {
 
 public static void main(String[] args) throws NumberFormatException, IOException {

      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw=new PrintWriter(System.out);
      int numPackets = Integer.parseInt(in.readLine());
      int numKids = Integer.parseInt(in.readLine());
      long[] packets = new long[numPackets];
     
      for(int i = 0; i < numPackets;i++)
      {
         packets[i] = Long.parseLong(in.readLine());
      }
     
      Arrays.sort(packets);
      long unfairness=0l,sum=0l;
      int index=0;
      for(int i=1-numKids;i<=numKids-1;i+=2)
      {
       unfairness+=i*packets[index];
       index++;
      }
      //index=0;
      //System.out.println(unfairness);
      for(int i=0;i<numKids-1;i++)
      {
       sum+=packets[i];
      }
      //System.out.println(sum);
      long min=unfairness;
      for(int i=1;i<numPackets-numKids;i++)
      {
       sum+=packets[i+numKids-2]-packets[i-1];
       unfairness+=(numKids-1)*(packets[i+numKids-1]+packets[i-1])-2*sum;
       if(min>unfairness)
       {
        min=unfairness;
        index=i;
       }
      }
      //for(int i=0;i<numKids;i++)
      {
       //System.out.println(packets[index+i]);
      }
      System.out.println(min);
   }
}
