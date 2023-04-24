#include<iostream>
using namespace std;

int main()
{
	int length = 0, target = 0, temp_input = 0;
	
	cin >> length >> target;
	
	int list[length] = {0};
	
	//save all data into array, while set it to 0 under condition
	for(int i = 0; i < length ; i++)
	{
		cin >> temp_input;
		if(temp_input % target == 0 and temp_input > 0)
		{
			list[i] = 0;
		}
		else
		{
			list[i] = temp_input;
		}
	}
	
	//important thing is that remember to set the initial sum as the lower/upper bound of the sum
	int front_ptr = 0, back_ptr = 0, now_sum = 0, best_front_ptr = 0, best_back_ptr = 0, best_sum = -999999;
	
	//repeatedly set front pointer and back pointer to all numbers in the list
	//and check if the sum of any of it is the biggest
	for(int i = 0 ; i < length ; i++)
	{
		front_ptr = i;
        now_sum = 0;
        for(int j = i ; j < length ; j++)
        {
        	back_ptr = j;
            now_sum += list[back_ptr];
            if(now_sum > best_sum or (now_sum == best_sum and back_ptr - front_ptr > best_back_ptr - best_front_ptr) or (now_sum == best_sum and back_ptr - front_ptr == best_back_ptr - best_front_ptr and front_ptr > best_front_ptr))
            {
            	best_front_ptr = front_ptr;
                best_back_ptr = back_ptr;
                best_sum = now_sum;
			}          
		}         
	}
    cout << best_front_ptr+1 << "," << best_back_ptr+1 << "," << best_sum;  
	
	return 0;
}

