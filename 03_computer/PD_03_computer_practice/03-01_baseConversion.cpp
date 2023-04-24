#include <iostream>
using namespace std;

int main()
{
  int value = 0, base = 0;
  cin >> value >> base;
  
  int aBit = 0;
  do
  {
    aBit = value % base;
    value = value / base;
  } while(value > 0);
  
  cout << aBit;
  
  return 0;
}
