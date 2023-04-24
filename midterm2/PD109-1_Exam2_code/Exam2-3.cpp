#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 10000;

int main(){
    int s = 0;
    char* str = new char[LEN];
    cin >> s;
    cin.ignore(); //ignore '\n' in the first line
    cin.getline(str, LEN);

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
            cout << static_cast<char>((str[i]-97+s)%26+97);
        else
            cout << str[i];
    }
    cout << endl;
    return 0;
}