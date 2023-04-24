#include <iostream>
using namespace std;

int main()
{
    //inputs and data process
    int  typesOfTickets = 0, fund = 0, cashToPay = 0, limTickets = 0, refund = 0, totalQuant = 0;
    cin >> typesOfTickets >> fund >> limTickets;
    
    for (int type = 0, quant = 0, price = 0; type < typesOfTickets; type++) 
    {
        cin >> quant >> price;
        totalQuant += quant; 
        cashToPay += quant * price;
    }
    //case decision 
    if (totalQuant > limTickets)
        cout << "-1";
    else if (cashToPay > fund)
        cout << "-2";
    else
    {
        refund = fund - cashToPay;
        cout << refund / 500 << "," << (refund % 500) / 100 << "," << (refund % 100) / 50 << ","
             << (refund % 50) / 10 << "," << (refund % 10) / 5 << "," << refund % 5;
    }

    return 0;
}