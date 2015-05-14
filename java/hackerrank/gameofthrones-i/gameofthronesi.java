//Inserts nodes in sorted way if element is already there it doesn't insert

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class gameofthronesi
{
	
	static class Node
	{
		int key;
		char ch;
		Node next;
		Node prev;
	
	
	Node()
	{
		
	}
	Node(char b,Node p,Node n)
	{
		this.key=1;
		this.ch=b;
		this.next=n;
		this.prev=p;
	}
	
	}
	
	public static void main(String[] args) throws IOException
	{
		Node list=new Node();
		list=null;
		Node node;
		
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		
		String s=br.readLine();
		for(int i=0;i<s.length();i++)
		{
			node=insert(list,s.charAt(i));
			list=node;
		}
		
		int res=traverse(list);
		if(res>1)
			System.out.println("NO");
		else
			System.out.println("YES");
		
	}
	
	
	public static Node insert(Node list,char a)
	{
		Node node,head,temp;
		temp=list;
		head=list;
		node=new Node(a,null,null);
		while(list!=null)
		{
			if(list.ch==a)
			{
				temp=list;
				temp.key+=1;
				temp.key=temp.key%2;
				return gethead(temp);
			}
			list=list.next;
		}
		list=head;
		{
			if(list==null)
			{
				list=node;
				return list;
			}
			else if((int)list.ch>a)
			{
				node.next=list;
				list.prev=node;
				return node;
			}
			else
			{
				temp=list;
				while(list!=null && (int)list.ch<a)
				{
					temp=list;
					list=list.next;
				}
				temp.next=node;
				node.prev=temp;
				node.next=list;
				if(list==null)
					return gethead(node);
				else
				{
					list.prev=node;
					return gethead(node);
				}
			}
			
		}

		
	}

	public static int traverse(Node list)
	{
		int s=0;
		while(list!=null)
		{
			s=s+list.key;
			list=list.next;
		}
		return s;
	}
	
	public static Node gethead(Node list)
	{
		while(list.prev!=null)
		{
			list=list.prev;
		}
		return list;
	}
	
	
}

