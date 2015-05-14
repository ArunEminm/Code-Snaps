//https://www.hackerrank.com/challenges/longest-increasing-subsequent

import java.io.*;
import java.util.*;
import java.io.*;
public class patiencesort
{
    public static <E extends Comparable<? super E>> void sort (E[] n)
    {
        List<Pile<E>> piles = new ArrayList<Pile<E>>();
        // sort into piles
        for (E x : n)
        {
            Pile<E> newPile = new Pile<E>();
            newPile.push(x);
            int i = Collections.binarySearch(piles, newPile);
            if (i < 0) i = ~i;
            if (i != piles.size())
                piles.get(i).push(x);
            else
                piles.add(newPile);
        }
        //System.out.println("longest increasing subsequence has length = " + piles.size());
        System.out.println(piles.size());
 
        // priority queue allows us to retrieve least pile efficiently
        PriorityQueue<Pile<E>> heap = new PriorityQueue<Pile<E>>(piles);
        for (int c = 0; c < n.length; c++)
        {
            Pile<E> smallPile = heap.poll();
            n[c] = smallPile.pop();
            if (!smallPile.isEmpty())
                heap.offer(smallPile);
        }
        assert(heap.isEmpty());
    }
 
    private static class Pile<E extends Comparable<? super E>> extends Stack<E> implements Comparable<Pile<E>>
    {
        public int compareTo(Pile<E> y) 
        { 
        	return peek().compareTo(y.peek()); 
        }
    }
    
    public static void main(String[] args) throws IOException
    {
    	        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		
		int N=Integer.parseInt(br.readLine());
		Integer[] list=new Integer[N];
		
		for(int i=0;i<N;i++)
		{
			list[i]=Integer.parseInt(br.readLine());
		}
		
		sort(list);
    }
}
