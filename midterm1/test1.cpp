#include <iostream>
using namespace std;

int main()
{
    int big = 0, medium = 0, small = 0;
    cin >> big >> medium >> small;
    
    if(big < small)
    {
        int temp = big;
        big = small;
        small = temp;
    }
    if(big < medium)
    {
        int temp = big;
        big = medium;
        medium = temp;
    }
    if(medium < small)
    {
        int temp = medium;
        medium = small;
        small = temp;
    }
    cout << medium;
    
    return 0;
}