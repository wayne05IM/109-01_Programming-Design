#include <iostream>
using namespace std;

/*int main()
{
    int itemNumbers = 0, maxWeight = 0;
    int itemWeightArray[100] = {0}, itemPriceArray[100] = {0}, itemTakeArray[100] = {0};
    cin >> itemNumbers >> maxWeight;

    for (int i = 0; i < itemNumbers; i++)
        cin >> itemWeightArray[i];
    for (int j = 0; j < itemNumbers; j++)
        cin >> itemPriceArray[j];
    for (int k = 0; k < itemNumbers; k++)
        cin >> itemTakeArray[k];
    
    int totalWeight = 0, totalPrice = 0;
    for (int x = 0; x < itemNumbers; x++)
    {
        totalWeight += (itemWeightArray[x]*itemTakeArray[x]);
        totalPrice += (itemPriceArray[x]*itemTakeArray[x]);
    }

    if (totalWeight > maxWeight)
        cout << 0;
    else
        cout << totalWeight << " " << totalPrice;
    
    return 0;
}*/

int main()           //better solution
{
    int itemCnt = 0, capacity = 0;
    cin >> itemCnt >> capacity;
    
    int weights[100] = {0}, values[100] = {0};
    bool selection[100] = {0};

    for (int i = 0; i < itemCnt; i++)
        cin >> weights[i];
    for (int j = 0; j < itemCnt; j++)
        cin >> values[j];
    for (int k = 0; k < itemCnt; k++)
        cin >> selection[k];
    
    int totalWeight = 0, totalValue = 0;
    for (int x = 0; x < itemCnt; x++)
    {
        totalWeight += (selection[x]*weights[x]);
        totalValue += (selection[x]*values[x]);
    }

    if (totalWeight > capacity)
        cout << 0;
    else
        cout << totalWeight << " " << totalValue;
    
    return 0;
}