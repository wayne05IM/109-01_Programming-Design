#include <iostream>
using namespace std;

int min(int, int); 
int gcd(int, int);

int main()
{
  int a = 0, b = 0;
  cin >> a >> b;
  cout << gcd(a, b);
  return 0;
}

int min(int a, int b)
{
  return a <= b ? a : b; 
}

int gcd(int a, int b)
{
  int smaller = min(a, b);
  int bigger = a;
  if(smaller == a)
    bigger = b;
	
  for(int i = 1; i <= smaller; i++)
  {
    if(smaller % i == 0)
    {
      int maybeGcd = smaller / i;
      if(bigger % maybeGcd == 0)
        return maybeGcd;
    }
  }
}
