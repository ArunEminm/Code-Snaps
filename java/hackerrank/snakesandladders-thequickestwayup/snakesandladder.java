import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class snakesandladder
 {

    public static void main(String[] args) throws IOException
    {
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	PrintWriter pw=new PrintWriter(System.out);
	int testcases=Integer.parseInt(br.readLine());
	while(testcases-->0)
	{
		String[] s1;
		s1=br.readLine().split(",");
		int ladders=Integer.parseInt(s1[0]);
		int snakes=Integer.parseInt(s1[1]);
		int[] graph=new int[101];
		int[][] weight=new int[101][101];
		String[] color=new String[101];
		int[] distance=new int[101];
		s1=br.readLine().split(" ");
		String[] s2;
		for(int i=0;i<ladders;i++)
		{
			s2=s1[i].split(",");
			graph[Integer.parseInt(s2[0])]=Integer.parseInt(s2[1]);
		}
		s1=br.readLine().split(" ");
		for(int i=0;i<snakes;i++)
		{
			s2=s1[i].split(",");
			graph[Integer.parseInt(s2[0])]=Integer.parseInt(s2[1]);
		}
		//printgraph(graph);
		System.out.println(quickest(graph,weight,color,distance));
	}
	
	}
	
	public static int quickest(int[] graph,int[][] weight,String[] color,int[] distance)
	{
		for(int i=2;i<graph.length;i++)
		{
			color[i]="N";
			distance[i]=Integer.MAX_VALUE;
		}
		color[1]="V";
		distance[1]=0;
		Queue<Integer> Q=new LinkedList<Integer>();
		Q.add(1);
		int u=1;
		while(!Q.isEmpty())
		{
			
			u=Q.remove();
			if(u==100) break;
			//System.out.println("queue->"+Q);
			int i=u;
			//System.out.println("removed->"+i);
			while(++i<graph.length && i<=u+6)
			{
				//System.out.println(u+" "+i);
				if(color[i].equals("N"))
				{
					color[i]="V";
					distance[i]=distance[u]+1;
					//System.out.println(i+"-"+distance[i]);
					if(graph[i]!=0)
					{
						Q.add(graph[i]);
						color[graph[i]]="V";
						distance[graph[i]]=distance[u]+1;
					}
					else
					{
						Q.add(i);
					}
				}
			}
		}
		//printArray(distance);
		return distance[100];
	}
	
	public static void printArray(int[] g)
	{
		for(int i:g)
			System.out.print(i+" ");
	}

}
