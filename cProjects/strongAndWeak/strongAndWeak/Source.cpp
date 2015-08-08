#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <sstream>
using namespace std;
void printvalues()
{
	int a1 = 10;
	int b1 = 20;
	int d1 = 20;
	static int c1 = 30;
	static int c2 = 30;
	cout << &a1 << " " << &b1 << " " << &c1 << " " << &c2 << " "  << &d1 << endl;
}
void main() {
	double a = 5.0;
	double *d = &a;
	int *b = (int*)d;
	int a1 = 10;
	cout << "Val of D : " << d << " Address of d :" << &d << " Value of *d :" << *d << endl;
	cout << "Val of B : " << b << " Address of B :" << &b << " Value of *b :" << *b << endl;

	cout << &a1 << endl;
	printvalues();
	int a2 = 10;
	cout << &a2 << endl;
	
	
	
	cout << "Val of a : " << a << " Address of a :"  << &a << endl;
	
	
	
	cout << b[0] << endl;
	cout << b[1] << endl;
	b[0] = 99;
	b[1] = 98;
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << a << endl;
	char te = _getch();
	//return 0;
}