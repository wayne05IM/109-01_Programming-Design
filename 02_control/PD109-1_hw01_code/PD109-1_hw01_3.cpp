#include<iostream>
using namespace std;

int main()
{
	int n = 0, t = 0, b = 0, total_ticket = 0, total_cost = 0, temp_ticket = 0, temp_cost = 0, charge = 0;
	cin >> n >> t >> b;
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> temp_ticket >> temp_cost;
		total_ticket += temp_ticket;
		total_cost += temp_cost * temp_ticket;
	}
	
	if(b < total_ticket)
	{
		cout << -1;
	}
	else if(t < total_cost)
	{
		cout << -2;
	}
	else
	{
		//Sadly that I can not use array this week = =
		//Or else by utilizing array, these codes can be better.
		
		charge = t - total_cost;
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


