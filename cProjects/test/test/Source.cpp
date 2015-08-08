

// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;


void main()
{
	int val = 10;
	int *ptr1 = new int(val);
	cout << " Ptr address : " << &ptr1 << " Val address :: " << &val << " Value :: " << val << " Ptr Value : " << ptr1 << " Ptr content :" << *ptr1;
	delete ptr1;
	cout << " Val address :: " << &val << " Value :: " << val;
	//cout << " Ptr Value : " << ptr1 << " Ptr content :" << *ptr1;
	cin >> val;
}


/*
// Function to swap values at two pointers 
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack
		}
	}
}

// Driver program to test above functions 
int main()
{
	char str[] = "RAH";
	int n = strlen(str);
	permute(str, 0, n - 1);
	int val = 0;
	cin >> val;
	return 0;
}
*/

/*
#include <iostream>
#include "Header.h"
using namespace std;

int Distance::getInnches()
{
	return inches;
}
void main()
{
	Distance d1,d2;
	d1.setFeet(10);
	d1.setInches(10);
	d1.setName("Rahul");
	cout << " D1 : Feet : " << d1.getFeet() << "  , Inches :" << d1.getInnches() <<" ,Name ::"<< d1.getName() << endl;
	
	d2 = d1;
	d2.setFeet(20);
	d2.name = "RA";
	cout << " D1 : Feet : " << d1.getFeet() << "  , Inches :" << d1.getInnches() << " ,Name ::" << d1.getName() << endl;
	cout << " D2 : Feet : " << d2.getFeet() << "  , Inches :" << d2.getInnches() << " ,Name ::" << d2.getName() << endl;


	char *number = "12345";
	char newNum[10];
	int i = 0;
	int value=0;
	cout << number + 4;
	while (number[i] != '\0')
	{
		value = value*10 + (number[i] - '0');
		i++;
	}
	cout << endl << value;
	int rem,j=1,pos=0;
	while (value > 0)
	{
		int mod = pow(10, j);
		j++;
		rem = value % mod;
		value = value - rem;
		
			rem = rem / (mod/10);
			newNum[pos++] = rem+'0';
		cout << endl << rem << " " << value;
	}
	newNum[pos] = '\0';
	cout << endl << "New Num :" << newNum;
	
	int temp;

	cin >> temp;
}
*/