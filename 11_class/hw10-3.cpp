#include <iostream>
using namespace std;

class Option
{
private:
    int dimention;

public:
    int optionNum;
    int *targets;
    void init(int dim);
    bool isDominating(Option b);
    bool isBefore(Option b);
};

void Option::init(int dim)
{
    dimention = dim;
    targets = new int[dimention];
    cin >> optionNum;
    for (int i = 0; i < dimention; i++)
        cin >> targets[i];
};

bool Option::isDominating(Option b)
{
    bool TorF = true;
    for (int i = 0; i < dimention; i++)
    {
        if (targets[i] > b.targets[i])
            TorF = false;
    }
    return TorF;
};

bool Option::isBefore(Option b)
{
    if (optionNum < b.optionNum)
        return true;
    else
        return false;
};

void RankSort(Option OptionArray[], int optionAmount);

int main()
{
    //input and initialize
    int optionAmount = 0, dim = 0;
    cin >> optionAmount >> dim;

    Option OptionArray[optionAmount];
    for (int i = 0; i < optionAmount; i++)
        OptionArray[i].init(dim);

    //operation
    for (int i = 0; i < optionAmount; i++)
    {
        for (int j = 0; j < optionAmount; j++)
        {
            if (j != i)
            {
                if (OptionArray[j].optionNum == -1)
                    ;
                else
                {
                    if ((OptionArray[i].isDominating(OptionArray[j])) == true)
                    {
                        OptionArray[j].optionNum = -1;
                    }
                }
            }
        }
    }

    RankSort(OptionArray, optionAmount);

    for (int i = 0; i < optionAmount; i++)
    {
        if (OptionArray[i].optionNum == -1)
            ;
        else
        {
            if (i < optionAmount - 1)
            {
                for (int j = 0; j < dim - 1; j++)
                    cout << OptionArray[i].targets[j] << ",";
                cout << OptionArray[i].targets[dim - 1] << ";";
            }
            else
            {
                for (int j = 0; j < dim - 1; j++)
                    cout << OptionArray[i].targets[j] << ",";
                cout << OptionArray[i].targets[dim - 1];
            }
        }
    }

    return 0;
}

void RankSort(Option OptionArray[], int optionAmount)
{
    for (int i = 0; i < optionAmount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (OptionArray[j].isBefore(OptionArray[j - 1]))
            {
                Option temp = OptionArray[j];
                OptionArray[j] = OptionArray[j - 1];
                OptionArray[j - 1] = temp;
            }
            else
                break;
        }
    }
}