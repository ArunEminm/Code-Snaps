import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// The part of the program involving reading from STDIN and writing to STDOUT has been provided by us.

public class angrychildren {
   static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
   static StringBuilder out = new StringBuilder();

   public static void main(String[] args) throws NumberFormatException, IOException {
      int numPackets = Integer.parseInt(in.readLine());
      int numKids = Integer.parseInt(in.readLine());
      int[] packets = new int[numPackets];
      
      for(int i = 0; i < numPackets; i ++)
      {
         packets[i] = Integer.parseInt(in.readLine());
      }
      
      int unfairness = Integer.MAX_VALUE;
	  Arrays.sort(packets);
	  int[] diff=new int[numPackets-numKids+1];
	  for(int i=0;i<numPackets-numKids+1;i++)
	  {
		  diff[i]=packets[i+numKids-1]-packets[i];
	  }
	  Arrays.sort(diff);
      unfairness=diff[0];
      System.out.println(unfairness);
   }
}

