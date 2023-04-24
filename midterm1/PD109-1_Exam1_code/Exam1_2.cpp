#include <iostream>
using namespace std;

int main()
{
	int num_city = 0, cover_radius = 0;
	
	cin >> num_city >> cover_radius;
	int* people = new int[num_city];
	
	for(int i = 0 ; i < num_city ; i++)
	{
		cin >> people[i];
	}
	
	int cover_people = 0, max_cover = -1, lower_bound = 0, upper_bound = 0;
	for(int i = 0 ; i < num_city ; i++)
	{
		cover_people = 0;
		
		lower_bound = i - cover_radius;
		if(lower_bound < 0)
		{
			lower_bound = 0;
		}
		
		upper_bound = i + cover_radius + 1;
		if(upper_bound > num_city)
		{
			upper_bound = num_city;
		}
		
		for(int j = lower_bound ; j < upper_bound ; j++)
		{
			cover_people += people[j];
		}
		
		if(cover_people > max_cover)
		{
			max_cover = cover_people;
		}		
	}
	cout << max_cover;
	
	return 0;
}
