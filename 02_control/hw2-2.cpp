#include <iostream>
using namespace std;

int main ()
{
    int  aduquant = 0, stuquant = 0, aduprice = 0, stuprice = 0, totalmoney = 0, elimtickets = 0, refund = 0;
    cin >> aduquant >> aduprice >> stuquant >> stuprice >> totalmoney >> elimtickets;

    if ((aduquant + stuquant) > elimtickets)
        cout << "-1";
    else if ((aduquant * aduprice + stuquant * stuprice) > totalmoney)
        cout << "-2";
    else
    {
        refund = totalmoney - (aduquant * aduprice + stuquant * stuprice);
        cout << refund / 500 << "," << (refund % 500) / 100 << "," << (refund % 100) / 50 << ","
             << (refund % 50) / 10 << "," << (refund % 10) / 5 << "," << refund % 5;
    }

    return 0;
}