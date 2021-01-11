//17608
package javaproject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

class Stack{
	private LinkedList<Integer>stack=new LinkedList<Integer>();
	private int top;
	
	public Stack() {	top=-1;	}
	public void push(int element)
	{
		stack.addFirst(element);
		top++;
	}
	
	public int pop() {
		if(isEmpty())
			return -1;
		
		top--;
		return stack.removeFirst();
	}
	
	public int getElement() {
		if(isEmpty())
			return -1;
		return stack.getFirst();
	}
	
	public int size() {
		return top;
	}
	
	public boolean isEmpty() {
		if(top==-1)	return true;
		return false;
	}
}

public class Main {
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		Stack stick=new Stack();
		for(int i=0;i<N;i++)
		{
			int element=Integer.parseInt(br.readLine());
			if(stick.isEmpty())
				stick.push(element);
			else		//비교
			{
				while(!stick.isEmpty()&&stick.getElement()<=element) {
					stick.pop();
				}
				stick.push(element);
			}
		}

		System.out.print(stick.size()+1);
		br.close();
	} 
}
