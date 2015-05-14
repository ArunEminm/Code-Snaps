import java.io.*;


public class alternatingcharacters
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw= new PrintWriter(System.out);
		
		int TestCount=Integer.parseInt(br.readLine());
		
		while(TestCount-->0)
		{
			pw.println(solution(br.readLine()));
		}
		
		pw.flush();
		
	}
	public static int solution(String s)
	{
		int res=0;
		int i=0,j=i+1;
		while(j<s.length())
		{
			if(s.charAt(i)==s.charAt(j))
			{
				res+=1;
				j+=1;
			}
			else
			{
				i=j;
				j+=1;
			}
		}
		return res;
	}
}
