#include <iostream>
using namespace std;

int main()
{
    int  aduquant = 0, stuquant = 0, aduprice = 0, stuprice = 0, totalmoney = 0, elimtickets = 0;
    cin >> aduquant >> aduprice >> stuquant >> stuprice >> totalmoney >> elimtickets;

    if ((aduquant + stuquant) > elimtickets)
        cout << "-1";
    else if ((aduquant * aduprice + stuquant * stuprice) > totalmoney)
        cout << "-2";
    else
        cout << totalmoney - (aduquant * aduprice + stuquant * stuprice);

    return 0;
}