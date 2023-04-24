#include<iostream>
using namespace std;

int main()
{
    int len = 0;
    cin >> len;

    const int MAXLEN = 100;
    int numbers[MAXLEN] = {0};
    for(int i = 0; i < len; i++)
        cin >> numbers[i];

    int increasemaxlen = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            int temp = -1;
            //if(numbers[i] > numbers[j])
            //{
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            //}
            int k = 0; 
            while(k <= len - 1)
            {
                int increaselen = 1;
                while(numbers[k] < numbers[k + 1])
                {
                    increaselen++;
                    k++;
                    if(k == len - 1)
                        break;
                }
                //cout << i << " " << j << " " << k << " " << increaselen << "\n";
                /*if(increaselen != 0)
                    increaselen ++;*/
                if(increaselen > increasemaxlen)
                    increasemaxlen = increaselen;
                k++;
            }
            if(temp != -1)
            {
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
            
        }
    }

    cout << increasemaxlen;
    
    return 0;
}