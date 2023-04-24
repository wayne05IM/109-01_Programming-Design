#include <iostream>
using namespace std;

int gcd (int a, int b)
{
    int number = 0;
    if(a > b)
        number = b;
    else
        number = a;

    while (number >= 0)
    {
        if((a % number == 0) and (b % number == 0))
            return number;
        number --;
    }
    return 0;
}

/*int min (int a, int b)
{
    if(a > b)
        return b;
    else
        return a;   
}

int gcd(int a, int b)   //better solution
{
    int m = min(a, b);
    for (int i = m; i >= 2; i--)
    {
        if ((a % i == 0) and (b % i == 0))
            return i;
    }
    return 1;
}*/

int main()
{
    int number1 = 0, number2 = 0;
    cin >> number1 >> number2;
    int greatestCommonDivisor = gcd(number1, number2);
    cout << greatestCommonDivisor;
    return 0;
}