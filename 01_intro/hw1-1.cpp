#include <iostream>
using namespace std;

int main()
{
    int  aduquant = 0, stuquant = 0, aduprice = 0, stuprice = 0, pay = 0, totalfee = 0, backfee = 0;

    cin >> aduquant >> stuquant >> aduprice >> stuprice >> pay;
    totalfee = aduquant * aduprice + stuquant * stuprice;
    if (pay >= totalfee)
        cout << pay - totalfee;
    else
        cout << "-1," << totalfee - pay;
    return 0;
}