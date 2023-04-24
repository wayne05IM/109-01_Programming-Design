# include<iostream>
using namespace std;

// This model is done by BFS,
// which is a slower but relatively easy algoritm.
// If you wish to see algorithm like DFS, please contact TA
 
int main() 
{
	int num_node = 0, num_line = 0, num_target = 0;
	
	cin >> num_node >> num_line;
	int graph[num_node][num_node] = {0};
	for(int i = 0 ; i < num_node ; i++)
	{
		for(int j = 0 ; j < num_node ; j++)
		{
			graph[i][j] = 0;
		}
	}
	
	int node1 = 0, node2 = 0;
	for(int i = 0 ; i < num_line ; i++)
	{
		cin >> node1 >> node2;
		graph[node1-1][node2-1] = 1;
	}
	
	cin >> num_target;
	int target[num_target] = {0};
	for(int i = 0 ; i < num_target ; i++)
	{
		cin >> target[i];
	}
	
	bool change = false, answer = 0;
	while(true)
	{
		change = false;
		for(int i = 0 ; i < num_target ; i++)
		{
			for(int j = 0 ; j < num_target ; j++)
			{
				if(graph[target[i]-1][target[j]-1] == 1)
				{
					for(int k = 0 ; k < num_target ; k++)
					{
						if(graph[target[j]-1][target[k]-1] == 1 and graph[target[i]-1][target[k]-1] == 0)
						{
							graph[target[i]-1][target[k]-1] = 1;
							change = true;
						}
					}
				}
			}
			
			if(graph[target[i]-1][target[i]-1] == 1)
			{
				answer = 1;
				break;
			}
		}
		
		if(answer == 1 or !change)
		{
			break;
		}
	}
	
	cout << answer;
	return 0;
}
