package chapter1Ctci;

public class settingRowAndColTo0 {

	public static void printArray(int[][] arr)
	{
		for(int i=0; i < arr.length;i++)
		{
			for(int j=0;j<arr[0].length;j++)
			{
				System.out.print(" "+arr[i][j]);
			}
			System.out.println("");
		}
	}
	public static void main(String[] args) 
	{
		int[][] originalArray = { {0,2,3,1}, 
								  {4,5,3,6},
								  {7,0,9,10} };
		int[] rowWith0 = new int[originalArray.length]; // Means the Row has a 0 in it
		int[] colWith0 = new int[originalArray[0].length]; // Means the Col has a 0 in it
		System.out.println("Array before Reseet");
		printArray(originalArray);
		for(int i=0; i < originalArray.length;i++)
		{
			for(int j=0;j<originalArray[0].length;j++)
			{
				if(originalArray[i][j] == 0)
				{
					rowWith0[i] = 1;
					colWith0[j] = 1;
				}
			}
		}
		for(int i=0; i < originalArray.length;i++)
		{
			for(int j=0;j<originalArray[0].length;j++)
			{
				if(rowWith0[i] == 1)
				{
					for(int col=0; col < originalArray[i].length;col++)
					{
						originalArray[i][col] = 0;
					}
				}
				if(colWith0[j] == 1)
				{
					for(int row=0; row < originalArray.length;row++)
					{
						originalArray[row][j] = 0;
					}
				}
			}

		}
		System.out.println("Array afer Reseet");
		printArray(originalArray);
	}
}
