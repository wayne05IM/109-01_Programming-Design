#include <iostream>
using namespace std;

int main()
{
  int n = 0, B = 0;
  cin >> n >> B;
  
  const int MAX_ITEM_CNT = 100;
  int w[MAX_ITEM_CNT] = {0};
  int v[MAX_ITEM_CNT] = {0};
  bool x[MAX_ITEM_CNT] = {0};

/*
  int* w = new int[n];
  for(int i = 0; i < n; i++)
    w[i] = 0;
  int* v = new int[n];
  for(int i = 0; i < n; i++)
    v[i] = 0;
  bool* x = new bool[n];
  for(int i = 0; i < n; i++)
    x[i] = 0;
*/

  for(int i = 0; i < n; i++)
    cin >> w[i];
  for(int i = 0; i < n; i++)
    cin >> v[i];
  for(int i = 0; i < n; i++)
    cin >> x[i];
    
  int totalWeight = 0;
  for(int i = 0; i < n; i++)
  {
    if(x[i] == true)
      totalWeight += w[i];
  }
  if(totalWeight > B)
    cout << 0;
  else
  {
    int totalValue = 0;
    for(int i = 0; i < n; i++)
    {
      if(x[i] == true)
        totalValue += v[i]; 
    }
    cout << totalWeight << " " << totalValue;
  }
  
  return 0;
}
