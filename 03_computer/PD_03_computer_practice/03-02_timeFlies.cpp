#include <iostream>
using namespace std;

int main()
{
  int hour = 0, min = 0, sec = 0, dur = 0;
  cin >> hour >> min >> sec >> dur;
  
  int beforeTime = hour * 3600 + min * 60 + sec;
  int afterTime = beforeTime + dur;
  
  int afterHour = afterTime / 3600;
  int afterMin = (afterTime - 3600 * afterHour) / 60;
  int afterSec = afterTime - 3600 * afterHour - afterMin * 60;
  
  cout << afterHour << ":" << afterMin << ":" << afterSec;
  
  return 0;
}
