#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t);
    void print();
};

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Time::print()
{
    cout << hour << ":" << minute << ":" << second;
}

/*bool Time::isEarlierThan (Time t)
{
    if(hour > t.hour)
        return true;
    else if(hour < t.hour)
        return false;
    else
    {
        if(minute > t.minute)
            return true;
        else if(minute < t.minute)
            return false;
        else
        {
            if(second > t.second)
                return true;
            else if(second < t.second)
                return false;
            else
                return false;
        }
    }
}*/

bool Time::isEarlierThan(Time t)
{
    int totalSecondSelf = hour * 3600 + minute * 60 + second;
    int totalSecondInput = t.hour * 3600 + t.minute * 60 + t.second;
    if (totalSecondSelf > totalSecondInput)
        return true;
    else
        return false;
}

int main()
{
    Time t1(14, 30, 0);
    Time t2(14, 25, 5);

    t1.print();
    cout << "\n";
    t2.print();

    return 0;
}