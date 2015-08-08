// pointer to functions
#include <iostream>
#include <conio.h>
using namespace std;


int add(int num1, int num2)
{
	return num1 + num2;
}
int sub(int num1, int num2)
{
	return num1 - num2;
}
int oper(int num1, int num2, int(*opname)(int, int))
{
	int temp;
	temp = (*opname)(num1, num2);
	return temp;
}
void main()
{
	int(*tempName)(int, int) = sub;
	cout << oper(1, 2, add);
	cout << endl << oper(2, 1, tempName);
	_getch();
}