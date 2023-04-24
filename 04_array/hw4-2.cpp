#include <iostream>
using namespace std;

int main()
{
    int valueAmount = 0, factor = 0;
    cin >> valueAmount >> factor;

    const int AMOUNT_MAX = 1000;
    int numberArray[AMOUNT_MAX] = {0};

    for (int i = 0; i < valueAmount; i++)  //read in array
        cin >> numberArray[i];

    for (int i = 0; i < valueAmount; i++) //append 0 to numbers that has the factor
    {
        if ((numberArray[i] % factor == 0) and (numberArray[i] > 0))
            numberArray[i] = 0;
    }

    int finalSum = -10002, finalFirst = 0, finalEnd = 0;
    for (int i = 0, tempSum = -10001, tempFirst = 0, tempEnd = 0, tempLength = 0, length = 0; i < valueAmount; i++)
    {
        tempFirst = i + 1;
        for (int j = i, sum = 0; j < valueAmount; j++)
        {
            sum += numberArray[j];
            if (sum >= tempSum)
            {
                tempSum = sum;
                tempEnd = j + 1;
            }
        }
        tempLength = tempEnd - tempFirst + 1;
        if (tempSum > finalSum)
        {
            length = tempLength;
            finalSum = tempSum;
            finalFirst = tempFirst;
            finalEnd = tempEnd;
        }
        else if ((tempSum == finalSum) and (tempLength >= length))
        {
            length = tempLength;
            finalSum = tempSum;
            finalFirst = tempFirst;
            finalEnd = tempEnd;
        }
    }
    
    cout << finalFirst << "," << finalEnd << "," << finalSum;
    
    return 0;
}