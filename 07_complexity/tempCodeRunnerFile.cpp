#include <iostream>
using namespace std;

const int DOT_MAX = 101;

bool cycle(int start, int first, int checkDotNum, bool adjacency[][DOT_MAX], int dotToCheck[]);

int main()
{
    //input
    int dot = 0, line = 0;
    cin >> dot >> line;

    bool adjacency[DOT_MAX][DOT_MAX] = {0};
    for(int i = 1; i <= line; i++)
    {
        int start = 0, end = 0;
        cin >> start >> end;
        adjacency[start][end] = 1;
    }

    int checkDotNum = 0;
    cin >> checkDotNum;
    int dotToCheck[DOT_MAX] = {0};
    for(int i = 1; i <= checkDotNum; i++)
        cin >> dotToCheck[i];

    //operation
    bool YorN = 0; 
    for(int i = 1; i <= checkDotNum; i++)
    {
        YorN = cycle(i, i, checkDotNum, adjacency, dotToCheck);
        if(YorN == 1)
            break;
    }
    cout << YorN;

    return 0;
}

int passDot[100] = {0}, k = 0;
bool cycle(int start, int first, int checkDotNum, bool adjacency[][DOT_MAX], int dotToCheck[])
{
    for(int i = 1; i <= checkDotNum; i++)
    {
        if(adjacency[dotToCheck[start]][dotToCheck[i]] == 1)
        {
            cin >> passDot[k];
            k++;
            if((i == first) and (i != start))
            {
                return true;
            }
            for(int j = 0; j < 100; j++)
            {
                if(passDot[j] == i)
                {
                    passDot[100] = {0};
                    return true;
                }
            }
            bool a = cycle(i, first, checkDotNum, adjacency, dotToCheck);
            if(a == true)
                return true;
        }
    }
    return false;
}