#include <iostream>
using namespace std;

 int ConvertToBinary( int n)
{
	 int sum = 0;
	 int pos = 0;
	do
	{
		 int rem = n % 2;
		sum = sum + rem* pow(10, pos);
		pos++;
		n = n / 2;

	} while (n > 0);
	
	return sum;

}
 int reverseBinary( int bin)
{
	int sum = 0; int pos = 0;
	do
	{
		int rem = bin % 10;
		sum = sum * 10 + rem ;
		pos++;
		bin = bin / 10;
	}
	while (bin > 0);
	return sum;
}
 int convertToDec(int bin)
 {
	 int dec;
	 int pos = 0;
	 int sum = 0;
	 do
	 {
		 int rem = bin % 10;
		 sum = sum + rem * pow(2, pos);
		 pos++;
		 bin = bin / 10;

	 } while (bin > 0);
	 return sum;
 }
void main()
{
	char *eixt="N";
	 int num;
	 int numInBinary;
	 while (strcmp(eixt, "y") != 0)
	 {
		 cout << endl << "ENter the Number :: ";
		 cin >> num;

		 numInBinary = ConvertToBinary(num);
		 cout << endl << "Num in Binary : " << numInBinary;
		 int revBin = reverseBinary(numInBinary);
		 int newDec = convertToDec(revBin);
		 cout << endl <<"Rev Bin :: " << revBin;
		 cout << endl <<"New Dec Value : " << newDec;
		 cout << endl << "Exit :: ";
		 //cin >> eixt;

	 }
	
}