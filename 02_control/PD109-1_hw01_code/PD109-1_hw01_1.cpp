#include<iostream>
using namespace std;

int main()
{
	int x1 = 0, p1 = 0, x2 = 0, p2 = 0, t = 0, b = 0;
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
		cout << t - x1*p1 - x2*p2;
	}
	
	return 0;
}


