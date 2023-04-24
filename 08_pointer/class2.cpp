#include<iostream>
using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    cout << a << "\n";

    int* aPtr = &a;
    *aPtr = 1000;
    cout << a << "\n";

    return 0;
}