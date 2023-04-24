#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N = 0, m = 0;
	cin >> N >> m;
	
	const int MAX_PERIOD_CNT = 1000; 
	int real[MAX_PERIOD_CNT] = {0};
	for(int i = 0; i < m; i++)
		cin >> real[i];
	
	const int MAX_N = 10;
	float MAE[MAX_N] = {0};
	for(int n = 2; n <= N; n++)
	{
		float SAE = 0;
		for(int i = n; i < m; i++)
		{
			int sum = 0;
			for(int j = 1; j <= n; j++) 
				sum += real[i - j];
			float fcst = static_cast<float>(sum) / n;
			SAE += abs(fcst - real[i]);
		}
		MAE[n - 1] = static_cast<float>(SAE) / (m - n);
	}
	
	int bestN = 0;
	float bestMAE = 100000000;
	for(int i = 1; i < N; i++)
	{
		if(MAE[i] < bestMAE)
		{
			bestN = i + 1;
			bestMAE = MAE[i];
		}
	}
	
	bestMAE = static_cast<int>(bestMAE * 100) / static_cast<float>(100);
	cout << bestN << " " << bestMAE;
			
	return 0;
}
