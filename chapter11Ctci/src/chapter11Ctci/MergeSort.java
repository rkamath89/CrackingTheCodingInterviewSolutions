package chapter11Ctci;

public class MergeSort 
{
	void merge(int[] unsoedArray,int[] leftArray,int mid,int[] rightArray,int high)
	{
		
		int i=0,j=0,k=0;
		while(i < mid && j < high)
		{
			if(leftArray[i] < rightArray[j])
			{
				unsoedArray[k] = leftArray[i];
				i++;
				k++;
			}
			else
			{
				unsoedArray[k] = rightArray[j];
				j++;
				k++;
			}
		}
		while(i < mid)
		{
			unsoedArray[k] = leftArray[i++];
			k++;
		}
		while(j < high)
		{
			unsoedArray[k] = rightArray[j++];
			k++;
		}
		
	}
	void mergeSort(int[] unsortedArray,int numOfElem)
	{
		if(numOfElem < 2)
		{
			return;
		}
		else
		{
			int mid= (numOfElem)/2;
			int[] leftArray = new int[mid];
			int[] rightArray = new int[numOfElem - mid];
			int i=0;
			for(int c=0;c<mid;c++)
			{
				leftArray[i] = unsortedArray[c];
				i++;
			}
			i=0;
			for(int c=mid;c<numOfElem;c++)
			{
				rightArray[i] = unsortedArray[c];
				i++;
			}
			mergeSort(leftArray,mid);
			mergeSort(rightArray,numOfElem-mid);
			merge(unsortedArray,leftArray,mid,rightArray,numOfElem-mid);
		}
	}

	public static void main(String[] args) 
	{
		int[] unsortedArray = {20,1,3,0,11,5};
		MergeSort sorting = new MergeSort();
		System.out.println(" Array Befoe Sorting");
		for(int i=0;i<unsortedArray.length;i++)
		{
			System.out.print(unsortedArray[i]+" ");
		}
		System.out.println("");
		sorting.mergeSort(unsortedArray,6);
		System.out.println(" Array after Sorting");
		for(int i=0;i<unsortedArray.length;i++)
		{
			System.out.print(unsortedArray[i]+" ");
		}
		System.out.println("");
	}

}
