package chapter1Ctci;

import java.util.ArrayList;

public class uniqueString {

	public static void main(String[] args) 
	{
		String str = "aAbBb";
		int ascii[] = new int[128];
		for(int i=0;i<str.length();i++)
		{
			if(ascii[str.charAt(i)] == 1)
			{
				System.out.println("Duplicate exists");
				break;
			}
			ascii[str.charAt(i)] = 1;
			
		}
		

	}

}
