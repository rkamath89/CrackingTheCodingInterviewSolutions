package chapter11Ctci;

import java.util.Scanner;

public class rotatedArray {

	int findPointOfRotation(int[] roundedSortedArray,int low,int high)
	{
		int value=-1;
		while(low <= high)
		{

			int numOfElem = high-low+1;
			int mid = (low+high)/2;
			int next = (mid+1)%numOfElem;
			int prev = (mid+numOfElem-1)%numOfElem; // Do not go to negative so add N
			if(roundedSortedArray[low] < roundedSortedArray[high])
			{
				value = low;
				break;
			}
			else if( (roundedSortedArray[mid] <= roundedSortedArray[prev]) &&
					(roundedSortedArray[mid] <= roundedSortedArray[next]))
			{
				value = mid;
				break;
			}
			else if(roundedSortedArray[mid] <= roundedSortedArray[high])
			{
				high = mid-1;
			}
			else if(roundedSortedArray[mid] >= roundedSortedArray[low])
			{
				low = mid+1;
			}
			else
			{
				value = -1;
				break;
			}

		}
		return value;
	}
	int searchNumber(int[] array,int low,int high,int num)
	{
		int value =-1;
		if(high >= low)
		{
			int mid = (low+high)/2;
			if(array[mid] == num)
			{
				value = mid;
			}
			else if(array[low] <= array[mid])
			{
				if(array[low] <= num && array[mid] >= num)
				{
					value = searchNumber(array, low, mid, num);
				}
				else
				{
					value = searchNumber(array, mid+1, high, num);
				}
			}
			else if(array[mid] <= array[high])
			{
				if(array[mid] <= num && array[high] >= num)
				{
					value = searchNumber(array, mid+1, high, num);
				}
				else
				{
					value = searchNumber(array, low, mid-1, num);
				}
			}
			else if(array[mid] == array[low]) // Dupicate Scenario
			{
				
				if(array[mid] != array[high])
				{
					value = searchNumber(array, mid+1, high, num);
				}
				else
				{
					int tempVal =-1;
					tempVal = searchNumber(array, low, mid-1, num);
					if(tempVal == -1)
					{
						tempVal = searchNumber(array, mid+1, high, num);
					}
					value = tempVal;
					
				}
			}
		}
		return value;
	}
	public static void main(String[] args) 
	{
		rotatedArray rot = new rotatedArray();
		Scanner input = new Scanner(System.in);
		boolean isExit = false;
		int[] roundedSortedArray = {2,3,4,5,6,2};//{ 2, 2, 2, 4, 5, 6, 7, 8, 2 };
		while(!isExit)
		{
			System.out.println("1: Find Point of Rotation");
			System.out.println("2: Find element");
			
			int choice = input.nextInt();
			switch(choice)
			{
			case 1:
				int point = rot.findPointOfRotation(roundedSortedArray, 0, roundedSortedArray.length-1);
				point++;
				System.out.println("Point of Rotation : "+point);
				break;
			case 2:
				System.out.println(" Enter the Number to find");
				int num = input.nextInt();
				int pos = rot.searchNumber(roundedSortedArray,0,roundedSortedArray.length-1, num);
				System.out.println("Element found at :"+pos);
				break;
		
			}
		}
		

	}

}
