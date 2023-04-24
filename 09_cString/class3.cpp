#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX = 1000;

int main()
{
    char sentence[MAX + 1] = {0};
    char insensitive[MAX + 1] = {0};

    cin.getline(sentence, MAX);
    cin.getline(insensitive, MAX);

    int len1 = strlen(sentence);
    for(int i = 0; i < len1; i++)
        sentence[i] = tolower(sentence[i]);

    int len2 = strlen(insensitive);
    for(int i = 0; i < len2; i++)
        insensitive[i] = tolower(insensitive[i]);

    if(strstr(sentence, insensitive) != nullptr)
        cout << 1;
    else
        cout << 0;
    
    return 0;
}