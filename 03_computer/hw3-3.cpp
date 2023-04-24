#include <iostream>
using namespace std;

int main()
{
    int number = 0, numberarray[4];
    cin >> number;
    // calculate the number of each digit
    numberarray[0] = number / 1000;
    numberarray[1] = (number % 1000) / 100;
    numberarray[2] = (number % 100) / 10;
    numberarray[3] = number % 10;
    // use for loop to check the which number is bigger
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1, temp = 0; j < 4; j++)
        {
            // if the latter is bigger then swap it
            if (numberarray[j] > numberarray[i])
            {
                temp = numberarray[i];
                numberarray[i] = numberarray[j];
                numberarray[j] = temp;
            }
            // do the new loop to check if the next number is bigger
        }
    }
    // conbine all the numbers in to a four digit number
    cout << numberarray[0] * 1000 + numberarray[1] * 100 + numberarray[2] * 10 + numberarray[3];
    return 0;
}