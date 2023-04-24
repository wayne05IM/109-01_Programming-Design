#include <iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0, num3 = 0, count = 0;
	cin >> num1 >> num2 >> num3;
	
	if(num1 == num2)
	{
		count ++;
	}
	if(num2 == num3)
	{
		count ++;
	}
	if(num1 == num3)
	{
		count ++;
	}
	
	if(count == 3)
	{
		cout << 1;
	}
	else if(count == 1)
	{
		cout << 2;
	}
	else if(count == 0)
	{
		cout << 3;
	}
	
	return 0;	
} 
