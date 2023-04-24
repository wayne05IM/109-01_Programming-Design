#include <iostream>
using namespace std;

int main ()
{
    // input value
    int gapNumber1 = 0, gapNumber2 = 0, ticketToBuy1 = 0, ticketToBuy2 = 0, limitFund = 0, buyingType = 0;
    cin >> gapNumber1 >> gapNumber2 >> ticketToBuy1 >> ticketToBuy2 >> limitFund >> buyingType;
    // input array1
    const int MAX_GAP_AMOUNT = 11;
    int ticketQuantArray1[MAX_GAP_AMOUNT] = {0}, ticketPriceArray1[MAX_GAP_AMOUNT] = {0};
    for (int i = 0; i <= gapNumber1; i++)
    {
        if (i == gapNumber1)
        {
            cin >> ticketPriceArray1[i];
            ticketQuantArray1[i] = 1000;
        }
        else
            cin >> ticketQuantArray1[i] >> ticketPriceArray1[i];
    }
    // input array2
    int ticketQuantArray2[MAX_GAP_AMOUNT] = {0}, ticketPriceArray2[MAX_GAP_AMOUNT] = {0};
    for (int i = 0; i <= gapNumber2; i++)
    {
        if (i == gapNumber2)
        {
            cin >> ticketPriceArray2[i];
            ticketQuantArray2[i] = 1000;
        }
        else
            cin >> ticketQuantArray2[i] >> ticketPriceArray2[i];
    }
    //totalTicketPrice1
    int totalTicketPrice1 = 0;
    for (int i = 0, exQuant = 0; i <= gapNumber1; i++)//do n times
    {
        if (ticketQuantArray1[i] <= ticketToBuy1)  // when the quantity is more than the total quantity
            totalTicketPrice1 += (ticketQuantArray1[i] - exQuant) * ticketPriceArray1[i];
        else    // when the quantity is less than the total quantity
        {
            totalTicketPrice1 += (ticketToBuy1 - exQuant) * ticketPriceArray1[i];
            break;
        }
        exQuant = ticketQuantArray1[i];  // save the former quantity to use in the next loop  
    }
    //totalTicketPrice2
    int totalTicketPrice2 = 0;
    for (int i = 0, exQuant = 0; i <= gapNumber2; i++)//do n times
    {
        if (ticketQuantArray2[i] <= ticketToBuy2)  // when the quantity is more than the total quantity
            totalTicketPrice2 += (ticketQuantArray2[i] - exQuant) * ticketPriceArray2[i];
        else    // when the quantity is less than the total quantity
        {
            totalTicketPrice2 += (ticketToBuy2 - exQuant) * ticketPriceArray2[i];
            break;
        }
        exQuant = ticketQuantArray2[i];  // save the former quantity to use in the next loop 
    }

    int idealPrice = totalTicketPrice1 + totalTicketPrice2, totalTicketQuant1 = 0, totalTicketQuant2 = 0;
    // idealPrice can be satisfied
    if (idealPrice <= limitFund)
        cout << ticketToBuy1 << "," << ticketToBuy2 << "," << idealPrice;
    // idealPrice can not be satisfied
    else
    {
        totalTicketPrice1 = 0;
        totalTicketPrice2 = 0;
        // buyingType = 0
        if (buyingType == 0)
        {
            int totalTicketPrice = 0, totalTicketTemp = 0;
            for (int i = 0, exQuant = 0, preQuant = 0; i <= MAX_GAP_AMOUNT; i++)
            {
                if((ticketQuantArray1[i + 1] != 0) and (ticketQuantArray2[i + 1] != 0))
                {
                    if (ticketPriceArray1[i] > ticketPriceArray2[i])
                    {
                        for (int j = 0; j < ticketQuantArray2[i] - preQuant; j++)
                        {
                            limitFund -= ticketPriceArray2[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray2[i];
                                totalTicketQuant2 += 1;
                                exQuant += 1;
                            } 
                            else    
                                i = MAX_GAP_AMOUNT + 1;
                        } 
                        preQuant = exQuant;
                        if ((ticketQuantArray1[i] > ticketQuantArray2[i]) and (i != MAX_GAP_AMOUNT + 1))
                        {
                            if(ticketPriceArray2[i + 1] > ticketPriceArray1[i])
                            {
                                for (int j = 0; j < ticketQuantArray1[i] - preQuant; j++)
                                {
                                    limitFund -= ticketPriceArray1[i];
                                    if (limitFund >= 0)
                                    {
                                        totalTicketPrice += ticketPriceArray1[i];
                                        totalTicketQuant1 += 1;
                                        exQuant += 1;
                                    }
                                    else
                                        i = MAX_GAP_AMOUNT + 1;
                                }
                                preQuant = exQuant;
                            }
                        }
                    }
                    else if (ticketPriceArray1[i] < ticketPriceArray2[i])
                    {
                        for (int j = 0; j < ticketQuantArray1[i] - preQuant; j++)
                        {
                            limitFund -= ticketPriceArray1[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray1[i];
                                totalTicketQuant1 += 1;
                                exQuant += 1;
                            }
                            else
                                i = MAX_GAP_AMOUNT + 1;
                        }
                        preQuant = exQuant;
                        if ((ticketQuantArray2[i] > ticketQuantArray1[i]) and (i != MAX_GAP_AMOUNT + 1))
                        {
                            if(ticketPriceArray1[i + 1] > ticketPriceArray2[i])
                            {
                                for (int j = 0; j < ticketQuantArray2[i] - preQuant; j++)
                                {
                                    limitFund -= ticketPriceArray2[i];
                                    if (limitFund >= 0)
                                    {
                                        totalTicketPrice += ticketPriceArray2[i];
                                        totalTicketQuant2 += 1; 
                                        exQuant += 1;
                                    }
                                    else
                                        i = MAX_GAP_AMOUNT + 1;
                                } 
                                preQuant = exQuant;
                            }
                        }
                    }
                    else
                    {
                        int ticketQuantTemp = 0;
                        if(ticketQuantArray1[i] > ticketQuantArray2[i])
                            ticketQuantTemp = ticketQuantArray1[i];
                        else
                            ticketQuantTemp = ticketQuantArray2[i];
                        cout << preQuant << ticketQuantTemp;
                        for (int j = 0; j < ticketQuantTemp - preQuant; j++)
                        {
                            limitFund -= ticketPriceArray2[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray1[i];
                                totalTicketTemp += 1;
                                exQuant += 1;
                            }   
                            else
                                i = MAX_GAP_AMOUNT + 1;
                        }
                        preQuant = exQuant;
                    }   
                }
                else if((ticketQuantArray1[i + 1] == 0) and (ticketQuantArray2[i + 1] == 0))
                {
                    if(ticketPriceArray1[i] > ticketPriceArray2[i])
                    {
                        for (int j = 0; ; j++)
                        {
                            limitFund -= ticketPriceArray2[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray2[i];
                                totalTicketQuant2 += 1;
                            }
                            else
                            {
                                i = MAX_GAP_AMOUNT + 1;
                                break;
                            }
                        }
                    }
                    else if(ticketPriceArray1[i] < ticketPriceArray2[i])
                    {
                        for (int j = 0; ; j++)
                        {
                            limitFund -= ticketPriceArray1[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray1[i];
                                totalTicketQuant1 += 1;
                            }
                            else
                            {
                                i = MAX_GAP_AMOUNT + 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; ; j++)
                        {
                            limitFund -= ticketPriceArray1[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray1[i];
                                totalTicketTemp += 1;
                            }
                            else
                            {
                                i = MAX_GAP_AMOUNT + 1;
                                break;
                            }
                        }
                    }
                }
                else if((ticketQuantArray1[i] == 0) or (ticketQuantArray2[i] == 0))
                {
                    if((ticketQuantArray1[i] != 0) and (ticketQuantArray2[i] == 0))
                    {
                        for (int j = 0; j < ticketQuantArray1[i] - preQuant; j++)
                        {
                            limitFund -= ticketPriceArray1[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray1[i];
                                totalTicketQuant1 += 1;
                                exQuant += 1;
                            }
                            else
                                i = MAX_GAP_AMOUNT + 1;
                        }
                        preQuant = exQuant;
                    }
                    else if((ticketQuantArray1[i] == 0) and (ticketQuantArray2[i] != 0))
                    {
                        for (int j = 0; j < ticketQuantArray2[i] - preQuant; j++)
                        {
                            limitFund -= ticketPriceArray2[i];
                            if (limitFund >= 0)
                            {
                                totalTicketPrice += ticketPriceArray2[i];
                                totalTicketQuant2 += 1;
                                exQuant += 1;
                            }
                            else
                                i = MAX_GAP_AMOUNT + 1;
                        }
                        preQuant = exQuant;
                    }
                    else if((ticketQuantArray1[i] == 0) and (ticketQuantArray2[i] == 0))
                        i = MAX_GAP_AMOUNT + 1;
                }       
            }
            for (int k = 0; k < totalTicketTemp; k++)
            {
                int case1 = (totalTicketQuant1 + 1) * totalTicketQuant2;
                int case2 = (totalTicketQuant2 + 1) * totalTicketQuant1;
                if (case1 >= case2)
                    totalTicketQuant1 += 1;
                else
                    totalTicketQuant2 += 1;
            }
            cout << totalTicketQuant1 << "," << totalTicketQuant2 << "," << totalTicketPrice;
        }
        // buyingType = 1
        if (buyingType == 1)
        {
            // maximize the totalTicketPrice1
            for (int i = 0, exQuant = 0; i <= gapNumber1; i++)
            {
                for(int j = 1; j <= (ticketQuantArray1[i] - exQuant); j++)
                {
                    limitFund -= 1 * ticketPriceArray1[i];
                    if (limitFund >= 0)
                    {
                        totalTicketPrice1 += 1 * ticketPriceArray1[i];
                        totalTicketQuant1 += 1;
                    }
                    else 
                    {
                        limitFund += 1 * ticketPriceArray1[i];
                        i = gapNumber1 + 1;
                        break;
                    }
                }
                exQuant = ticketQuantArray1[i];
            }
            // maximize the totalTicketPrice2
            for (int i = 0, exQuant = 0; i <= gapNumber2; i++)
            {
                for(int j = 1; j <= (ticketQuantArray2[i] - exQuant); j++)
                {
                    limitFund -= 1 * ticketPriceArray2[i];
                    if (limitFund >= 0)
                    {
                        totalTicketPrice2 += 1 * ticketPriceArray2[i];
                        totalTicketQuant2 += 1;
                    }
                    else 
                    {
                        limitFund += 1 * ticketPriceArray2[i];
                        i = gapNumber2 + 1;
                        break;
                    }
                }
                exQuant = ticketQuantArray2[i];
            }
            cout << totalTicketQuant1 << "," << totalTicketQuant2 << "," << totalTicketPrice1 + totalTicketPrice2;
        }
        // buyingType = 2
        else if (buyingType == 2)
        {
            // maximize the totalTicketPrice2
            for (int i = 0, exQuant = 0; i <= gapNumber2; i++)
            {
                for(int j = 1; j <= (ticketQuantArray2[i] - exQuant); j++)
                {
                    limitFund -= 1 * ticketPriceArray2[i];
                    if (limitFund >= 0)
                    {
                        totalTicketPrice2 += 1 * ticketPriceArray2[i];
                        totalTicketQuant2 += 1;
                    }
                    else 
                    {
                        limitFund += 1 * ticketPriceArray2[i];
                        i = gapNumber2 + 1;
                        break;
                    }
                }
                exQuant = ticketQuantArray2[i];
            }
            // maximize the totalTicketPrice1
            for (int i = 0, exQuant = 0; i <= gapNumber1; i++)
            {
                for(int j = 1; j <= (ticketQuantArray1[i] - exQuant); j++)
                {
                    limitFund -= 1 * ticketPriceArray1[i];
                    if (limitFund >= 0)
                    {
                        totalTicketPrice1 += 1 * ticketPriceArray1[i];
                        totalTicketQuant1 += 1;
                    }
                    else 
                    {
                        limitFund += 1 * ticketPriceArray1[i];
                        i = gapNumber1 + 1;
                        break;
                    }
                }
                exQuant = ticketQuantArray1[i];
            }
            cout << totalTicketQuant1 << "," << totalTicketQuant2 << "," << totalTicketPrice1 + totalTicketPrice2;
        }
    }
    return 0;
}