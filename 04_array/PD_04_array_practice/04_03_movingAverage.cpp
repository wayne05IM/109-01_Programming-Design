#include <iostream>
using namespace std;

int main()
{
  // Loading data
  int n = 0, m = 0;
  const int MAX_PERIOD_CNT = 1000;
  int x[MAX_PERIOD_CNT] = {0};
  
  cin >> n >> m;
  for(int i = 0; i < m; i++)
    cin >> x[i];
    
  // print out m - n + 1 values of forecasting
  for(int i = n; i <= m - 1; i++)
  {
    int totalDemand = 0;
    for(int j = i - n; j <= i - 1; j++)
      totalDemand += x[j];
    int avgDemand = totalDemand / n;
    cout << avgDemand << ",";
  }
  int totalDemand = 0;
  for(int j = m - n; j <= m - 1; j++)
    totalDemand += x[j];
  int avgDemand = totalDemand / n;
  cout << avgDemand;  
  
  return 0;
}
