#include <iostream>
using namespace std;

int min (int a, int b)
{
    if(a > b)
        return b;
    else
        return a;   
}

int main()
{
    int number1 = 0, number2 = 0;
    cin >> number1 >> number2;
    int theSmallerNumber = min(number1, number2);
    cout << theSmallerNumber;
    return 0;
}