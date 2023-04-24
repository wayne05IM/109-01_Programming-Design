#include <iostream>
using namespace std;

const int NUM_TYPE = 2;
const int MAX_NUMBOUND = 10;
const int MAX_NUMTOBUY = 100000;

const int CUTOFF_NUM_MAX = 10;
bool isFeasibleToBuy(const int ticketNum[], const int intervalNum[], int budget, const int cutoffs[][CUTOFF_NUM_MAX], const int prices[][CUTOFF_NUM_MAX + 1]);

int main()
{
    // input
    int numBound[NUM_TYPE] = {0};
    int numToBuy[NUM_TYPE] = {0};
    int bound[NUM_TYPE][MAX_NUMBOUND] = {0};
    int price[NUM_TYPE][MAX_NUMBOUND + 1] = {0};
    int numBought[NUM_TYPE] = {0};
    int budget = 0, mode = 0;
    
    for(int i = 0; i < NUM_TYPE; i++)
    {
        cin >> numBound[i];
    }
    for(int i = 0; i < NUM_TYPE; i++)
    {
        cin >> numToBuy[i];
    }
    cin >> budget >> mode;
    
    for(int i = 0; i < NUM_TYPE; i++)
    {
        for(int j = 0; j < numBound[i]; j++)
        {
            cin >> bound[i][j] >> price[i][j];
        }
        cin >> price[i][numBound[i]];
    }

    // algo
    
    int totalPrice = 0;
    if(mode == 1 || mode == 2)
    {
        int target = mode - 1;
        int order[NUM_TYPE] = {target, 1-target};
        // 先買目標那種
        for(int i = 0; i < NUM_TYPE; i++)
        {
            int type = order[i];

            for(int j = 0; j < numBound[type]; j++)
            {
                int budgetLimit = (budget - totalPrice) / price[type][j];

                // 如果想買的數量 <= 現在這個門檻，表示進這裡就會買完
                if(numToBuy[type] <= bound[type][j])
                {
                    // 檢查是否卡到預算，是的話就只買到預算可買的張數
                    if(budgetLimit < numToBuy[type] - numBought[type])
                    {
                        totalPrice += budgetLimit * price[type][j];
                        numBought[type] += budgetLimit;
                    }
                    // 否的話買完
                    else
                    {
                        totalPrice += (numToBuy[type] - numBought[type]) * price[type][j];
                        numBought[type] = numToBuy[type];
                    }
                    // 要馬卡到預算要馬買完，因此這邊跑完就跳離開這種票的購買流程，進到下一種票的購買流程
                    break;
                }
                else
                {
                    if(budgetLimit < bound[type][j] - numBought[type])
                    {
                        totalPrice += budgetLimit * price[type][j];
                        numBought[type] += budgetLimit;
                        break;
                    }
                    else
                    {
                        totalPrice += (bound[type][j] - numBought[type]) * price[type][j];
                        numBought[type] = bound[type][j];
                    }
                }
            }
            // 如果想要購買的數量超過最後一段的話
            if(numToBuy[type] > numBought[type])
            {
                int budgetLimit = (budget - totalPrice) / price[type][numBound[type]];
                // 同樣檢查是否卡到預算，卡到的話就買預算內可買的張數
                if(budgetLimit < numToBuy[type] - numBought[type])
                {
                    totalPrice += budgetLimit * price[type][numBound[type]];
                    numBought[type] += budgetLimit;
                }
                // 沒卡到預算就買完
                else
                {
                    totalPrice += (numToBuy[type] - numBought[type]) * price[type][numBound[type]];
                    numBought[type] = numToBuy[type];
                }
            }
        }
    }
    else
    {
        // mode 0 原則上是窮舉

        int boughtTicket1[MAX_NUMTOBUY + 1] = {0}; // 存放買第一種票幾張的時候需要多少錢
        int boughtTicket2[MAX_NUMTOBUY + 1] = {0}; // 存放買第二種票幾張的時候需要多少錢

        // 跑過第一種票，從第 0 張開始跑到想要買的張數張，看看每一種購買張數要花多少錢
        for(int i = 0; i <= numToBuy[0]; i++)
        {
            int totalPrice1 = 0;
            int bought1 = 0;
            
            // 買第一種票 i 張，先不管預算，方式如同之前作業及上方 mode 1,2 只是不管預算
            for(int b1 = 0; b1 < numBound[0]; b1 ++)
            {
                if(i <= bound[0][b1])
                {
                    totalPrice1 += (i - bought1) * price[0][b1];
                    bought1 = i;
                    break;
                }
                else
                {
                    totalPrice1 += (bound[0][b1] - bought1) * price[0][b1];
                    bought1 = bound[0][b1];
                }
            }
            if(i > bought1)
            {
                totalPrice1 += (i - bought1) * price[0][numBound[0]];
            }
            boughtTicket1[i] = totalPrice1;
        }

        // 跑過第二種票，從第 0 張開始跑到想要買的張數張，看看每一種購買張數要花多少錢
        for(int j = 0; j <= numToBuy[1]; j++)
        {
            int totalPrice2 = 0;
            int bought2 = 0;
            // 買第二種票 j 張
            for(int b2 = 0; b2 < numBound[1]; b2 ++)
            {
                if(j <= bound[1][b2])
                {
                    totalPrice2 += (j - bought2) * price[1][b2];
                    bought2 = j;
                    break;
                }
                else
                {
                    totalPrice2 += (bound[1][b2] - bought2) * price[1][b2];
                    bought2 = bound[1][b2];
                }
            }
            if(j > bought2)
            {
                totalPrice2 += (j - bought2) * price[1][numBound[1]];
            }

            boughtTicket2[j] = totalPrice2;
        }

        // 以上跑完可以得到兩種票數所有的購買組合，接下來比較該買哪種票數組合最好
        
        // 跑過所有組合
        for(int i = 0; i <= numToBuy[0]; i++)
        {
            for(int j = 0; j <= numToBuy[1]; j++)
            {
                int nowTicketNum[2] = {i,j};
                // 總票價低於預算的才需要考慮
                if(isFeasibleToBuy(nowTicketNum, numBound, budget, bound, price))
                {
                    // 選總票數最大的
                    if(numBought[0] + numBought[1] < i+j)
                    {
                        numBought[0] = i;
                        numBought[1] = j;
                        totalPrice = boughtTicket1[i] + boughtTicket2[j];
                    }
                    else if(numBought[0] + numBought[1] == i+j)
                    {
                        // 若一樣，選乘積最大的
                        if(numBought[0] * numBought[1] < i*j)
                        {
                            numBought[0] = i;
                            numBought[1] = j;
                            totalPrice = boughtTicket1[i] + boughtTicket2[j];
                        }
                        // 若又一樣，選第一種票數最多的
                        else if(numBought[0] * numBought[1] == i*j && numBought[0] < i)
                        {
                            numBought[0] = i;
                            numBought[1] = j;
                            totalPrice = boughtTicket1[i] + boughtTicket2[j];
                        }
                    }
                }
            }
        }
    
    }
    
    // 最後輸出
    for(int i = 0; i < NUM_TYPE; i++)
    {
        cout << numBought[i] << ",";
    }
    cout << totalPrice;
    
    return 0;
}


bool isFeasibleToBuy(const int ticketNum[], const int intervalNum[], int budget ,
                    const int cutoffs[][CUTOFF_NUM_MAX], const int prices[][CUTOFF_NUM_MAX + 1])
{
    int funcTotalPrice = 0;
    int k = 0;
    for (int i = 1; i <= ticketNum[0]; i++)
    {
        if(k < intervalNum[0])
        {
            if(i > cutoffs[0][k])
                k++;    
        }
        funcTotalPrice += prices[0][k];
    }
    k = 0; 
    for (int i = 1; i <= ticketNum[1]; i++)
    {
        
        if(k < intervalNum[1])
        {
            if(i > cutoffs[1][k])
                k++;
        }
        funcTotalPrice += prices[1][k];
    }
    if(funcTotalPrice > budget)
        return false;
    else
        return true;
}