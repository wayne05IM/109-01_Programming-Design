#include <iostream>
using namespace std;

int main()
{
    float maxTemp = 37;

    for (int time = 1 ; ; time++)
    {
        float cosTemp = 0;
        cin >> cosTemp;
        if ((time == 1) and (cosTemp < maxTemp)) //the first time and temperature < maximum temperature 
            cout << int(cosTemp);
        else if(cosTemp > maxTemp) //temperature > maximum temperature end loop
            break;
        else  //temperature < maximum temperature and not the first time
            cout << ","<< int(cosTemp);
    }
    return 0;
}