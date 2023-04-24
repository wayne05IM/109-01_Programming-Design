#include <iostream>
using namespace std;

const int MACHINE_MAX = 51;

int main()
{
    // input
    int numMachine = 0,numOrder = 0,maxFix = 0;
    cin >> numMachine >> numOrder >> maxFix;

    int* amount = new int[numMachine];
    int* declineRate  = new int [numMachine];
    int* fixTime  = new int [numMachine];
    int* startRate  = new int [numMachine];
    int* minRate  = new int [numMachine];
    for(int i = 0;i < numMachine;i++){ 
        cin >> amount[i] >> declineRate[i] >> fixTime[i] >> startRate[i] >> minRate[i];
    }
    
    int* orderQuantity = new int [numOrder];
    int* orderDeadline = new int [numOrder];
    for(int i = 0;i < numOrder;i++){
        cin >> orderQuantity[i] >> orderDeadline[i];
    }

    //operation

    //place the orders in order
    for(int i = 0; i < numOrder; i++)
    {
        int tempDeadline = 0, tempOrder = 0;
        for(int j = i + 1 ; j < numOrder ; j=j+1 )
        {
            if(orderDeadline[i] > orderDeadline[j])
            {
                tempDeadline = orderDeadline[i];
                orderDeadline[i] = orderDeadline[j];
                orderDeadline[j] = tempDeadline;
                tempOrder = orderQuantity[i];
                orderQuantity[i] = orderQuantity[j];
                orderQuantity[j] = tempOrder;
            }
            if(orderDeadline[i] == orderDeadline[j])
            {
                if(orderQuantity[i] > orderQuantity[j])
                {
                    tempDeadline = orderDeadline[i];
                    orderDeadline[i] = orderDeadline[j];
                    orderDeadline[j] = tempDeadline;
                    tempOrder = orderQuantity[i];
                    orderQuantity[i] = orderQuantity[j];
                    orderQuantity[j] = tempOrder;
                }
            }
        }
    }

    /*cout << endl;
    cout << "order imformation:" << endl;
    for(int i = 0; i < numOrder; i++)
        cout << orderQuantity[i] << " " << orderDeadline[i] << endl;*/

    //find out the min time
    int* nowTime = new int[numMachine];
    for(int i= 0; i < numMachine; i++)
        nowTime[i] = 0;

    int** orders = new int*[numMachine];
    for(int i= 0; i < numMachine; i++)
        orders[i] = new int[numOrder];
    int* count = new int[numMachine];
    for(int i= 0; i < numMachine; i++)
        count[i] = 0;
    
    int fixAmount[10000] = {0};
    
    for(int k = 0; k < numOrder; k++)
    {
        //no fix
        int bestMachine = 0, minTime = 9999999, preEndQ = 0, preStart = 0;
        bool type = 0;
        for(int l = 0; l < numMachine; l++)
        {
            int time = 0, machine = 0;
            int startQ1 = startRate[l];
            float tempQuant = 0;
            for(int i = time + 1;; i++)
            {
                if(startQ1 - declineRate[l] > minRate[l])
                    startQ1 -= declineRate[l];
                else
                {
                    startQ1 = minRate[l];
                    tempQuant += static_cast<float>(amount[l]) * static_cast<float>(startQ1) / static_cast<float>(100);
                }

                if(tempQuant >= static_cast<float>(orderQuantity[k]))
                {
                    time = i;
                    machine = l;
                    break;
                }
            }
            if(time + nowTime[machine] < minTime + nowTime[bestMachine])
            {
                minTime = time;
                bestMachine = machine;
                preEndQ = startQ1;
                preStart = startRate[l];
                type = 0;
            }
            else if(time + nowTime[machine] == minTime + nowTime[bestMachine])
            {
                if(startRate[l] < preStart)
                {
                    minTime = time;
                    bestMachine = machine;
                    preEndQ = startQ1;
                    preStart = startRate[l];
                    type = 1;
                }
            }
        }
        //cout  << minTime << bestMachine
        //fix
        for(int l = 0; l < numMachine; l++)
        {
            if(nowTime[l] <= maxFix)
            {
                int time = 0, machine = 0;
                int startQ1 = startRate[l];
                float tempQuant = 0;

                time += fixTime[l];
                startQ1 = 100 - declineRate[l];

                for(int i = time + 1;; i++)
                {
                    if(startQ1 - declineRate[l] > minRate[l])
                        startQ1 -= declineRate[l];
                    else
                        startQ1 = minRate[l];
                        tempQuant += static_cast<float>(amount[l]) * static_cast<float>(startQ1) / static_cast<float>(100);
                    if(tempQuant >= static_cast<float>(orderQuantity[k]))
                    {
                        time = i;
                        machine = l;
                        break;
                    }
                }

                if(time + nowTime[machine] < minTime + nowTime[bestMachine])
                {
                    minTime = time;
                    bestMachine = machine;
                    preEndQ = startQ1;
                    preStart = startRate[l];
                    type = 1;
                }
                else if(time + nowTime[machine] == minTime + nowTime[bestMachine])
                {
                    if(startRate[l] < preStart)
                    {
                        minTime = time;
                        bestMachine = machine;
                        preEndQ = startQ1;
                        preStart = startRate[l];
                        type = 1;
                    }
                }
            }
        }

        startRate[bestMachine] = preEndQ;
        nowTime[bestMachine] += minTime;
        orders[bestMachine][count[bestMachine]] = k + 1;
        count[bestMachine] += 1;
        if(type == 1)
        {
            for(int i = nowTime[bestMachine] - minTime + 1; i <= nowTime[bestMachine] - minTime + 1 + fixTime[bestMachine]; i++)
                fixAmount[i] += 1;
        }
        //cout << minTime << " " << bestMachine << endl;
    }

    for(int i = 0; i < numMachine; i++)
    {
        if(count[i] != 0)
        {
            for(int j = 0; j < count[i]; j++)
            {
                cout << orders[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}