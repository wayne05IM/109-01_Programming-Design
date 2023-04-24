#include <iostream>
using namespace std;

/*int main()
{
    int averageAmounts = 0, valueAmounts = 0;
    cin >> averageAmounts >> valueAmounts;

    int demandsArray[1000] = {0};
    for (int i = 0; i < valueAmounts; i++)
        cin >> demandsArray[i];

    for (int i = 0, totalDemand = 0; i < valueAmounts - (averageAmounts - 1); i++)
    {
        for (int j = i; j < i + averageAmounts; j++)
        {
            totalDemand += demandsArray[j];
        }
        cout << (totalDemand / averageAmounts);
        if (i != valueAmounts - averageAmounts)
            cout << " ";
        totalDemand = 0;
    }
    return 0;
}*/

int main()       //better solution
{
    const int PERIOD_CNT_MAX = 1000;
    int windowSize = 0, periodCnt = 0;
    int sales[PERIOD_CNT_MAX] = {0};

    cin >> windowSize >> periodCnt;
    for (int i = 0; i < periodCnt; i++)
        cin >> sales[i];

    for (int i = windowSize; i < periodCnt; i++)
    {
        int fsct = 0;
        for (int j = i - 1; j >= i - windowSize; j--)
            fsct += sales[j];
        fsct = fsct / windowSize;
        cout << fsct << " ";
    }
    int fsct = 0;
    for (int j = periodCnt - 1; j >= periodCnt - windowSize; j--)
        fsct += sales[j];
    fsct = fsct / windowSize;
    cout << fsct;
    return 0;
}