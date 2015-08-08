#include <iostream>
#include <map>
#include <string>
#include <map>
#include <iterator>
using namespace std;


void main()
{
	string name, value;
	bool exitProg = false;
	map<string, string> hashMap;
	while (!exitProg)
	{
		
		cout << endl << " Enter the Value to Hash :";
		cin >> name;
		if (hashMap.count(name) == 0)
		{
			cout << endl << "ENter the Value of " << name << " :";
			cin >> value;
			hashMap[name] = value;
		}
		else
		{
			cout << endl << " Count :: " << hashMap.count(name);
			cout << endl << " Value Exists for " << name << " existing Value ::" << hashMap[name];
			cout << endl << "ENter the New Value of " << name << " :";
			cin >> value;

			hashMap[name] = value;
		}
	}
}