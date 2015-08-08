#include <iostream>
#include <string>
using namespace std;

void main()
{
//R:82
//A : 65
//H : 72
//U : 85
//L : 76
	string name = "RAHUL";
	int nameIntValues[6];
	cout << " Name is : " <<  name << endl;
	for (int i = 0; i < name.length(); i++)
	{
		nameIntValues[i] = name[i];
	}
	//nameIntValues[5] = '\0';
	char newName[6];
	for (int i = 0; i < name.length(); i++)
	{
		newName[i] = nameIntValues[i];
	}
	newName[5] = '\0';
	cout << " New Name : " << newName;
	while (1)
	{

	}

}