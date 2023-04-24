#include <iostream>
using namespace std;

/*int main()
{
    int hour = 0, minute = 0, second = 0, plusSecond = 0, totalSecond = 0;
    cin >> hour >> minute >> second >> plusSecond;

    totalSecond = hour * 3600 + minute * 60 + second + plusSecond;

    second = totalSecond % 60;
    minute = (totalSecond / 60) % 60;
    hour = totalSecond / 3600;

    cout << hour <<":"<< minute <<":"<< second;

    return 0;
}*/

int main()     //better solution
{
    int hour = 0, minute = 0, second = 0, secondDuration = 0;
    cin >> hour >> minute >> second >> secondDuration;

    int totalSecond = hour * 3600 + minute * 60 + second + secondDuration;

    int hourNew = totalSecond / 3600;
    int totalSecondRemain = totalSecond % 3600;
    int minuteNew = totalSecondRemain / 60;
    int secondNew = totalSecondRemain % 60; 

    cout << hourNew <<":"<< minuteNew <<":"<< secondNew;

    return 0;
}