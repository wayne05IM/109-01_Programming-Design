#include <iostream>
using namespace std;

int main()
{
    char a[1000] = {0} ;
    cin.getline(a, 1000);

    int num = 0;
    for(int i = 0; i < 1000; i++)
    {
        if((a[i] == ',') or (a[i] == '.') or (a[i] == ':') or (a[i] == ';') or (a[i] == '!') or (a[i] == '?'))
            num++;
    }
    cout << num;
    
    return 0;
}