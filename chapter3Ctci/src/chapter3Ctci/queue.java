package chapter3Ctci;

import java.util.Scanner;

public class queue 
{
	Stack inQueue,outQueue = null;
	void addToQueue(int val)
	{

		if(inQueue == null)
		{
			inQueue = new Stack();
			inQueue.currentSize++;
			inQueue.push(val);
		}
		else
		{
			inQueue.currentSize++;
			inQueue.push(val);
		}
	}
	int removeFromQueue()
	{
		int value =-1;
		if(outQueue == null)
		{
			outQueue = new Stack();
			while(inQueue.currentSize > 0)
			{
				inQueue.currentSize--;
				int tempvalue = inQueue.pop();
				outQueue.currentSize++;
				outQueue.push(tempvalue);
			}
			if(outQueue.currentSize > 0)
			{
				outQueue.currentSize--;
				value = outQueue.pop();
			}
		}
		else
		{
			if(outQueue.currentSize <= 0 && inQueue.currentSize > 0)
			{
				while(inQueue.currentSize > 0)
				{
					inQueue.currentSize--;
					int tempvalue = inQueue.pop();
					outQueue.currentSize++;
					outQueue.push(tempvalue);
				}
			}
			if(outQueue.currentSize > 0)
			{
				outQueue.currentSize--;
				value = outQueue.pop();
			}
		}
		return value;
	}
	public static void main(String[] args) 
	{
		queue queueUsingStack = new queue();
		Scanner input = new Scanner(System.in);
		boolean isExit = false;
		while(!isExit)
		{
			System.out.println("1: Add to Queue");
			System.out.println("2: Pop from Queue");
			System.out.println("3: Print Elements in Queue");

			int choice = input.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println(" Eneter element to add  to Queue");
				int val = input.nextInt();
				queueUsingStack.addToQueue(val);
				break;
			case 2:
				int val2 = queueUsingStack.removeFromQueue();//pop();
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
				System.out.println(" COntents of InQueue");
				queueUsingStack.inQueue.printQueue(queueUsingStack.inQueue.top);
				System.out.println(" COntents of OutQueue");
				queueUsingStack.outQueue.printQueue(queueUsingStack.outQueue.top);
				break;

			}
		}



	}

}
