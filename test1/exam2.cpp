#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    const int LONG = 100;
    int arrayX[LONG] = {0}, arrayY[LONG] = {0};
    for(int i = 0; i < n; i++)
        cin >> arrayX[i];
    for(int i = 0; i < m; i++)
        cin >> arrayY[i];
    
    if(n < m)
    {
        int min = 1001;
        for(int i = 0; i < n; i++)
        { 
            if(arrayX[i] < min)
                min = arrayX[i];
        }
        cout << min;
    }
    else if(n > m)
    {
        int min = 1001;
        for(int i = 0; i < m; i++)
        { 
            if(arrayY[i] < min)
                min = arrayY[i];
        }
        cout << min;
    }
    else
    {
        int dot = 0;
        for(int i = 0; i < m; i++)
        { 
            dot += arrayX[i] * arrayY[i];
        }
        cout << dot;
    }
    
    return 0;
}