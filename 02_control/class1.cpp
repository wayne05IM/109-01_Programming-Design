#include<iostream>
using namespace std;

/*int main()
{
    int gender = 0, age = 0;
    cin >> gender >> age;
    if (gender == 0)
    {
        if (age >= 16)
            cout << "Yes";
        else
            cout << "No";
    }
    if (gender == 1)
    {
        if (age >= 18)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}*/

int main()       //better answer
{
    int gender = 0, age = 0;
    cin >> gender >> age;

    int minAgeForMale = 18;
    int minAgeForFemale = 16;
    int codeForMale = 1;
    int codeForFemale = 0;
    
    if ((gender == codeForFemale and age >= minAgeForFemale) or
        (gender == codeForMale and age >= minAgeForMale))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}