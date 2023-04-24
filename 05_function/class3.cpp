#include <iostream>
using namespace std;

/*int min (int a, int b, int c)
{
    int minNumber;
    if(a > b)
        minNumber = b;
    else
        minNumber = a;

    if(minNumber > c)
        minNumber = c;

    return minNumber;
}

int gcd(int a, int b, int c)
{
    int m = min(a, b, c);
    for (int i = m; i >= 2; i--)
    {
        if ((a % i == 0) and (b % i == 0) and (c % i ==0))
            return i;
    }
    return 1;
}*/

int min (int a, int b)
{
    if(a > b)
        return b;
    else
        return a;   
}

int gcd(int a, int b, int c)   //better solution
{
    int m = min(min(a, b), c);
    for (int i = m; i >= 2; i--)
    {
        if ((a % i == 0) and (b % i == 0))
            return i;
    }
    return 1;
}

int gcd(int a, int b, int c)   //??
{
    return gcd(gcd(a, b),c);
}

int main()
{
    int number1 = 0, number2 = 0, number3;
    cin >> number1 >> number2 >> number3;
    int greatestCommonDivisor = gcd(number1, number2, number3);
    cout << greatestCommonDivisor;
    return 0;
}