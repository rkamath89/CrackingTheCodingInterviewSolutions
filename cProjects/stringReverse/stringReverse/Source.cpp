#include <iostream>
using namespace std;

void reverse(char *str,int i)
{
	i++;
	if (str[i] == '\0')
	{ 
		return;
	}
	else
	{
		reverse(str, i);
		cout << str[i];
	}
}
void swap(char * start, char *end)
{
	char  temp;
	while (start < end)
	{
		temp = *end;
		*end = *start;
		*start = temp;
		end--;
		start++;
	}
}
void reverseWord(char *str)
{
	char *start = str;
	char *end = str;
	while(*end)
	{
		end++;
		if (*end == '\0')
			swap(start, end - 1);
		else if (*end == ' ')
		{
			swap(start, end-1);
			start = end + 1;
		}
	}
	swap(str, end-1);
}
void main()
{
	char str[] = "Hi Rahul";
	//reverse(str, -1);
	reverseWord(str);
	cout << endl << " Reversed Sting is :: " << str;
	int exit = 0;
	cin >> exit;
}