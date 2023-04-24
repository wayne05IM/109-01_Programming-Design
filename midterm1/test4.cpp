#include <iostream>
using namespace std;

int main()
{
    int horDis = 0, vertDis = 0, range = 0, staNum = 0, railNum = 0;
    cin >> horDis >> vertDis >> range >> staNum >> railNum;
    
    const int MAX_LEN = 101;
    int pop[MAX_LEN][MAX_LEN] = {0};
    for(int i = 0; i <= horDis; i++)
        for (int j = 0; j <= vertDis; j++)
            cin >> pop[i][j];
    int popAvail[MAX_LEN][MAX_LEN] = {0};
    for(int i = 0; i <= horDis; i++)
        for (int j = 0; j <= vertDis; j++)
            popAvail[i][j] = 1;

    const int MAX_STANUM = 21;
    int stationX[MAX_STANUM] = {0};
    int stationY[MAX_STANUM] = {0};
    for(int i = 1; i <= staNum; i++)
        cin >> stationX[i] >> stationY[i];

    const int MAX_RAILNUM = 101;
    int station1[MAX_RAILNUM] = {0};
    int station2[MAX_RAILNUM] = {0};
    for(int i = 1; i <= railNum; i++)
        cin >> station1[i] >> station2[i];

    int staProfitPop = 0;
    for(int i = 1; i <= staNum; i++)
    {
        for(int j = stationY[i] - range; j <= stationY[i] + range; j++)
        {
            if((j >= 0) and (j <= vertDis))
            {
                for(int k = stationX[i] - range; k <= stationX[i] + range; k++)
                {
                    if((k >= 0) and (k <= horDis))
                    {
                        if(popAvail[k][j] == 1)
                            staProfitPop += pop[k][j];
                        popAvail[k][j] = 0;
                    }
                }
            }
        }       
    }

    int profitPop = 0;
    for(int i = 1; i <= railNum; i++)
    {
        if(stationX[station1[i]] == stationX[station2[i]])
        {
            if(stationY[station1[i]] > stationY[station2[i]])
            {
                for(int j = stationY[station1[i]]; j >= stationY[station2[i]]; j--)
                {
                    profitPop += pop[stationX[station1[i]]][j];
                    pop[stationX[station1[i]]][j] = 0;
                }
            }
            else if(stationY[station1[i]] < stationY[station2[i]])
            {
                for(int j = stationY[station2[i]]; j >= stationY[station1[i]]; j--)
                {
                    profitPop += pop[stationX[station1[i]]][j];
                    pop[stationX[station1[i]]][j] = 0;
                }
            }
        }
        else if(stationY[station1[i]] == stationY[station2[i]])
        {
            if(stationX[station1[i]] > stationX[station2[i]])
            {
                for(int j = stationX[station1[i]]; j >= stationX[station2[i]]; j--)
                {
                    profitPop += pop[j][stationY[station1[i]]];
                    pop[j][stationY[station1[i]]] = 0;
                }
            }
            else if(stationX[station1[i]] < stationX[station2[i]])
            {
                for(int j = stationX[station2[i]]; j >= stationX[station1[i]]; j--)
                {
                    profitPop += pop[j][stationY[station1[i]]];
                    pop[j][stationY[station1[i]]] = 0;
                }
            }
        }
    }

    cout << staProfitPop << "," <<profitPop;

    return 0;
}