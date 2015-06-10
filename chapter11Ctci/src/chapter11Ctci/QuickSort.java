package chapter11Ctci;

public class QuickSort {

	void printAray(int[] unsortedArray)
	{
		for(int i=0;i<unsortedArray.length;i++)
		{
			System.out.print(unsortedArray[i]+" ");
		}
		System.out.println("");
	}
	public int partition(int[] unsortedArray,int low,int high)
	{
		int value  =-1;
		
		int pivotElement = unsortedArray[high];
		int pivot = low;
		for(int i=low;i<high;i++)
		{
			if(unsortedArray[i] <= pivotElement )
			{
				int temp = unsortedArray[i];
				unsortedArray[i] = unsortedArray[pivot];
				unsortedArray[pivot] = temp;
				pivot++;
			}
		}
		unsortedArray[high] = unsortedArray[pivot];
		unsortedArray[pivot] = pivotElement; 
		value =  pivot;
		return value;
	}
	public void quickSort(int[] unsortedArray,int low,int high)
	{
		if(high <= low)
		{
			return;
		}
		else
		{
			int pivotElement = partition(unsortedArray,low,high);
			quickSort(unsortedArray,low,pivotElement-1);
			quickSort(unsortedArray, pivotElement+1, high);
		}
	}
	public static void main(String[] args) 
	{
		QuickSort sort = new QuickSort();
		int[] unsortedArray = {20,5,3,2,1,4,0};
		System.out.println("Unsorted Array");
		sort.printAray(unsortedArray);
		sort.quickSort(unsortedArray, 0, unsortedArray.length-1);
		System.out.println("Sorted Array");
		sort.printAray(unsortedArray);

	}

}
