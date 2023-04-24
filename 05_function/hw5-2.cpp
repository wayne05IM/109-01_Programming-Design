#include <iostream>
#include <cmath>
using namespace std;
// global value
const int PERIOD_CNT_MAX = 1000;
const int WINDOWSIZE_MAX = 6;
//header of function MAPE
float MAPE(int windowSize , int periodCut , const int sales []);

int main()
{
    //input value
    int periodCut = 0;
    int sales[PERIOD_CNT_MAX] = {0};

    cin >> periodCut;
    for (int i = 0; i < periodCut; i++)
        cin >> sales[i];
    //count all the MAPEs
    const int MAPE_MAX = 10;
    float mape[MAPE_MAX] = {0};
    for (int windowSize = 2; windowSize <= WINDOWSIZE_MAX; windowSize++)
    {
        mape[windowSize - 1] = MAPE (windowSize , periodCut, sales); //call function to count MAPE
    }
    //find out the smallest MAPE and the best window size
    int bestWindowSize = 0;
    float bestMAPE = 1000000;
    for (int j = 1; j < WINDOWSIZE_MAX; j++)
    {
        if ((mape[j] < bestMAPE) and (mape[j] >= 0))
        {
            bestWindowSize = j + 1;
            bestMAPE = mape[j];
        }
    }
    //casting the best MAPE into a two digit number and output the result 
    bestMAPE = static_cast<int>(bestMAPE * 100);
	cout << bestWindowSize << "," << bestMAPE;

    return 0;
}
//MAPE counting function
float MAPE(int windowSize , int periodCut , const int sales [])
{
    float MAE = 0;
    float MAESUM = 0;
    for (int i = windowSize; i < periodCut; i++)
    {
        if (sales[i] != 0)
        {
            int sum = 0;
            float fcst = 0;
            for (int j = i - 1; j >= i - windowSize; j--)
                sum += sales[j];
            fcst = static_cast<float>(sum) / windowSize;
            
            MAE = abs(sales[i] - fcst) / sales[i];
            MAESUM += MAE;
        }
        else
            MAESUM = -1;
    }     
    return (MAESUM /(periodCut - windowSize));
}