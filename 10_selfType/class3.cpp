#include<iostream>
#include <cstdlib>
using namespace std;

int MAX = 10000;

void setRN (int rn [], int len);

int main()
{
    int len = 0;
    cin >> len;
    int* rn = new int[len]();

    setRN(rn, len);
    for(int i = 0; i < len; i++)
        cout << rn[i] <<" ";

    return 0;
}

void setRN (int rn [], int len)
{
    srand(time(nullptr));
    for(int i = 0; i < len; i++)
        rn[i] = rand() % MAX;
}
