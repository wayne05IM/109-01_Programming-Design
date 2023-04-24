#include <iostream>
#include <cmath>
using namespace std;

/*int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    for (int x = 0; x <= 5; x++)
    {
        if ((x == x1) or (x == x2) or (x == x3))
            continue;
        for (int y = 0; y <= 5; y++)
        {
            if ((y == y1) or (y == y2) or (y == y3))
              continue;
            else if((abs(x - x1) == abs(y - y1)) 
                    or (abs(x - x2) == abs(y - y2)) 
                    or (abs(x - x3) == abs(y - y3)))
              continue;
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}*/


int main()        //better answer
{
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  
  int xMax = 5, yMax = 5;
  
  for(int x = 0; x <= xMax; x++)
  {
    for(int y = 0; y <= yMax; y++)
    {
      bool isSafe = true;
      if(x == x1 || x == x2 || x == x3)
        isSafe = false;
      else if(y == y1 || y == y2 || y == y3)
        isSafe = false;
      else if(abs(x - x1) == abs(y - y1) ||
              abs(x - x2) == abs(y - y2) ||
              abs(x - x3) == abs(y - y3))
        isSafe = false;
      
      if(isSafe == true)
        cout << x << " " << y << "\n";
    }
  }
  
  return 0;
}