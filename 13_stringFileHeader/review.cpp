#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("temp.txt", ios::ate);
    file << "1,2,3 \n" << "4,5,6 ";
    file.close();

    return 0;
}