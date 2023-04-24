#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int WORD_MAX_LEN = 50;

int main()
{
    int wordNum = 0;
    cin >> wordNum;
    char word[WORD_MAX_LEN] = {0};
    cin >> word;
    int len = strlen(word);
    for(int i = 0; i < len; i++)
        word[i] = tolower(word[i]);

    char** dictionary = new char*[wordNum];
    for(int i = 0; i < wordNum; i++)
    {
        dictionary[i] = new char[i + 1];
        cin >> dictionary[i];
    }

    int compare = 0;
    for(int i = 0; i < wordNum; i++)
    {
        compare = strcmp(dictionary[i], word);
        if(compare == 0)
            break;
    }

    if(compare == 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}