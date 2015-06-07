package chapter3Ctci;

import java.util.Scanner;

public class minimumStack extends Stack
{
	static int minValue=999;
	static Stack actualStack=null,minStack=null;
	static int getMin()
	{
		int val = 999;
		if(minStack == null)
		{
			val = 999;
		}
		else
		{
			val = minStack.peek();
		}
		return val;
	}
	void pushMin(int val)
	{
		if(minStack == null && actualStack == null)
		{
			minStack= new Stack();
			actualStack= new Stack();
			minStack.push(val);
		}
		else
		{
			if(val < getMin())
			{
				minStack.push(val);
			}
		}
		actualStack.push(val);

	}
	int popMin()
	{
		int value =-1;
		value = actualStack.pop();
		if(value == getMin())
		{
			minStack.pop();
		}
		return value;
	}
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		minimumStack minStack = new minimumStack();
		boolean isExit = false;
		while(!isExit)
		{
			System.out.println("1: Add to Queue");
			System.out.println("2: Pop from Queue");
			System.out.println("3: Print Elements in Queue");
			System.out.println("4: Find Min of Queue");
			int choice = input.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println(" Eneter element to add  to Queue");
				int val = input.nextInt();
				minStack.pushMin(val);
				break;
			case 2:
				int val2 = minStack.popMin();//pop();
				if(val2 == -1)
				{
					System.out.println(" Queue is Empty");
				}
				else
				{
					System.out.println(val2+" Popped");
				}
				break;
			case 3:
				minStack.printQueue(minStack.actualStack.top);
				break;
			case 4:
				int minVal =minStack.getMin();
				System.out.println("Min of Queue is : "+minVal);
				break;
			}
		}
	}
}
