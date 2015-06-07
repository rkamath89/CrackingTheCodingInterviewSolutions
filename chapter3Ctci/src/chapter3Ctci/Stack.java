package chapter3Ctci;
import org.omg.CORBA.FREE_MEM;

import chapter3Ctci.Node;

public class Stack 
{
	public Node top=null;
	
	public int currentSize=0;
	void push(int value)
	{
		if(top == null)
		{
			top = new Node(value,null);
			
		}
		else
		{
			Node node = new Node(value,top);
			top = node;			
		}
	}
	int pop()
	{
		int value =-1;
		if(top == null)
		{
			System.out.println(" Stack is empty");
		}
		else
		{
			value = top.value;
			top = top.nextNode;
		}
		return value;
	}
	void printQueue(Node node)
	{
		Node temp ;
		if(node == null)
			temp = top;
		else
			temp = node;
		if(temp == null)
		{
			System.out.println(" Queue is Empty");
		}
		else
		{
			while(temp != null)
			{
				System.out.print(temp.value+" ->");
				temp = temp.nextNode;
			}
			System.out.println();
		}
	}
	int peek()
	{
		int val =999;
		if(top != null)
		{
			val = top.value;
		}
		return val;
	}
}
