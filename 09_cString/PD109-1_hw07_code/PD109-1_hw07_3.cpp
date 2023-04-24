#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getProfit(int*&  cost, int***&  rev, bool*&  tmp_built, int*&  deg, int const n);
int getOutlinkSum(int**&  rev, int const degree, bool*&  tmp_built);
//allocate one more space when get one more new neighbor
int** addOneMoreElement(const int to, const int profit, const int n, int** arr);
//allocate double space when there's no more space for new neighbor
int** addOneMoreElement2(const int from, const int to, const int profit, const int curPointerLoc, int** arr, int* curArrSize);

int main(int argc, char** argv){
    int nodeCnt = 0, flightCnt = 0;
    cin >> nodeCnt >> flightCnt;
    int *cost = new int[nodeCnt];
    int *degree = new int[nodeCnt];
    int ***rev = new int**[nodeCnt];

    for (int i = 0; i < nodeCnt; i++)
    {
        cin >> cost[i];
        degree[i] = 0;
        rev[i] = nullptr;
    }

    int* curArrSize = new int[nodeCnt];
    for (int i = 0; i < nodeCnt; i++)
    {
        curArrSize[i] = flightCnt / nodeCnt + 1;
        rev[i] = new int*[curArrSize[i]];
        for (int j = 0; j < curArrSize[i]; j++)
            rev[i][j] = new int[2];
    }

    for (int i = 0; i < flightCnt; i++)
    { 
        int from = 0, to = 0, r = 0;
        cin >> from >> to >> r;
    //     rev[from-1] = addOneMoreElement(to-1, r, degree[from-1], rev[from-1]);
    //     rev[to-1] = addOneMoreElement(from-1, r, degree[to-1], rev[to-1]);
        rev[from-1] = addOneMoreElement2(from-1, to-1, r, degree[from-1], rev[from-1], curArrSize);
        rev[to-1] = addOneMoreElement2(to-1, from-1, r, degree[to-1], rev[to-1], curArrSize);
        degree[from-1] += 1;        
        degree[to-1] += 1;
    }
    

    // check input
    // for (int i = 0; i < nodeCnt; i++)
    // {
    //     cout << "from: " << i << " to: ";
    //     for (int j = 0; j < degree[i]; j++)
    //     {
    //         cout << "(" << rev[i][j][0] << " ," << rev[i][j][1] << ") -> ";
    //     }
    //     cout << endl;
    // }

    
    //algorithm is the same as HW4
    bool* built = new bool[nodeCnt];
    for (int i = 0; i < nodeCnt; i++)
    {
        built[i] = 1;
    }
    bool removed_in_this_round = true;
    int opt_profit = getProfit(cost, rev, built, degree, nodeCnt);
    while (true)
    {
        int opt_spot = -1;
        removed_in_this_round = false;
        int oriProfitThisRnd = opt_profit;
        for (int tmp_rm_spot = 0; tmp_rm_spot < nodeCnt; tmp_rm_spot++)
        {
            if (built[tmp_rm_spot])
            {
                built[tmp_rm_spot] = 0;
            }
            else
            {
                continue;
            }

            int rm_spot_profit = 0;
            for (int i = 0; i < degree[tmp_rm_spot]; i++) //from: tmp_rm_spot
            {
                int to = rev[tmp_rm_spot][i][0];
                int r = rev[tmp_rm_spot][i][1];
                rm_spot_profit += r * built[to];
            }
            rm_spot_profit -= cost[tmp_rm_spot];
            int tmp_profit = oriProfitThisRnd - rm_spot_profit;
            if (tmp_profit > opt_profit)
            {
                opt_profit = tmp_profit;
                opt_spot = tmp_rm_spot;
                removed_in_this_round = true;
            }
            built[tmp_rm_spot] = 1;
        }

        if (removed_in_this_round)
        {
            built[opt_spot] = 0;
            // cout << "**rm spot in this round:" << opt_spot << " profit = " << opt_profit << endl;
        }
        else
        {           
            bool first = true;
            for (int i = 0; i < nodeCnt; i++)
            {
                if(first && built[i])
                {
                    cout << i + 1;
                    first = false;   
                }
                else if(built[i])
                {
                    cout << "," << i + 1;
                }
            }
            cout << ";" << opt_profit << endl;
            break;
        }
    }
    return 0;
}

int getProfit(int*&  cost, int***&  rev, bool*&  tmp_built, int*&  deg, int const n)
{
    int tmp_total_rev = 0, tmp_total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        tmp_total_cost += tmp_built[i] * cost[i];
    }
    for (int i = 0; i < n; i++)
    {
        tmp_total_rev += getOutlinkSum(rev[i], deg[i], tmp_built);
    }
    tmp_total_rev /= 2;
    return tmp_total_rev - tmp_total_cost;
}

int getOutlinkSum(int**&  rev, int const degree, bool*&  tmp_built)
{
    int totalRev = 0;
    for (int i = 0; i < degree; i++) //from: i
    {
        int to = rev[i][0];
        int r = rev[i][1];
        totalRev += r * tmp_built[to];
    }
    return totalRev;
}

int** addOneMoreElement(const int to, const int profit, const int curPointerLoc, int** arr)
{
    int** newArr = new int*[curPointerLoc+1];
    for (int i = 0; i < curPointerLoc; i++)
    {
        newArr[i] = new int[2];
        newArr[i][0] = arr[i][0];
        newArr[i][1] = arr[i][1];
        delete [] arr[i];
    }
    newArr[curPointerLoc] = new int[2];
    newArr[curPointerLoc][0] = to;
    newArr[curPointerLoc][1] = profit;

    delete [] arr;
    return newArr;
}

int** addOneMoreElement2(const int from, const int to, const int profit, const int curPointerLoc, int** arr, int* curArrSize)
{
    if (curPointerLoc >= curArrSize[from])
    {
        //expend size
        int** newArr = new int*[2 * curPointerLoc];
        curArrSize[from] = 2 * curPointerLoc;
        for (int j = 0; j < curArrSize[from]; j++)
            newArr[j] = new int[2];
        for (int i = 0; i < curPointerLoc; i++)
        {
            newArr[i][0] = arr[i][0];
            newArr[i][1] = arr[i][1];
            delete [] arr[i];
        }
        newArr[curPointerLoc][0] = to;
        newArr[curPointerLoc][1] = profit;

        delete [] arr;
        return newArr;
    }
    else
    {
        arr[curPointerLoc][0] = to;
        arr[curPointerLoc][1] = profit;
        return arr;
    }
}

