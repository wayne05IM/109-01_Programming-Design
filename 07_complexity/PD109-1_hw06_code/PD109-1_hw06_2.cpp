# include<iostream>
using namespace std;
 
int main() 
{
	int ideal = 0, breakdown = 0, fix_time = 0, begin = 0, total_time = 0, stable = 0;
	cin >> ideal >> breakdown >> fix_time >> begin >> total_time >> stable;
	
	int efficiency = begin, profit = 0;
	
	for(int i = 0 ; i < total_time ; i++)
	{
		efficiency -= breakdown;
		if(efficiency < stable)
		{
			efficiency = stable;
		}
		profit += efficiency * ideal / 100;
	}
	
	int best_fix_time = 0, best_profit = profit;
	
	for(int i = 0 ; i < total_time ; i++)
	{
		efficiency = begin;
		profit = 0;
		
		for(int j = 0 ; j < total_time ; j++)
		{
			efficiency -= breakdown;			
			if(j >= i and j <= i + fix_time - 1)
			{
				efficiency = 0;
			}
			else if(j == i + fix_time)
			{
				efficiency = 100;
			}
			else if(efficiency < stable)
			{
				efficiency = stable;
			}			
			profit += efficiency * ideal / 100;
		}
		
		if(profit > best_profit)
		{
			best_profit = profit;
			best_fix_time = i+1;
		}
	}
	cout << best_fix_time << "," << best_profit;
	
	return 0;	
}
