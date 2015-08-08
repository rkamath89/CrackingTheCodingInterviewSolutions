#include <iostream>
#include <string>
using namespace std;

char* swap(char* name, int i, int j)
{
	char *newName = new char();
	strcpy(newName, name);
	char temp = newName[i];
	newName[i] = newName[j];
	newName[j] = temp;
	return newName;

}
void permute(char* name, int start, int end)
{
	if (start == end)
		cout << endl << name;
	else
	{
		for (int i = start; i < end; i++)
		{
			char *newname = swap(name, start, i);
			permute(newname, start + 1, end);
			//cout << endl << newname;
		}
	}
	
}
void main()
{
	bool isExit = false;
	while (!isExit)
	{
		char* name = "ABC";// new char();
		//cout << endl << " Enter your String :: ";
		//cin >> name;
		int end = strlen(name);
		permute(name, 0, end);
		cin >> isExit;
		
	}

}