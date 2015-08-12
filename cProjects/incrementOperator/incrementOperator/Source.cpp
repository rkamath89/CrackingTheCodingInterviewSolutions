#include <iostream>
using namespace std;

void fibo(int n)
{
	int num = 0;
	int first = 0;
	int second = 1;
	cout << endl;
	cout << first << "," << second;
	//0 1 1 2 3 5
	for (int i = 0; i < n - 2; i++)
	{
		
		num = first + second;
		first = second;
		second = num;
		
		cout << "," << num;
	}
}
int fibRec(int num)
{
	if (num == 0)
	{
		//cout << " " << 0;
		return 0;
	}
		
	if (num == 1)
	{
		//cout << " " << 1;
		return 1;
	}
		
	else
	{
		int n = fibRec(num - 1) + fibRec(num - 2);
		//cout << " " << n;
		return n;
	}
		

}
void main()
{
	for (int i = 0; i <= 10; i++)
	{
		cout << " " << i;
	}
	cout << endl; cout << endl;
	for (int i = 0; i <= 10; ++i)
	{
		cout << " " << i;
	}
	cout << endl; cout << endl;
	int temp = 1;
	cout << temp++;
	cout << ++temp;
	fibo(10);
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << " " << fibRec(i);
	}
	int k;
	cin >> k;


}