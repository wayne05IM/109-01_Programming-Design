#include <iostream>
using namespace std;

const int DOT_MAX = 101;

bool cycle(int start, int checkDotNum, bool adjacency[][DOT_MAX], int dotToCheck[]);

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
    bool YorN = false;
    int checkArray[DOT_MAX][DOT_MAX] = {0}, k = 1;
    for(int graphs = 1; graphs <= checkDotNum; graphs++)
    {
        for(int i = 1; i <= checkDotNum; i++) // step
        {
            for(int j = 1; j <= checkDotNum; j++) // end
            {
                if((i == 1) or (checkArray[i - 1][dotToCheck[j]] == 1))
                {
                    if(adjacency[dotToCheck[k]][dotToCheck[j]] == 1)
                        checkArray[i][dotToCheck[j]] = 1;
                }
            }
        }
        if()
        for(int x = 1; x <= checkDotNum; x++)
        {
            if(checkArray[x][dotToCheck[k]] == 1)
            {
                YorN = true;
                break;
            }
        }
    }

    cout << YorN;

    return 0;
}