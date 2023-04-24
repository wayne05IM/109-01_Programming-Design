#include <iostream>
#include <iomanip> 
using namespace std;

int main ()
{
    float a = 0, b = 0;

    cin >> a >> b;
    cout << a + b << endl;

    if ((a + b) == 0.3)
        cout << "a + b is 0.3.\n";
    else
        cout << "a + b is not 0.3.\n";

    cout << setprecision (10) << a + b;
    return 0;
}