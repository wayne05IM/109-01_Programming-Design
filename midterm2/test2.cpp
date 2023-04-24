#include<iostream>
using namespace std;

const int RECTANGLE_MAX = 11;
const int DOT_AMOUNT = 5;

int main()
{
    //input
    int rectangleAmount = 0;
    cin >> rectangleAmount;

    int rectangleX[RECTANGLE_MAX][DOT_AMOUNT] = {0}, rectangleY[RECTANGLE_MAX][DOT_AMOUNT] = {0};
    for(int i= 1; i <= rectangleAmount; i++)
    {
        for(int j = 1; j < DOT_AMOUNT; j++)
            cin >> rectangleX[i][j];
        for(int k = 1; k < DOT_AMOUNT; k++)
            cin >> rectangleY[i][k];
    }

    //operate
    bool yorn = 0;
    for(int i = 1; i <= rectangleAmount; i++)
    {
        for(int k = i + 1; k <= rectangleAmount; k++)
        {
            for (int j = 1; j < DOT_AMOUNT; j++)
            {
                if((rectangleX[k][j] > rectangleX[i][1]) and (rectangleX[k][j] < rectangleX[i][2]))
                {
                    if((rectangleY[k][j] > rectangleY[i][3]) and (rectangleY[k][j] < rectangleY[k][1]))
                    {
                        yorn = 1;
                        break;
                    }
                }
            }
        }
    }

    cout << yorn;

    return 0;
}