#include <iostream>
using namespace std;

int main()
{
    int number = 0, temp = 0;
    cin >> number;
    // do the operations until the number equals 6174
    while (number != 6174)
    {
        // calculate the number of each digit
        int thousand = number / 1000;
        int hundred = (number % 1000) / 100;
        int ten = (number % 100) / 10;
        int one = number % 10;
        // compare the value of each digit to find out the biggest value
        if (thousand < one)
        {
            temp = thousand;
            thousand = one;
            one = temp;
        }
        if (thousand < ten)
        {
            temp = thousand;
            thousand = ten;
            ten = temp;
        }
        if (thousand < hundred)
        {
            temp = thousand;
            thousand = hundred;
            hundred = temp;
        }
        if (hundred < one)
        {
            temp = hundred;
            hundred = one;
            one = temp;
        }
        if (hundred < ten)
        {
            temp = hundred;
            hundred = ten;
            ten = temp;
        }
        if (ten < one)
        {
            temp = ten;
            ten = one;
            one = temp;
        }
        //find out the maximum and the minimum value and the next number
        int maxValue = thousand * 1000 + hundred * 100 + ten * 10 + one;
        int minValue = one * 1000 + ten * 100 + hundred * 10 + thousand;
        number = maxValue - minValue;
        //put the comma in the exact place and print out the value
        if (number == 6174)
            cout << number;
        else 
            cout << number << ",";
    }
    return 0;
}