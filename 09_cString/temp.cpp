#include <iostream>
using namespace std;

int main()
{
    //input
    int buyerNum = 0;
    cin >> buyerNum;

    const int MAX_BUYERS = 21;
    int buyer[MAX_BUYERS] = {0};
    for(int i = 1; i <= buyerNum; i++)
        cin >> buyer[i];

    int Deadline[MAX_BUYERS] = {0};
    for(int i = 1; i <= buyerNum; i++)
        cin >> Deadline[i];

    //sorting
    bool again = true;
    while(again)
    {
        again = false;
        for(int i = 1; i < buyerNum; i++)
        {
            if(Deadline[i] > Deadline[i + 1])
            {
                int temp1 = Deadline[i];
                Deadline[i] = Deadline[i + 1];
                Deadline[i + 1] = temp1;

                int temp2 = buyer[i];
                buyer[i] = buyer[i + 1];
                buyer[i + 1] = temp2;
                again = true;
            }
            else if(Deadline[i] == Deadline[i + 1])
            {
                if((buyer[i] > buyer[i + 1]))
                {
                    int temp1 = Deadline[i];
                    Deadline[i] = Deadline[i + 1];
                    Deadline[i + 1] = temp1;

                    int temp2 = buyer[i];
                    buyer[i] = buyer[i + 1];
                    buyer[i + 1] = temp2;
                    again = true;
                }
            }
        }
    }

    for(int i = 1; i <= buyerNum; i++)
        cout << buyer[i] << " ";
    cout << endl;
    for(int i = 1; i <= buyerNum; i++)
        cout << Deadline[i] << " ";

    return 0;
    /*
    for(int i = 2; i <= buyerNum; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(Deadline[i] == Deadline[i - j])
            {
                if(buyer[i] < buyer[i - j])
                {
                    int temp1 = Deadline[i];
                    Deadline[i] = Deadline[i - j];
                    Deadline[i - j] = temp1;

                    int temp2 = buyer[i];
                    buyer[i] = buyer[i - j];
                    buyer[i - j] = temp2;
                }
                else
                {
                    int temp1 = Deadline[i];
                    Deadline[i] = Deadline[i - j + 1];
                    Deadline[i - j + 1] = temp1;

                    int temp2 = buyer[i];
                    buyer[i] = buyer[i - j + 1];
                    buyer[i - j + 1] = temp2;
                }
                break;
            }
            else if(Deadline[i] > Deadline[i - j])
            {
                int temp1 = Deadline[i];
                Deadline[i] = Deadline[i - j + 1];
                Deadline[i - j + 1] = temp1;

                int temp2 = buyer[i];
                buyer[i] = buyer[i - j + 1];
                buyer[i - j + 1] = temp2;
                break;
            }
        }
    }

    for(int i = 2; i <= buyerNum; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(Deadline[i] < Deadline[i - j])
            {
                int temp1 = Deadline[i];
                Deadline[i] = Deadline[i - j];
                Deadline[i - j] = temp1;

                int temp2 = buyer[i];
                buyer[i] = buyer[i - j];
                buyer[i - j] = temp2;
            }
            else if(Deadline[i] == Deadline[i - j])
            {
                if(buyer[i] < buyer[i - j])
                {
                    int temp1 = Deadline[i];
                    Deadline[i] = Deadline[i - j];
                    Deadline[i - j] = temp1;

                    int temp2 = buyer[i];
                    buyer[i] = buyer[i - j];
                    buyer[i - j] = temp2;
                }
                break;
            }
            else
                break;
        }
    }*/
     
}