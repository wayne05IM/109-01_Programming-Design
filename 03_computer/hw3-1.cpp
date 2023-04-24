#include <iostream>
using namespace std;
 
int main()
{
    // input value to array
    int number = 0;
    cin >> number;
    int numberArray[number] ;
    for (int i = 0; i < number; i++)
    {
        cin >> numberArray[i];
    }
    // read every array elements and condition judgment
    int length = 0, firstNumber = 0;
    for (int j = 0, preLength = 0, preFirstNumber = 0; j < number; j++)
    {
        // judge the sign of numberArray[j]
        if ((numberArray[j] <= 0) and (number != 1))
        {
            if (preLength > length)
            {
                length = preLength;
                firstNumber = preFirstNumber;
            }
            preLength = 0;
            preFirstNumber = 0;
        }
        else if (numberArray[j] > 0)
        {
            preLength ++;
            if (preLength == 1)
                preFirstNumber = j + 1;
            if ((length == 0) and (j != 0))
            {
                length = preLength;
                firstNumber = preFirstNumber;
            }
        }
        // print out condition
        if ((length != 0) and (j == (number - 1)))
        {
            if (preLength > length)
            {
                length = preLength;
                firstNumber = preFirstNumber;
            }
            cout << length << "," << firstNumber;
        }
        else if ((length == 0) and (j == (number - 1)))
            cout << length;
    }
    return 0;
}