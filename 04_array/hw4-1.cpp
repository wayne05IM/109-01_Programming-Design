#include <iostream>
using namespace std;

int main ()
{
    // input value
    int number = 0, ticketToBuy = 0;
    cin >> number >> ticketToBuy;

    int finalPrice = 0, finalQuant = 0;
    // input array
    const int MAX_GAP_AMOUNT = 11;
    int ticketQuantArray[MAX_GAP_AMOUNT] = {0}, ticketPriceArray[MAX_GAP_AMOUNT] = {0};
    for (int i = 0; i <= number; i++)
    {
        if (i == number)
        {
            cin >> ticketPriceArray[i];
            ticketQuantArray[i] = 100000;
        }
        else
            cin >> ticketQuantArray[i] >> ticketPriceArray[i];
    }
    
    int j = 0;
    for (int i = 0, cheaperPrice = 0, totalPrice = 0,firstPrice = 0, exQuant = 0; i <= number; i++)//do n times
    {
        if (ticketQuantArray[i] <= ticketToBuy)  // when the quantity is more than the total quantity
        {
            firstPrice += (ticketQuantArray[i] - exQuant) * ticketPriceArray[i];
        }
        else    // when the quantity is less than the total quantity
        {
            j ++;
            if (j == 1)
            {
                totalPrice = firstPrice;
                totalPrice += (ticketToBuy - exQuant) * ticketPriceArray[i];
                
                cheaperPrice = firstPrice;
                cheaperPrice += (ticketQuantArray[i] - exQuant) * ticketPriceArray[i];

                finalPrice = totalPrice;
                finalQuant = ticketToBuy;
            }
            else
            {
                cheaperPrice += (ticketQuantArray[i] - exQuant) * ticketPriceArray[i];
                
                if (cheaperPrice <= finalPrice)
                {
                    finalPrice = cheaperPrice;
                    finalQuant = ticketQuantArray[i];
                }
            }
        }
        exQuant = ticketQuantArray[i];
    }
    cout << finalQuant << "," << finalPrice << endl;  //print the final price
    return 0;
}