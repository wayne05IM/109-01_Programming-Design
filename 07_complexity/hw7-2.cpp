#include <iostream>
using namespace std;

int main()
{
    //input
    int quantPU = 0, quantDecreasePUR = 0, maintenanceT = 0, quantPUR1 = 0, totalT = 0, quantPURMin = 0;
    cin >> quantPU >> quantDecreasePUR >> maintenanceT >> quantPUR1 >> totalT >> quantPURMin;

    //operation
    int quant[169] = {0};

    //no maintenance
    int startQ0 = quantPUR1;
    for(int i = 1; i <= totalT; i++)
    {
        if(startQ0 - quantDecreasePUR > quantPURMin)
            startQ0 -= quantDecreasePUR;
        else
            startQ0 = quantPURMin;
        quant[0] += quantPU * startQ0 / 100; 
    }

    //all situation
    for (int j = 1; j < totalT - maintenanceT ; j++)
    {
        int startQ = quantPUR1;
        for(int i = 1; i <= totalT; i++)
        {
            if(startQ - quantDecreasePUR > quantPURMin)
                startQ -= quantDecreasePUR;
            else
                startQ = quantPURMin;

            if(i == j)
            {
                startQ = 100;
                i += maintenanceT;
            }
            
            quant[j] += quantPU * startQ / 100;
        }
    }

    //compare the values
    int quantMax = -1, time = 0;
    for(int i = 0; i <= totalT; i++)
    {
        if(quant[i] > quantMax)
        {
            quantMax = quant[i];
            time = i;
        }
    }

    cout << time << "," << quantMax;

    return 0;
}