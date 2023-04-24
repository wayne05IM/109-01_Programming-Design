#include <iostream>
using namespace std;

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

    //operation
    int end = 0;
    int startQ1 = quantPUR1;
    for(int j = 1; j <= buyerNum; j++)
    {
        if(j == 1)
            cout << 1;
        else
            cout << "," << end + 1;
        
        float tempQuant0 = 0;
        for(int i = 1; i <= totalT; i++)
        {
            if(startQ1 - quantDecreasePUR > quantPURMin)
                startQ1 -= quantDecreasePUR;
            else
                startQ1 = quantPURMin;
            tempQuant0 += static_cast<float>(quantPU) * static_cast<float>(startQ1) / static_cast<float>(100);
            if(tempQuant0 >= static_cast<float>(buyer[j]))
            {
                end += i;
                break;
            }
        }
    }
    return 0;
}