#include <iostream>
using namespace std;

int delayTime(int time, int deadline);

int main()
{
    //input
    int quantPU = 0, quantDecreasePUR = 0, maintenanceT = 0, quantPUR1 = 0, totalT = 0, quantPURMin = 0;
    cin >> quantPU >> quantDecreasePUR >> maintenanceT >> quantPUR1 >> totalT >> quantPURMin;
    int buyerNum = 0;
    cin >> buyerNum;

    const int MAX_BUYERS = 21;
    int buyer[MAX_BUYERS] = {0};
    for(int i = 1; i <= buyerNum; i++)
        cin >> buyer[i];

    int Deadline[MAX_BUYERS] = {0};
    for(int i = 1; i <= buyerNum; i++)
        cin >> Deadline[i];

    //sorting
    bool again = true;
    while(again)
    {
        again = false;
        for(int i = 1; i < buyerNum; i++)
        {
            if(Deadline[i] > Deadline[i + 1])
            {
                int temp1 = Deadline[i];
                Deadline[i] = Deadline[i + 1];
                Deadline[i + 1] = temp1;

                int temp2 = buyer[i];
                buyer[i] = buyer[i + 1];
                buyer[i + 1] = temp2;
                again = true;
            }
            else if(Deadline[i] == Deadline[i + 1])
            {
                if((buyer[i] > buyer[i + 1]))
                {
                    int temp1 = Deadline[i];
                    Deadline[i] = Deadline[i + 1];
                    Deadline[i + 1] = temp1;

                    int temp2 = buyer[i];
                    buyer[i] = buyer[i + 1];
                    buyer[i + 1] = temp2;
                    again = true;
                }
            }
        }
    }

    //operation
    int finaltotaldelay = 1000000, finalmaintenance = 0;
    for(int k = 0; k <= buyerNum; k++)
    {
        int totaldelay = 0, time = 0, maintenancepoint = 0;
        int startQ1 = quantPUR1;
        for(int j = 1; j <= buyerNum; j++)
        {
            if(j == k)
            {
                maintenancepoint = time + 1;
                time += maintenanceT;
                startQ1 = 100 + quantDecreasePUR;
            }

            float tempQuant0 = 0;
            for(int i = time + 1; i <= totalT; i++)
            {
                if(startQ1 - quantDecreasePUR > quantPURMin)
                    startQ1 -= quantDecreasePUR;
                else
                    startQ1 = quantPURMin;
                tempQuant0 += static_cast<float>(quantPU) * static_cast<float>(startQ1) / static_cast<float>(100);
                if(tempQuant0 >= static_cast<float>(buyer[j]))
                {
                    time = i;
                    break;
                }
            }
            totaldelay += delayTime(time, Deadline[j]);
        }
        
        if(totaldelay < finaltotaldelay)
        {
            finaltotaldelay = totaldelay;
            finalmaintenance = maintenancepoint;
        }
    }

    if(finaltotaldelay == 1000000)
        finaltotaldelay = 0;
    
    cout << finalmaintenance << "," << finaltotaldelay;

    return 0;
} 

int delayTime(int time, int deadline)
{
    if((deadline - time) >= 0)
        return 0;
    else
        return (time - deadline);
}