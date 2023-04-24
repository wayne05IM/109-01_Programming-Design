#include <iostream>
#include <cmath>
using namespace std;

const int MAX_LEN = 101;
const int MAX_STANUM = 21;
const int MAX_RAILNUM = 101;

int marginalBenefit(int pop[][MAX_LEN], int stationX[], int stationY[], int station1[], int station2[], int i);

int main()
{
    // input values
    int horDis = 0, vertDis = 0, staNum = 0, maxLen = 0;
    cin >> horDis >> vertDis >> staNum >> maxLen;
    
    int pop[MAX_LEN][MAX_LEN] = {0};
    for(int i = 0; i <= horDis; i++)
        for (int j = 0; j <= vertDis; j++)
            cin >> pop[i][j];

    int stationX[MAX_STANUM] = {0};
    int stationY[MAX_STANUM] = {0};
    for(int i = 1; i <= staNum; i++)
        cin >> stationX[i] >> stationY[i];

    int station1[MAX_RAILNUM] = {0};
    int station2[MAX_RAILNUM] = {0};
    int railLen[MAX_RAILNUM] = {0};
    int k = 0;
    for(int i = 1; i <= staNum; i++)
    {
        for(int j = i + 1; j <= staNum; j++)
        {
            if(stationX[i] == stationX[j])
            {
                k++;
                station1[k] = i;
                station2[k] = j;
                railLen[k] = abs(stationY[i] - stationY[j]);
            }
            else if(stationY[i] == stationY[j])
            {
                k++;
                station1[k] = i;
                station2[k] = j;
                railLen[k] = abs(stationX[i] - stationX[j]);
            }
        }
    }

    //operation
    int profitPop = 0;
    int railCandidate[MAX_RAILNUM] = {0}, x = 0; 
    bool again = true;
    while (again)
    {
        int bestMarBene = 0, railChoose = 0;
        float bestPorportion = 0;
        int b = 0;
        for (int i = 1; i <= k; i++)
        {
            if((railLen[i] > maxLen) or (station1[i] == 0))
            {
                station1[i] = 0;
                station2[i] = 0;
            }
            else
            {
                b = marginalBenefit(pop, stationX, stationY, station1, station2, i);
                if((static_cast<float>(b) / static_cast<float>(railLen[i])) > bestPorportion)
                {
                    bestPorportion = (static_cast<float>(b) / static_cast<float>(railLen[i]));
                    bestMarBene = b;
                    railChoose = i;
                }
                else if((static_cast<float>(b) / static_cast<float>(railLen[i])) == bestPorportion)
                {
                    if(railLen[i] < railLen[railChoose])
                    {
                        bestPorportion = (static_cast<float>(b) / static_cast<float>(railLen[i]));
                        bestMarBene = b;
                        railChoose = i;
                    }
                    else if(railLen[i] == railLen[railChoose])
                    {
                        if((station1[i] + station2[i]) < (station1[railChoose] + station2[railChoose]))
                        {
                            bestPorportion = (static_cast<float>(b) / static_cast<float>(railLen[i]));
                            bestMarBene = b;
                            railChoose = i;
                        }
                        else if((station1[i] + station2[i]) == (station1[railChoose] + station2[railChoose]))
                        {
                            int temp1 = 0, temp2 = 0;
                            if(station1[i] > station2[i])
                                temp1 = station2[i];
                            else if(station1[i] < station2[i])
                                temp1 = station1[i];
                        
                            if(station1[railChoose] > station2[railChoose])
                                temp2 = station2[railChoose];
                            else if(station1[railChoose] < station2[railChoose])
                                temp2 = station1[railChoose];

                            if(temp1 < temp2)
                            {
                                bestPorportion = (static_cast<float>(b) / static_cast<float>(railLen[i]));
                                bestMarBene = b;
                                railChoose = i;
                            }
                        }
                    }
                }
            }
        }

        if(bestMarBene == 0)
            break;
        else
        {
            maxLen -= railLen[railChoose];
            profitPop += bestMarBene;
            x++;
            railCandidate[x] = railChoose;

            int i = railChoose;
            if(stationX[station1[i]] == stationX[station2[i]])
            {
                if(stationY[station1[i]] > stationY[station2[i]])
                {
                    for(int k = stationY[station2[i]]; k <= stationY[station1[i]]; k++)
                        pop[stationX[station1[i]]][k] = 0;
                }
                else if(stationY[station1[i]] < stationY[station2[i]])
                {
                    for(int k = stationY[station1[i]]; k <= stationY[station2[i]]; k++)
                        pop[stationX[station1[i]]][k] = 0;
                }
            }
            else if(stationY[station1[i]] == stationY[station2[i]])
            {
                if(stationX[station1[i]] > stationX[station2[i]])
                {
                    for(int k = stationX[station2[i]]; k <= stationX[station1[i]]; k++)
                        pop[k][stationY[station1[i]]] = 0;
                }
                else if(stationX[station1[i]] < stationX[station2[i]])
                {
                    for(int k = stationX[station1[i]]; k <= stationX[station2[i]]; k++)
                        pop[k][stationY[station1[i]]] = 0;
                }
            }
            station1[railChoose] = 0;
            station2[railChoose] = 0;
        }

        again = false;
        for (int i = 1; i <= k; i++)
        {
            if(station1[i] != 0)
                again = true;
        }
    }

    cout << profitPop << "," << maxLen;

    return 0;
}

int marginalBenefit(int pop[][MAX_LEN], int stationX[], int stationY[], int station1[], int station2[], int i)
{
    int marBene = 0;
    if(stationX[station1[i]] == stationX[station2[i]])
    {
        if(stationY[station1[i]] > stationY[station2[i]])
        {
            for(int k = stationY[station2[i]]; k <= stationY[station1[i]]; k++)
                marBene += pop[stationX[station1[i]]][k];
        }
        else if(stationY[station1[i]] < stationY[station2[i]])
        {
            for(int k = stationY[station1[i]]; k <= stationY[station2[i]]; k++)
                marBene += pop[stationX[station1[i]]][k];
        }
    }
    else if(stationY[station1[i]] == stationY[station2[i]])
    {
        if(stationX[station1[i]] > stationX[station2[i]])
        {
            for(int k = stationX[station2[i]]; k <= stationX[station1[i]]; k++)
                marBene += pop[k][stationY[station1[i]]];
        }
        else if(stationX[station1[i]] < stationX[station2[i]])
        {
            for(int k = stationX[station1[i]]; k <= stationX[station2[i]]; k++)
                marBene += pop[k][stationY[station1[i]]];
        }
    }
    
    return  marBene;
}