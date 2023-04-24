# include<iostream>
using namespace std;
 
int main() 
{
	float ideal = 0;
	int breakdown = 0, fix_time = 0, begin = 0, total_time = 0, stable = 0, num_demand = 0;
	cin >> ideal >> breakdown >> fix_time >> begin >> total_time >> stable >> num_demand;
	
	float demand[num_demand] = {0};
	int finished_demand = 0, finished_time[num_demand] = {0};
	for(int i = 0 ; i < num_demand ; i++)
	{
		cin >> demand[i];
	}
	
	finished_time[0] = 1;
	float efficiency = begin;
	
	for(int i = 0 ; i < total_time ; i++)
	{
		efficiency -= breakdown;
		if(efficiency < stable)
		{
			efficiency = stable;
		}
		
		demand[finished_demand] -= efficiency * ideal / 100;
		
		//cout << finished_demand << " " << demand[finished_demand] << "\n";
		
		if(demand[finished_demand] <= 0)
		{
			finished_demand++;
			if(finished_demand >= num_demand)
			{
				break;
			}
			else
			{
				finished_time[finished_demand] = i+2;
			}		
		}		
	}
	
	for(int i = 0 ; i < num_demand ; i++)
	{
		cout << finished_time[i];
		if(i < num_demand - 1)
		{
			cout << ",";
		}
	}
		
	return 0;	
}
