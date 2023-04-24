#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 10000;
const int MAX_D = 10000000;

int shortestPath(const int d[][MAX_N + 1], int s, int t, 
                 int n, int opt[][MAX_N + 1]);
int main()
{
  int n = 0, m = 0, s = 0, t = 0;
  cin >> n >> m >> s >> t;
  int d[MAX_N + 1][MAX_N + 1] = {0};
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      cin >> d[i][j];
      if(d[i][j] == -1)
        d[i][j] = MAX_D + 1; 
    }
  }
  
  int opt[MAX_N + 1][MAX_N + 1] = {0};  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
      opt[i][j] = MAX_D + 1;
  }
  
  //cout << s << " to " << t << ": " << shortestPath(d, s, t, n, opt) << "\n";
  cout << shortestPath(d, s, t, n, opt);
  
  return 0;
}

int shortestPath(const int d[][MAX_N + 1], int s, int t, 
                 int n, int opt[][MAX_N + 1])
{
  if(s == t)
    return 0;
  if(opt[s][t] != MAX_D + 1)
  {
    //cout << "   ";
    return opt[s][t];
  }
  
  int sp = MAX_D + 1;
  for(int i = 1; i <= n; i++)
  {
    if(d[i][t] != MAX_D + 1)
    {
      //cout << "solve " << s << " to " << i << "\n"; 
      int sp1 = shortestPath(d, s, i, n, opt);
      //cout << s << " to " << i << ": " << sp1 << "\n";
      if(sp1 + d[i][t] < sp)
        sp = sp1 + d[i][t];
    }
  }
  opt[s][t] = sp;
  return sp;
}