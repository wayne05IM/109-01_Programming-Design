#include <iostream>
using namespace std;

/*
int main()
{
    int anInteger = 0;
    for(int i = 0; i < 10; i ++)
    {
        int anotherInteger = 0;
        cout << &anotherInteger << "---";

        int* aPtr = new int;
        cout << aPtr << "\n";
    }
    return 0;
}*/

int main()
{
    int anInteger = 0;
    for(int i = 0; i < 10; i ++)
    {
        int anotherInteger = i * 10;
        cout << &anotherInteger << "---";

        int* aPtr = new int;
        *aPtr = i * 100;
        cout << *aPtr << "!!!";
        cout << aPtr << "~~~";
        delete aPtr;
        cout << *aPtr << "\n";
    }
    return 0;
}