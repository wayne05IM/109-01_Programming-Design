#include<iostream>
using namespace std;

int main()
{
	int x1 = 0, p1 = 0, x2 = 0, p2 = 0, t = 0, b = 0, charge = 0;
	cin >> x1 >> p1 >> x2 >> p2 >> t >> b;
	
	if(b < x1 + x2)
	{
		cout << -1;
	}
	else if(t < x1*p1 + x2*p2)
	{
		cout << -2;
	}
	else
	{
		//Sadly that I can not use array this week = =
		//Or else by utilizing array, these codes can be better.
		
		charge = t - x1*p1 - x2*p2;
		cout << charge / 500 << ",";
		charge = charge % 500;
		cout << charge / 100 << ",";
		charge = charge % 100;
		cout << charge / 50 << ",";
		charge = charge % 50;
		cout << charge / 10 << ",";
		charge = charge % 10;
		cout << charge / 5 << ",";
		charge = charge % 5;
		cout << charge;
	}
	
	return 0;
}


