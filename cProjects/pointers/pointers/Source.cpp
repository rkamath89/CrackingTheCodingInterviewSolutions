#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	int arr[3] = { 1, 2, 3 };
	double arr1[3];
	int *p;
	
	p = arr;
	
	double *q;
	
	q = arr1;
	/*cout << " address of Array " << &arr1[0] << " " << &arr1[1] << " " << &arr1[2] << " " << endl;
	cout << " Address for q :: " << q << " " << q++ << " " << q++ << endl;
	cout << " address of Array " << &arr[0] << " " << &arr[1] << " " << &arr[2] << " " << endl;
	cout << " Address for p :: " << p << " " << p++ << " " << p++ << endl;*/
	

	// To check length of string and size of string
	char *str1 = "Hello";//5 char
	cout << " 5th element " << str1[4] << " String : " << str1;
	_getch();
}