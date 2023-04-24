#include<iostream>
using namespace std;

int main()
{
	bool the_first_input = true;
	int output = 0;
	float input = 0;
	while(cin)
	{
		cin >> input;
		if(input < 37)
		{
			output = input * 10 / 10;
			if(the_first_input)
			{
				cout << output;
				the_first_input = false;
			} 
			else
			{
				cout << "," << output;
			}
		}
		else
		{
			break;
		}
	}
	
	return 0;
}


