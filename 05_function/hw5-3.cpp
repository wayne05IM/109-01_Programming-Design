#include <iostream>
using namespace std;
 
const int AIRPORT_MAX_AMOUNT = 101;
 
int main()
{
    //input
    int airportAmount = 0;
    cin >> airportAmount;
 
    int airportPrice[AIRPORT_MAX_AMOUNT] = {0};
    for (int i = 1; i <= airportAmount; i++)
        cin >> airportPrice[i];
    
    int airlinePrice[AIRPORT_MAX_AMOUNT][AIRPORT_MAX_AMOUNT] = {0};
    for(int i = 1, len = airportAmount - 1, starter = 1; i <= airportAmount; i++, len-- )
    {
        starter += 1;
        for(int j = starter; j < starter + len; j++)
            cin >> airlinePrice[i][j];
    }
 
    int airportBuild[AIRPORT_MAX_AMOUNT] = {0};
    for (int i = 1; i <= airportAmount; i++)
        airportBuild[i] = 1;
     
    //data analyze
    int airportToDam = 0;
    while(true)
    {
        int maxProfit = 0;
        for (int i = airportAmount; i > 0; i--)
        {
            int profit = 0;
            if(airportBuild[i] == 1)
            {
                profit += airportPrice[i];
                for (int j = 1; j < i; j++)
                    profit -= airlinePrice[j][i];
                for (int j = i + 1; j <= airportAmount; j++)
                    profit -= airlinePrice[i][j];
            }
            if(profit >= maxProfit)
            {
                maxProfit = profit;
                airportToDam = i;
            }
        }
        if (maxProfit == 0)
            break;

        for (int j = 1; j < airportToDam; j++)
            airlinePrice[j][airportToDam] = 0;
        for (int j = airportToDam + 1; j <= airportAmount; j++)
            airlinePrice[airportToDam][j] = 0;
        
        airportBuild[airportToDam] = 0;
        airportPrice[airportToDam] = 0;
    }
 
    for (int i = 1; i <= airportAmount; i++)
    {
        cout << airportBuild[i];
        if (i != airportAmount)
            cout << ",";
    }


    int totalProfit = 0;
    for(int i = 1, len = airportAmount - 1, starter = 1; i <= airportAmount; i++, len-- )
    {
        starter += 1;
        for(int j = starter; j < starter + len; j++)
            totalProfit += airlinePrice[i][j];
    }
    for (int i = 1; i <= airportAmount; i++)
        totalProfit -= airportPrice[i];

    cout << ";" << totalProfit; 
         
    return 0;
}