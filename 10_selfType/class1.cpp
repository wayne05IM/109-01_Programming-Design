#include<iostream>
using namespace std;

void bubbleSort (const int unsorted[], int sorted[], int len);
//void insertionSort (const int unsorted[], int sorted[], int len);

int main()
{
    int len = 0;
    cin >> len;
    int* unsorted = new int[len];
    for(int i = 0; i < len; i++)
        cin >> unsorted[i];

    int* sorted = new int[len]();
    bubbleSort(unsorted, sorted, len);
    //insertionSort(unsorted, sorted, len);

    for(int i = 0; i < len; i++)
    {
        cout << sorted[i];
        if(i != len - 1)
            cout << " ";
    }

    return 0;
}

void bubbleSort (const int unsorted[], int sorted[], int len)
{
    for(int i = 0; i < len; i++)
        sorted[i] = unsorted[i];

    int k = 0;
    while(k == 0)
    {
        k = 1;
        for(int i = 0; i < len - 1; i++)
        {
            if(sorted[i] > sorted[i + 1])
            {
                int temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
                k = 0;
            }
        }
    }
}

/*void insertionSort (const int unsorted[], int sorted[], int len)
{

}*/

/*const int LEN = 7;

void bubbleSort(const int unsorted[], int sorted[], int len);
void insertionSort(const int unsorted[], int sorted[], int len);

int main()
{
  int values[] = {7, 5, 3, 3, 9, 6, 7};
  int sorted[LEN] = {0};

  bubbleSort(values, sorted, LEN);
  for(int i = 0; i < LEN; i++)
    cout << values[i] << " ";
  cout << "\n";

  insertionSort(values, sorted, LEN);
  for(int i = 0; i < LEN; i++)
    cout << values[i] << " ";
  cout << "\n";  
 
  return 0;
}

void bubbleSort(const int unsorted[], int sorted[], int len)
{
  for(int i = 0; i < len; i++)
    sorted[i] = unsorted[i];
    
  for(int i = len - 1; i > 0; i--)
  {
    for(int j = 0; j < i; j++)
    {
      if(sorted[j] > sorted[j + 1])
      {
        int temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;
      }
    }
  }  
}

void insertionSort(const int unsorted[], int sorted[], int len)
{
  for(int i = 0; i < len; i++)
    sorted[i] = unsorted[i];
    
  for(int i = 0; i < len; i++)
  {
    for(int j = i; j > 0; j--)
    {
      if(sorted[j] < sorted[j - 1])
      {
        int temp = sorted[j];
        sorted[j] = sorted[j - 1];
        sorted[j - 1] = temp;
      }
      else
        break;
    }
  }    
}*/