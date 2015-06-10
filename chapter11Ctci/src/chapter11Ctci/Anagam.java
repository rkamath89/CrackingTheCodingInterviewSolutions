package chapter11Ctci;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Set;

// 11.2 CTci
// Anagram is Permutation of a String
// EG : RAT is , RTA, ART, TAR etc
public class Anagam 
{

	public static void main(String[] args) 
	{
		String[] words = {"RAT","BAT","CAT","ART","TAB","ACT"};
		HashMap<String,LinkedList<String>> anagramDict = new HashMap<String, LinkedList<String>>(); 
		for (String word : words) 
		{
			System.out.print(" "+word);
			char[] charWord = word.toCharArray();
			Arrays.sort(charWord);
			if(!anagramDict.containsKey(String.valueOf(charWord)))
			{
				anagramDict.put(String.valueOf(charWord), new LinkedList<String>());
			}
			anagramDict.get(String.valueOf(charWord)).add(word);
		}
		System.out.println(" ");
		Set<String> anagramKeys = anagramDict.keySet();
		int index =0;
		for(String keyVal : anagramKeys)
		{
			LinkedList<String> tempWord = anagramDict.get(keyVal);
			while(!tempWord.isEmpty())
			{
				words[index] = tempWord.pop();
				index++;
			}
		}
		for(String tempWord : words)
		{
			System.out.print(" "+tempWord);
		}
	}

}
