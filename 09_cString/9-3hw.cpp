#include <iostream>
using namespace std;

int main()
{
    //input
    int airportAmount = 0, airlineAmount = 0;
    cin >> airportAmount >> airlineAmount;
 
    int* airportPrice = new int[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        cin >> airportPrice[i];

    int* len = new int[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        len[i] = airlineAmount / airportAmount + 1;

    int* airportAirline = new int[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        airportAirline[i] = 0;

    int** airlinePrice = new int*[airportAmount + 1];
    int** airline = new int*[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
    {
        airlinePrice[i] = new int[airlineAmount / airportAmount + 1];
        airline[i] = new int[airlineAmount / airportAmount + 1];
    }
    for(int i = 1; i <= airlineAmount; i++)
    {
        int airport1 = 0, airport2 = 0, benefit = 0;
        cin >> airport1 >> airport2 >> benefit;

        airportAirline[airport1] += 1;
        airportAirline[airport2] += 1;

        if(len[airport1] <= airportAirline[airport1] + 1)
        {
            len[airport1] *= 2;

            int* temp1 = new int[len[airport1]];
            for(int i = 1; i <= airportAirline[airport1]; i ++)
                temp1[i] = airline[airport1][i];
            delete [] airline[airport1];
            airline[airport1] = temp1;

            int* temp2 = new int[len[airport1]];
            for(int i = 1; i <= airportAirline[airport1]; i ++)
                temp2[i] = airlinePrice[airport1][i];
            delete [] airlinePrice[airport1];
            airlinePrice[airport1] = temp2;
        }

        if(len[airport2] <= airportAirline[airport2] + 1)
        {
            len[airport2] *= 2;

            int* temp1 = new int[len[airport2]];
            for(int i = 1; i <= airportAirline[airport2]; i ++)
                temp1[i] = airline[airport2][i];
            delete [] airline[airport2];
            airline[airport2] = temp1;

            int* temp2 = new int[len[airport2]];
            for(int i = 1; i <= airportAirline[airport2]; i ++)
                temp2[i] = airlinePrice[airport2][i];
            delete [] airlinePrice[airport2];
            airlinePrice[airport2] = temp2;
        }

        airline[airport1][airportAirline[airport1]] = airport2;
        airline[airport2][airportAirline[airport2]] = airport1;

        airlinePrice[airport1][airportAirline[airport1]] = benefit;
        airlinePrice[airport2][airportAirline[airport2]] = benefit;
    }
    
    int* airportBuild = new int[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        airportBuild[i] = 1;

 /*   //
    cout << "airportPrice: ";
    for(int i = 1; i <= airportAmount; i++)
        cout << airportPrice[i] << " ";

    cout << endl << "airline: " << endl;
    for(int i = 1; i <= airlineAmount; i++)
    {
        for(int j = 1; j <= airportAirline[i]; j ++)
            cout << airline[i][j] << " ";
        cout << endl;
    }

    cout << "airlineP:" << endl;
    for(int i = 1; i <= airlineAmount; i++)
    {
        for(int j = 1; j <= airportAirline[i]; j ++)
            cout << airlinePrice[i][j] << " ";
        cout << endl;
    }

    cout << "Build:" << endl;
    for(int i = 1; i <= airportAmount; i++)
        cout << airportBuild[i] << " ";
    
    cout << endl << "airportairline:" << endl;
    for(int i = 1; i <= airportAmount; i++)
        cout << airportAirline[i] << " ";*/

    //data analysis
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
                for (int j = 1; j <= airportAirline[i]; j++)
                    profit -= airlinePrice[i][j];
            }
            //cout << "profit:" << profit << endl;
            if(profit >= maxProfit)
            {
                maxProfit = profit;
                airportToDam = i;
            }
            //cout << "maxp:" << maxProfit << endl;
            //cout << "airportDam:" << airportToDam << endl;
        }
        if (maxProfit == 0)
            break;

        for(int i = 1; i <= airportAmount; i++)
        {
            if(i == airportToDam)
            {
                for(int j = 1; j <= airportAirline[i]; j++)
                    airlinePrice[i][j] = 0;
            }
            else
            {
                for(int j = 1; j <= airportAirline[i]; j++)
                {
                    if(airline[i][j] == airportToDam)
                        airlinePrice[i][j] = 0;
                }
            }
        }
        //cout << airportToDam << endl;
        
        airportBuild[airportToDam] = 0;
        airportPrice[airportToDam] = 0;
    }

    int amounts = 0;
    for (int i = 1; i <= airportAmount; i++)
    {
        if(airportBuild[i] == 1)
            amounts++;
    }

    for (int i = 1, temp = 0; i <= airportAmount; i++)
    {
        if(airportBuild[i] == 1)
        {
            cout << i;
            temp++;
            if(temp != amounts)
                cout << ",";
        }
    }

    int totalProfit = 0;
    for(int i = 1; i <= airportAmount; i++)
    {
        for(int j = 1; j <= airportAirline[i]; j++)
            totalProfit += airlinePrice[i][j];
    }
    totalProfit = totalProfit / 2;
    for (int i = 1; i <= airportAmount; i++)
        totalProfit -= airportPrice[i];

    cout << ";" << totalProfit;
    
    return 0;
}