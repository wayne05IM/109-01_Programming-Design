#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

int main()
{
    int s = 0;
    cin >> s;

    char b[2] = {0};
    cin.getline(b, 2);

    char sent[1000] = {0};
    cin.getline(sent, 1000);

    int len = strlen(sent);
    
    for(int i = 0; i < len; i++)
    {
        if(isalpha(sent[i]))
        {
            int temp = static_cast <int> (sent[i]);
            int k = 0;
            while(k < s)
            {
                temp++;
                k++;
                if(isalpha(static_cast <char> (temp)))
                    ;
                else
                    temp = static_cast<int>('a');
            }
            sent[i] = static_cast <char> (temp);
        }
    }
    cout << sent;

    return 0;
}