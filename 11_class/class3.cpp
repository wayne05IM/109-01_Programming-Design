#include <iostream>
using namespace std;

class Time
{
private:
    static bool hourIn12;
    int hour;
    int minute;
    int second;
    void printTwoDigits(int n);
    
public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t);
    void print();
    static void set12Hour(bool in12);
    void printNicely();
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

int main()
{
    Time t1(14, 30, 0);
    Time t2(14, 25, 5);

    t1.printNicely(); // 14:30:00
    cout << "n";

    Time::set12Hour(true);

    t1.printNicely(); // 02:30:00 PM

    return 0;
}