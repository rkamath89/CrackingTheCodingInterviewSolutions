package chapter1Ctci;

public class replaceString {

	
	public static void main(String[] args) 
	{
		String sent = "Hi How Are You";
		int numberOfSpaces=0;
		int newLength=0;
		for(int i=0;i<sent.length();i++)
		{
			if(sent.charAt(i) == ' ')
			{
				numberOfSpaces++;
			}
		}
		newLength = sent.length()+(numberOfSpaces*2);
		
		char[] newSentence = new char[newLength];
		for(int i=sent.length()-1;i>=0;i--)
		{
			if(sent.charAt(i) == ' ')
			{
				newSentence[newLength-1] = '0';
				newSentence[newLength-2] = '2';
				newSentence[newLength-3] = '%';
				newLength = newLength-3;
			}
			else
			{
				newSentence[newLength-1] = sent.charAt(i);
				newLength = newLength-1;
			}
		}
		System.out.println("Original :: "+sent.toString());
		System.out.println(" New Sentece :: "+new String(newSentence));

	}

}
