#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, result = 0;
    cin >> a >> b >> c;
    
    if(a == b)
    {
        if(a == c)
            result = 1;
        else
            result = 2;   
    }
    else if(a == c)
    {
        if(a == b)
            result = 1;
        else
            result = 2;   
    }
    else if(b == c)
    {
        if(b == a)
            result = 1;
        else
            result = 2;   
    }
    else
        result = 3;

    cout << result;
    
    return 0;
}