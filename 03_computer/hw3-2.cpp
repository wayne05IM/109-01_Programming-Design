#include <iostream>
using namespace std;

int main ()
{
    // input value
    int number = 0, ticketToBuy = 0;
    cin >> number >> ticketToBuy;

    int totalPrice = 0;
    for (int i = 0, totalQuant = 0, ticketPrice = 0, exQuant = 0; i < number; i++)//do n times
    {
        cin >> totalQuant >> ticketPrice; // input value
        
        if (totalQuant <= ticketToBuy)  // when the quantity is more than the total quantity
            totalPrice += (totalQuant - exQuant) * ticketPrice;
        else    // when the quantity is less than the total quantity
        {
            totalPrice += (ticketToBuy - exQuant) * ticketPrice;
            break;
        }
        exQuant = totalQuant;  // save the former quantity to use in the next loop
        totalQuant = 0;
        ticketPrice = 0;   //wipe out the value
    }
    cout << totalPrice;  //print the total price
    return 0;
}