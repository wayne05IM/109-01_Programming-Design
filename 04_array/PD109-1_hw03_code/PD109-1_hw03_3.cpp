#include<iostream>
using namespace std;

int main()
{
	// TA Yoyo37564 here
	// if you are to revise this code for problem 4-1, that means that you didn't know how to deal with this problem.
	// my advise to you is that NOT to use this code, use TA Karseee's code instead,
	// unless you want to challenge yourself, then good job!
	// the algorithm used in this code is thrivial but complicated, unsuitable for you to revise.
	// nevertheless, if you have any problem with this code, feel free to ask me.
	
	int ticket_type1 = 0, ticket_max1 = 0, ticket_type2 = 0, ticket_max2 = 0, total_budget = 0, mode = 0, temp_ticket = 0, temp_cost = 0, cal_total_cost = 0, last_ticket = 0;
	
	cin >> ticket_type1 >> ticket_type2 >> ticket_max1 >> ticket_max2 >> total_budget >> mode;
	
	int num_ticket1[ticket_type1] = {0}, cost_ticket1[ticket_type1] = {0}, total_cost1[ticket_type1] = {0};
	int num_ticket2[ticket_type2] = {0}, cost_ticket2[ticket_type2] = {0}, total_cost2[ticket_type2] = {0}; 
	
	// save all data in six array, the last one is calculated total cost
	for(int i = 0; i < ticket_type1 ; i++)
	{
		cin >> temp_ticket >> temp_cost;
		cal_total_cost += (temp_ticket - last_ticket) * temp_cost;
		last_ticket = temp_ticket;
		num_ticket1[i] = temp_ticket;
		cost_ticket1[i] = temp_cost;
		total_cost1[i] = cal_total_cost;		
	}
	cin >> cost_ticket1[ticket_type1];
	
	last_ticket = 0;
	cal_total_cost = 0; 
	
	// do it for both ticket
	for(int i = 0; i < ticket_type2 ; i++)
	{
		cin >> temp_ticket >> temp_cost;
		cal_total_cost += (temp_ticket - last_ticket) * temp_cost;
		last_ticket = temp_ticket;
		num_ticket2[i] = temp_ticket;
		cost_ticket2[i] = temp_cost;
		total_cost2[i] = cal_total_cost;		
	}
	cin >> cost_ticket2[ticket_type2];
		
	// here we go
	int ans_ticket1 = 0, ans_ticket2 = 0, now_budget = total_budget, leftover = 0, max_ticket_budget = 0;
	
	if(mode == 1)
	{
		// the algorithm here is simple, buy all ticket of a kind, then buy the other if
		// 1. the number of the ticket is the same as the number the the ticket wanted
		// 2. out of budget
		
		// test how many ticket 1 can we buy
		leftover = 0;				
		max_ticket_budget = -1;
		
		
		for(int i = 0; i < ticket_type1 ; i++)
		{
			if(num_ticket1[i] > ticket_max1)
			{
				if(i == 0)
				{
					max_ticket_budget = ticket_max1 * cost_ticket1[i];
					break;
				}
				else
				{
					max_ticket_budget = (ticket_max1 - num_ticket1[i-1]) * cost_ticket1[i] + total_cost1[i-1];
					break;
				}
			}
		}
		
		// if too many budget
		if(max_ticket_budget == -1)
		{
			max_ticket_budget = (ticket_max1 - num_ticket1[ticket_type1-1]) * cost_ticket1[ticket_type1] + total_cost1[ticket_type1-1];
		}
		
		// try to buy that many ticket 1
		if(max_ticket_budget <= now_budget)
		{
			ans_ticket1 = ticket_max1;
			now_budget -= max_ticket_budget;		
		}
		else
		{
			// if not enough budget, than buy some of ticket 1
			for(int i = 0; i < ticket_type1 ; i++)
		    {
		    	if(now_budget < total_cost1[i])
		    	{
		    		if(i == 0)
		    		{
						leftover = now_budget;
						ans_ticket1 = leftover / cost_ticket1[i];
						now_budget = now_budget - ans_ticket1 * cost_ticket1[i];	    			
					}	                
		            else
		            {
						leftover = now_budget - total_cost1[i-1];
		            	ans_ticket1 = leftover / cost_ticket1[i];
						now_budget = now_budget - total_cost1[i-1] - ans_ticket1 * cost_ticket1[i];
						ans_ticket1 += num_ticket1[i-1];
					}	                
		            break;
				}
			}
			
			// if not enough budget, than buy some of ticket 1
			if(now_budget > total_cost1[ticket_type1-1]) 
			{
				leftover = now_budget - total_cost1[ticket_type1-1];
				ans_ticket1 = leftover / cost_ticket1[ticket_type1];
				now_budget = now_budget - total_cost1[ticket_type1-1] - ans_ticket1 * cost_ticket1[ticket_type1];
				ans_ticket1 += num_ticket1[ticket_type1-1];
			}
		}
		
		// test how many ticket 2 can we buy
		leftover = 0;				
		max_ticket_budget = -1;
		
		for(int i = 0; i < ticket_type2 ; i++)
		{
			if(num_ticket2[i] > ticket_max2)
			{
				if(i == 0)
				{
					max_ticket_budget = ticket_max2 * cost_ticket2[i];
					break;
				}
				else
				{
					max_ticket_budget = (ticket_max2 - num_ticket2[i-1]) * cost_ticket2[i] + total_cost2[i-1];
					break;
				}
			}
		}
		
		// if too many budget
		if(max_ticket_budget == -1)
		{
			max_ticket_budget = (ticket_max2 - num_ticket2[ticket_type2-1]) * cost_ticket2[ticket_type2] + total_cost2[ticket_type2-1];
		}
		
		// try to buy that many ticket 2
		if(max_ticket_budget <= now_budget)
		{
			ans_ticket2 = ticket_max2;
			now_budget -= max_ticket_budget;
		}
		else
		{
			// if not enough budget, than buy some of ticket 2
			for(int i = 0; i < ticket_type2 ; i++)
		    {
		    	if(now_budget < total_cost2[i])
		    	{
		    		if(i == 0)
		    		{
						leftover = now_budget;
						ans_ticket2 = leftover / cost_ticket2[i];
						now_budget = now_budget - ans_ticket2 * cost_ticket2[i];	    			
					}	                
		            else
		            {
						leftover = now_budget - total_cost2[i-1];
		            	ans_ticket2 = leftover / cost_ticket2[i];
						now_budget = now_budget - total_cost2[i-1] - ans_ticket2 * cost_ticket2[i];
						ans_ticket2 += num_ticket2[i-1];
					}	                
		            break;
				}
			}
			
			// if not enough budget, than buy some of ticket 2
			if(now_budget > total_cost2[ticket_type2-1])
			{
				leftover = now_budget - total_cost2[ticket_type2-1];
				ans_ticket2 = leftover / cost_ticket2[ticket_type2];
				now_budget = now_budget - total_cost2[ticket_type2-1] - ans_ticket2 * cost_ticket2[ticket_type2];
				ans_ticket2 += num_ticket2[ticket_type2-1];
			}		
		}		
	}
	else if(mode == 2)
	{
		// test how many ticket 2 can we buy
		leftover = 0;				
		max_ticket_budget = -1;
		
		for(int i = 0; i < ticket_type2 ; i++)
		{
			if(num_ticket2[i] > ticket_max2)
			{
				if(i == 0)
				{
					max_ticket_budget = ticket_max2 * cost_ticket2[i];
					break;
				}
				else
				{
					max_ticket_budget = (ticket_max2 - num_ticket2[i-1]) * cost_ticket2[i] + total_cost2[i-1];
					break;
				}
			}
		}
		
		// if too many budget
		if(max_ticket_budget == -1)
		{
			max_ticket_budget = (ticket_max2 - num_ticket2[ticket_type2-1]) * cost_ticket2[ticket_type2] + total_cost2[ticket_type2-1];
		}
		
		// try to buy that many ticket 2
		if(max_ticket_budget <= now_budget)
		{
			ans_ticket2 = ticket_max2;
			now_budget -= max_ticket_budget;
		}
		else
		{
			// if not enough budget, than buy some of ticket 2
			for(int i = 0; i < ticket_type2 ; i++)
		    {
		    	if(now_budget < total_cost2[i])
		    	{
		    		if(i == 0)
		    		{
		    			leftover = now_budget;
						ans_ticket2 = leftover / cost_ticket2[i];
						now_budget = now_budget - ans_ticket2 * cost_ticket2[i];	    			
					}	                
		            else
		            {
		            	leftover = now_budget - total_cost2[i-1];
		            	ans_ticket2 = leftover / cost_ticket2[i];
						now_budget = now_budget - total_cost2[i-1] - ans_ticket2 * cost_ticket2[i];
						ans_ticket2 += num_ticket2[i-1];
					}	                
		            break;
				}
			}
			
			// if not enough budget, than buy some of ticket 2
			if(now_budget > total_cost2[ticket_type2-1])
			{
				leftover = now_budget - total_cost2[ticket_type2-1];
				ans_ticket2 = leftover / cost_ticket2[ticket_type2];
				now_budget = now_budget - total_cost2[ticket_type2-1] - ans_ticket2 * cost_ticket2[ticket_type2];
				ans_ticket2 += num_ticket2[ticket_type2-1];
			}		
		}
				
		// test how many ticket 1 can we buy
		leftover = 0;				
		max_ticket_budget = -1;
		for(int i = 0; i < ticket_type1 ; i++)
		{
			if(num_ticket1[i] > ticket_max1)
			{
				if(i == 0)
				{
					max_ticket_budget = ticket_max1 * cost_ticket1[i];
					break;
				}
				else
				{
					max_ticket_budget = (ticket_max1 - num_ticket1[i-1]) * cost_ticket1[i] + total_cost1[i-1];
					break;
				}
			}
		}
		
		// if too many budget
		if(max_ticket_budget == -1)
		{
			max_ticket_budget = (ticket_max1 - num_ticket1[ticket_type1-1]) * cost_ticket1[ticket_type1] + total_cost1[ticket_type1-1];
		}
		
		// try to buy that many ticket 1
		if(max_ticket_budget <= now_budget)
		{
			ans_ticket1 = ticket_max1;
			now_budget -= max_ticket_budget;
		}
		else
		{
			// if not enough budget, than buy some of ticket 2
			for(int i = 0; i < ticket_type1 ; i++)
		    {
		    	if(now_budget < total_cost1[i])
		    	{
		    		if(i == 0)
		    		{
						leftover = now_budget;
						ans_ticket1 = leftover / cost_ticket1[i];
						now_budget = now_budget - ans_ticket1 * cost_ticket1[i];	    			
					}	                
		            else
		            {
						leftover = now_budget - total_cost1[i-1];
		            	ans_ticket1 = leftover / cost_ticket1[i];
						now_budget = now_budget - total_cost1[i-1] - ans_ticket1 * cost_ticket1[i];
						ans_ticket1 += num_ticket1[i-1];
					}	                
		            break;
				}
			}
			
			// if not enough budget, than buy some of ticket 2
			if(now_budget > total_cost1[ticket_type1-1])
			{
				leftover = now_budget - total_cost1[ticket_type1-1];
				ans_ticket1 = leftover / cost_ticket1[ticket_type1];
				now_budget = now_budget - total_cost1[ticket_type1-1] - ans_ticket1 * cost_ticket1[ticket_type1];
				ans_ticket1 += num_ticket1[ticket_type1-1];
			}
		}
	}
	else if(mode == 0)
	{
		// the algorithm here is a quite bothering
		// at any moment, buy the ticket of the cheaper one, until
		// 1. the number of the ticket is the same as the number the the ticket wanted
		// 2. out of budget
		// 3. the price of the ticket is not cheaper anymore
		// this guarantee to get the near-optimal solution of this problem
		
		int now_cost1 = -1, now_cost2 = -1, segment_ticket1 = 0, segment_ticket2 = 0, ticket_buy = 0;
		bool buy_any_ticket = false;
		
		// repeated do this algorithm
		// in this algorithm, we buy ticket with segment instead of one by one to increase calculate speed
		while(true)
		{
			now_cost1 = -1;
			now_cost2 = -1;
			segment_ticket1 = 0;
			segment_ticket2 = 0;
			buy_any_ticket = false;					
			
			// test how many ticket 1 can we buy
			for(int i = 0; i < ticket_type1 ; i++)
			{
				if(ans_ticket1 < num_ticket1[i])
				{
					now_cost1 = cost_ticket1[i] * 1;
					if(num_ticket1[i] < ticket_max1)
					{
						segment_ticket1 = num_ticket1[i] - ans_ticket1;
					}
					else
					{
						segment_ticket1 = ticket_max1 - ans_ticket1;
					}
					break;				
				}
			}
			
			// if no more we want to buy
			if(ticket_max1 == ans_ticket1)
			{
				now_cost1 = 101;
			}
			// if no more segment ahead
			else if(now_cost1 == -1)
			{
				now_cost1 = cost_ticket1[ticket_type1];
				segment_ticket1 = ticket_max1 - ans_ticket1;
			}
			
			// test how many ticket 2 can we buy
			for(int i = 0; i < ticket_type2 ; i++)
			{
				if(ans_ticket2 < num_ticket2[i])
				{
					now_cost2 = cost_ticket2[i] * 1;
					if(num_ticket2[i] < ticket_max2)
					{
						segment_ticket2 = num_ticket2[i] - ans_ticket2;
					}
					else
					{
						segment_ticket2 = ticket_max2 - ans_ticket2;
					}
					break;
				}
			}
			
			// if no more we want to buy
			if(ticket_max2 == ans_ticket2)
			{
				now_cost2 = 101;
			}
			// if no more segment ahead
			else if(now_cost2 == -1)
			{
				now_cost2 = cost_ticket2[ticket_type2];
				segment_ticket2 = ticket_max2 - ans_ticket2;
			}
			
			// if ticket 1 can buy and is cheaper
			if(now_cost1 <= now_cost2 and segment_ticket1 > 0)
			{					
	            //if we can buy all ticket 1 of this segment
	            if(now_budget > segment_ticket1 * now_cost1)
	            {
					now_budget -= segment_ticket1 * now_cost1;
	                ans_ticket1 += segment_ticket1;
	                buy_any_ticket = true;
				}	                
	            else  //if we can buy some ticket 1 of this segment
	            {
					ticket_buy = now_budget / now_cost1;
					if(ticket_buy > 0)
	                {
						now_budget -= ticket_buy * now_cost1;
	                    ans_ticket1 += ticket_buy;
	                    buy_any_ticket = true;
					}	                   
				}	                
	    	}
		     
			// if ticket 2 can buy and is cheaper, or we do not buy ticket 1
			if((now_cost1 > now_cost2 or (not buy_any_ticket)) and segment_ticket2 > 0)
	        {
				//if we can buy all ticket 2 of this segment
	            if(now_budget > segment_ticket2 * now_cost2)
	            {
					now_budget -= segment_ticket2 * now_cost2;
	                ans_ticket2 += segment_ticket2;
	                buy_any_ticket = true;
				}	                
	            else  //if we can buy some ticket 2 of this segment
	            {
					ticket_buy = now_budget / now_cost2;
	                if(ticket_buy > 0)
	                {
						now_budget -= ticket_buy * now_cost2;
	                    ans_ticket2 += ticket_buy;
	                    buy_any_ticket = true;
					}	                    
				}
	    	}
	    	
	        // break if no more ticket can buy
	        if(not buy_any_ticket)
	        {
				break;
			}
		}	
		int temp_ticket1 = ans_ticket1, temp_ticket2 = ans_ticket2;
	
		// however, the algorithm do not end here
		// to obtain the optimal solution, we have to do some local search, with a view to optimize the product of the ticket
		while(true)
		{
			int local_cost = 0;
			
			// test if we can buy one more ticket 2 and buy one less ticket 1
			if(temp_ticket1 > temp_ticket2)
			{
				temp_ticket1 -= 1;
				temp_ticket2 += 1;
			}
			else if(temp_ticket1 < temp_ticket2)
			{
				temp_ticket1 += 1;
				temp_ticket2 -= 1;
			}
			else
			{
				break;
			}
			
			// if one of which is too many, break
			if(temp_ticket1 > ticket_max1 or temp_ticket2 > ticket_max2)
			{
				break;
			}
							
			// calculate the money of ticket 1
			for(int i = 0; i < ticket_type1 ; i++)
			{
				if(temp_ticket1 < num_ticket1[i])
				{
					if(i == 0)
					{
						local_cost += temp_ticket1 * cost_ticket1[i];
					}
					else
					{
						local_cost += (temp_ticket1 - num_ticket1[i-1]) * cost_ticket1[i] + total_cost1[i-1];
					}					
					break;				
				}
			}
			if(temp_ticket1 >= num_ticket1[ticket_type1-1])
			{
				local_cost += (temp_ticket1 - num_ticket1[ticket_type1-1]) * cost_ticket1[ticket_type1] + total_cost1[ticket_type1-1];
			}
			
			// calculate the money of ticket 1
			for(int i = 0; i < ticket_type2 ; i++)
			{
				if(temp_ticket2 < num_ticket2[i])
				{
					if(i == 0)
					{
						local_cost += temp_ticket2 * cost_ticket2[i];
					}
					else
					{
						local_cost += (temp_ticket2 - num_ticket2[i-1]) * cost_ticket2[i] + total_cost2[i-1];
					}					
					break;				
				}
			}
			if(temp_ticket2 >= num_ticket2[ticket_type2-1])
			{
				local_cost += (temp_ticket2 - num_ticket2[ticket_type2-1]) * cost_ticket2[ticket_type2] + total_cost2[ticket_type2-1];
			}
			
			// if this new answer performs better, save it and do it again, otherwise, recover it and break
			if(local_cost <= total_budget and ((temp_ticket1 * temp_ticket2 > ans_ticket1 * ans_ticket2) or (temp_ticket1 * temp_ticket2 == ans_ticket1 * ans_ticket2 and temp_ticket1 > ans_ticket1)))
			{
				ans_ticket1 = temp_ticket1;
				ans_ticket2 = temp_ticket2;
				now_budget = total_budget - local_cost;
			}
			else
			{
				break;
			}
		}
	}
		
	cout << ans_ticket1 << "," << ans_ticket2 << "," << total_budget - now_budget;
	   	
	return 0;
}

