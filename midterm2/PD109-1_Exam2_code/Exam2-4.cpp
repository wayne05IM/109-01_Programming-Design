# include<iostream>
using namespace std;

int main() 
{
	int num_station = 0, change_time = 0, station_start = 0, station_end = 0, temp = 0;
	cin >> num_station >> change_time >> station_start >> station_end;
	
	// Deal with data input
	int ticket[num_station][num_station];
	for(int i = 0 ; i < num_station - 1 ; i++)
	{
		for(int j = i + 1 ; j < num_station ; j++)
		{
			cin >> temp; 
			ticket[i][j] = temp;
			ticket[j][i] = temp;
		}		
	}
	
	// Create two array for apply Dijkstra algorithm, if we want to know the total step
	int* this_step = new int[num_station];
	int* next_step = new int[num_station];
	
	// Set the starting distance, 99999 as infinity
	for(int i = 0 ; i < num_station ; i++)
	{
		ticket[i][i] = 1;
		this_step[i] = 99999;
		next_step[i] = 99999;
	}
	// Set the distance of the starting point as 0
	this_step[station_start-1] = 0;
	next_step[station_start-1] = 0;
	
	// Dijkstra algorithm
	for(int step = 0 ; step <= change_time ; step++)
	{
		for(int i = 0 ; i < num_station ; i++)
		{
			for(int j = 0 ; j < num_station ; j++)
			{
				// If a faster move if found, save the data into the next array
				if(next_step[j] > this_step[i] + ticket[i][j])
				{
					next_step[j] = this_step[i] + ticket[i][j];
				}
			}
		}
		// After every node is visited, put all number from next array to the previous array		
		for(int i = 0 ; i < num_station ; i++)
		{
			this_step[i] = next_step[i];
		}
	}
	
	// The answer is in the array
	cout << this_step[station_end];
	
	return 0;
}
