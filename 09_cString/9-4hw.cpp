#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

// Function to remove all spaces from a given string 
void removeSpaces(char *str) 
{ 
    // To keep track of non-space character count 
    int count = 0; 
  
    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is 
    }
    
    // incremented 
    str[count] = '\0'; 
}

int main()
{
    //input
    int airportAmount = 0, airlineAmount = 0;
    cin >> airportAmount >> airlineAmount;
    cin.ignore();

    char nameString[400] = {0};
    char** airportName = new char*[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        airportName[i] = new char[3];
    cin.getline(nameString, 400);
    char* address = strtok(nameString, " ");
    int i = 0;
    while (address != nullptr)
    {
        i++;
        airportName[i] = address;
        address = strtok (nullptr, " ");
    }

    int* airportCost = new int[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        cin >> airportCost[i];
    cin.ignore();

    int** airlineProfit = new int*[airportAmount + 1];
    for(int i = 1; i <= airportAmount; i++)
        airlineProfit[i] = new int[airportAmount + 1];
    for(int i = 0; i < airlineAmount; i++)
    {
        char airlineString[1000];
        cin.getline(airlineString, 1000);
        removeSpaces(airlineString);
        for(int j = 0; i < strlen(airlineString);j++)
            airlineString[j] = toupper(airlineString[j]);
        //cout << airlineString;

        int start = 0, end = 0;
        char* address = strtok(airlineString, "\"");
        if(address != nullptr)
        {
            address = strtok(nullptr, "\"");
            for(int k = 1; k <= airportAmount; k++)
            {
                if(strcmp(address, airportName[k]) == 0)
                {
                    start = k;
                    break;
                }
            }
        }
        cout << start << endl;
        address = strtok(nullptr, "\"");
        if(address != nullptr)
        {
            address = strtok(nullptr, "\"");
            for(int k = 1; k <= airportAmount; k++)
            {
                if(strcmp(address, airportName[k]) == 0)
                {
                    end = k;
                    break;
                }
            }
        }
        cout << end << endl;
        if(address != nullptr)
        {
            address = strtok(nullptr, "\"");
            int profit = 0;
            profit = atoi(address);
            airlineProfit[start][end] = profit;
            airlineProfit[end][start] = profit;
        }
    }

    //data analysis

    return 0;
}