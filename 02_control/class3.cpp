#include <iostream>
using namespace std;

/*int main()
{
    int a = 0, b = 0, cost = 0, maxprofit = 0, optimalprice = 0;
    cin >> a >> b >> cost;
    for(int tempprofit = 0,tempprice = cost + 1;;tempprice++)
    {
        tempprofit = (a - b*tempprice)*(tempprice - cost);
        if (tempprofit <= maxprofit)
        {
            cout << optimalprice << " "<< maxprofit;
            break;
        }
        optimalprice = tempprice;
        maxprofit = tempprofit;
    }
    return 0;
}*/


int main()         //better answer
{
    int baseDemand = 0, sensitivity = 0, cost = 0;
    cin >> baseDemand >> sensitivity >> cost;
    
    int maxProfit = 0, optimalPrice = 0;
    for(int price = 0;price <= (baseDemand / sensitivity);price++)
    {
        int profit = (baseDemand - sensitivity * price) * (price - cost);
        //cout << price << " " << profit << "\n";
        if(profit > maxProfit)
        {
            maxProfit = profit;
            optimalPrice = price;
        }
    }
    cout << optimalPrice << " " << maxProfit;
    return 0;
}