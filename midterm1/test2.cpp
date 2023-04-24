#include <iostream>
using namespace std;

int main()
{
    int cityNum = 0, distance = 0;
    cin >> cityNum >> distance;

    const int MAX_CITY = 101;
    int cityPop[MAX_CITY] = {0};
    for(int i = 1; i <= cityNum; i++)
        cin >> cityPop[i];
    
    int servePop[MAX_CITY] = {0};
    for(int i = 1; i <= cityNum; i++)
    {
        servePop[i] += cityPop[i];
        for(int k = i + 1; k <= i + distance; k++)
        {
            if(k <= cityNum)
                servePop[i] += cityPop[k];
            else
                break;
        }
        for(int j = i - 1; j >= i - distance; j--)
        {
            if(j > 0)
                servePop[i] += cityPop[j];
            else
                break;
        }
    }

    int maxPop = 0;
    for (int i = 1; i <= cityNum; i++)
    {
        if(servePop[i] > maxPop)
            maxPop = servePop[i];
    }

    cout << maxPop;

    return 0;
}