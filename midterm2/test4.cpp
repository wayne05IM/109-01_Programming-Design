#include<iostream>
using namespace std;

int main()
{
    // input
    int stationAmount = 0, transferMax = 0, start = 0, end = 0;
    cin >> stationAmount >> transferMax >> start >> end;

    int ticketPrice[20][20] = {0};
    for(int i = 1; i < stationAmount; i++)
    {
        for(int j = i + 1; j <= stationAmount; j++)
            cin >> ticketPrice[i][j];
    }

    // operation
    int minCost = 0;
    if(start > end)
    {
        int temp = start;
        start = end;
        end = start;
    }
    minCost = ticketPrice[start][end];

    if(transferMax != 0)
    {
        for(int i = 1; i <= transferMax; i++)
        {
            int cost = 0;
            for(int j = 1; j <= transferMax; j++)
            {
                if(j < start)
                {
                    cost += 
                }
            }
            if(cost < minCost)
                minCost = cost;
        }
    }

    cout << minCost;
    
    return 0;
}