#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX = 1000;

int main()
{
    char sentence[MAX + 1] = {0} ;
    cin.getline(sentence, MAX);

    int len = strlen(sentence);
    for(int i = 0; i < len; i++)
    {
        if((i == 0) or (sentence[i - 1] == ' ') or (ispunct(sentence[i - 1])))
            sentence[i] = toupper(sentence[i]);
        else
            sentence[i] = tolower(sentence[i]);
    }

    cout << sentence;
    
    return 0;
}