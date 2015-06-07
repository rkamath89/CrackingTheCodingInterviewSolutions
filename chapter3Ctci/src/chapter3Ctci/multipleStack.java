package chapter3Ctci;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class multipleStack extends Stack
{
	final int MAX_SIZE =2;
	static multipleStack mulStack = new multipleStack();
	ArrayList<Stack> multiStackArray = new ArrayList<Stack>();
	static int curentStack = 0; // Which stack is the Current index
	void setCurrentStack(int val)
	{
		curentStack = val;
	}
	int getCurrentStack()
	{
		return curentStack;
	}
	void pushMultiStack(int value)
	{
		int currStack = mulStack.getCurrentStack();
		if(multiStackArray.size() == 0)
		{
			System.out.println(" Created a NewStack on the StackArray");
			Stack newStack = new Stack();
			newStack.currentSize++;
			newStack.push(value);
			multiStackArray.add(newStack);
		}
		else
		{
			if(multiStackArray.get(currStack).currentSize == MAX_SIZE)
			{
				System.out.println(" Created a NewStack on the StackArray, prev stack was full");
				Stack newStack = new Stack();
				newStack.currentSize++;
				newStack.push(value);
				multiStackArray.add(newStack);
				mulStack.setCurrentStack(++currStack);
			}
			else
			{
				System.out.println("Pushed val "+value+" on old stack");
				multiStackArray.get(currStack).currentSize++;
				multiStackArray.get(currStack).push(value);
			}
			
		}
	}
	int popMultiStack()
	{
		int value=-1;
		if(multiStackArray.size() == 0)
		{
			
		}
		else
		{
			int currStack = mulStack.getCurrentStack();
			value = multiStackArray.get(currStack).pop();
			multiStackArray.get(currStack).currentSize--;
			if(multiStackArray.get(currStack).currentSize == 0 )
			{
				multiStackArray.remove(currStack);
				mulStack.setCurrentStack(--currStack);
			}
			
			
		}
		return value;
	}
	
	void printMultiStack()
	{
		if(multiStackArray.size() == 0)
		{
			System.out.println(" Stack is Empty");
		}
		else
		{
			for(int i=0;i<multiStackArray.size();i++)
			{
				System.out.println("");
				System.out.println("Contents of Stack : "+i);
				
				Stack tempStack = multiStackArray.get(i);
				tempStack.printQueue(tempStack.top);
			}
		}
	}
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		boolean isExit = false;
		while(!isExit)
		{
			System.out.println("1: Add to Stack");
			System.out.println("2: Pop from Stack");
			System.out.println("3: Print Elements in Stack");
			System.out.println("4: Pop at Index");// Should Implement
			
			int choice = input.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println(" Eneter element to add  to Queue");
				int val = input.nextInt();
				mulStack.pushMultiStack(val);
				break;
			case 2:
				int val2 = mulStack.popMultiStack();//pop();
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
				mulStack.printMultiStack();
				break;
			case 4:
				int popVal = mulStack.popMultiStack();
				if(popVal == -1)
				{
					System.out.println(" Stack is Empty");
				}
				else
				{
					System.out.println(popVal+" Popped");
				}
				break;
		
			}
		}
	

	}

}
