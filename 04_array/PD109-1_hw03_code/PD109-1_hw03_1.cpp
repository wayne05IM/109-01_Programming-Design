#include<iostream>
using namespace std;

int main()
{
	int ticket_type = 0, ticket_max = 0, temp_ticket = 0, temp_cost = 0, cal_total_cost = 0, last_ticket = 0;
	
	cin >> ticket_type >> ticket_max;
	
	int num_ticket[ticket_type] = {0}, cost_ticket[ticket_type] = {0}, total_cost[ticket_type] = {0}; 
	
	//save all data in three array, the third one is calculated total cost
	for(int i = 0; i < ticket_type ; i++)
	{
		cin >> temp_ticket >> temp_cost;
		cal_total_cost += (temp_ticket - last_ticket) * temp_cost;
		last_ticket = temp_ticket;
		num_ticket[i] = temp_ticket;
		cost_ticket[i] = temp_cost;
		total_cost[i] = cal_total_cost;		
	}	
	cin >> cost_ticket[ticket_type];	
	
	int smallest_cost = -1, possible_ticket = -1, unpeak_answer = -1;
	
	//find the peak point of the ticket cost with enough ticket
	for(int i = 0; i < ticket_type ; i++)
	{
		if(num_ticket[i] >= ticket_max)
		{
			if((total_cost[i] < smallest_cost or possible_ticket == -1) or (total_cost[i] == smallest_cost and num_ticket[i] > possible_ticket))
			{
				smallest_cost = total_cost[i];
            	possible_ticket = num_ticket[i];
			}
		}
	}
	
	//if no peak is include, that means the target ticket number is too big
	if(smallest_cost < 0)
	{
		smallest_cost = (ticket_max - num_ticket[ticket_type-1]) * cost_ticket[ticket_type] + total_cost[ticket_type-1];
    	possible_ticket = ticket_max;
	}
	
	//calculate the local point
	for(int i = 0 ; i < ticket_type - 1 ; i++)
	{
		if(num_ticket[i] > ticket_max)
		{
			unpeak_answer = ticket_max * cost_ticket[i];
        	break;
		}
		else if(num_ticket[i] < ticket_max and num_ticket[i+1] > ticket_max)
		{
			unpeak_answer = total_cost[i] + (ticket_max-num_ticket[i]) * cost_ticket[i+1];
        	break;
		}
	}
	
	//compare the peak point and the local point
    if(unpeak_answer > 0 and unpeak_answer < smallest_cost)
    {
    	cout << ticket_max << "," << unpeak_answer;
	} 
	else
	{
		cout << possible_ticket << "," << smallest_cost;
	} 
	
	return 0;
}

