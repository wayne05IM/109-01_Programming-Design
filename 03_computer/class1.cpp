#include <iostream>
using namespace std;

/*int main()
{
    int tenBaseValue = 0, convertBase = 0;
    cin >> tenBaseValue >> convertBase;
    while (tenBaseValue >= convertBase)
    {
        tenBaseValue = tenBaseValue / convertBase;
    }
    cout << tenBaseValue;
    return 0;
}*/

int main()      //better solution 
{
    int value = 0, base = 0;
    cin >> value >> base;
    int quotient = 0, remainder = 0;
    
    while(true)
    {
        quotient = value / base;
        remainder = value % base;

        cout << quotient << " " << remainder << "\n";
        value = quotient;

        if (value < base)
            break; 
    }
    cout << value;

    return 0;
}