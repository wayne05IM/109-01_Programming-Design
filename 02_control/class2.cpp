#include <iostream>
using namespace std;

/*int main()
{
    int a = 0;
    cin >> a;
    while (true)
    {
        if (a % 2 == 0)
            a = a / 2;
        else
            a = (a * 3) + 1;
        cout << a;
        if (a == 1)
            break;
        else 
            cout << " ";
    }
    return 0;
}*/

int main()   //better answer or using do-while
{
    int value = 0;
    cin >> value;
    while (true)
    {
        if (value % 2 == 1)
            value = (value * 3) + 1;
        else
            value = value / 2;
        cout << value;

        if (value != 1)
            cout << " ";

        if (value == 1)
            break;
    }
    return 0;
}