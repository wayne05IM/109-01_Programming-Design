#include<iostream>
using namespace std;

class Option
{
    private:
        int _id;
        int _size;
        int* values;
    public:
        Option();
        Option(const Option& opt);
        Option(const int _id, const int _size, const int* values);
        ~Option();
        bool isDominating(Option* b);
        bool isBefore(Option* b);
        void print();
        int getID(){ return this->_id; };
        int getValue(const int idx){ return this->values[idx]; };
};

void sortOption(Option* options[], const int optionNum);

int main()
{
    //handle input
    int n = 0, m = 0;
    cin >> n >> m;
    Option* options[n];
    for (int i = 0; i < n; i++)
    {
        int tmpId = 0;
        int* tmpValues = new int[m];
        cin >> tmpId;
        for (int j = 0; j < m; j++)
            cin >> tmpValues[j];
        options[i] = new Option(tmpId, m, tmpValues);
        delete [] tmpValues;
    }

    //sort options by idx
    sortOption(options, n);

    //find out points on pareto frontier
    int* paretoPointsIdxs = new int[n];
    int paretoPointsCnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool dominatingAll = true;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (options[j]->isDominating(options[i]))
            {
                dominatingAll = false;
                break;
            }
        }
        
        if (dominatingAll)
            paretoPointsIdxs[paretoPointsCnt++] = i;
    }
    
    //print pareto points
    for (int i = 0; i < paretoPointsCnt; i++)
    {
        int paretoPointIdx = paretoPointsIdxs[i];
        options[paretoPointIdx]->print();
        if (i != paretoPointsCnt - 1)
            cout << ";";
        else
            cout << endl;
    }

    //release memory
    for (int i = 0; i < n; i++)
    {
        delete options[i];
    }
    delete [] paretoPointsIdxs;
} 

//========function========

Option::Option()
{
    this->_id = 0;
    this->_size = 0;
    this->values = nullptr;
}

Option::Option(const Option& opt)
{
    this->_id = opt._id;
    this->_size = opt._size;
    this->values = new int[opt._size];
    for (int i = 0; i < opt._size; i++)
    {
        this->values[i] = opt.values[i];
    } 
}

Option::Option(const int _id, const int _size, const int* values)
{
    this->_id = _id;
    this->_size = _size;
    this->values = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        this->values[i] = values[i];
    }   
}

Option::~Option()
{
    delete [] this->values;
}


void Option::print()
{
    // cout << "(" << this->_id << ")";
    for (int i = 0; i < this->_size - 1; i++)
    {
        cout << this->values[i] << ",";
    }
    cout << this->values[this->_size - 1];
}

bool Option::isBefore(Option* b)
{
    return this->_id < b->getID();
}

bool Option::isDominating(Option* b)
{
    bool allEqualOrBetter = true;
    bool atLeastOneBetter = false;
    for (int i = 0; i < this->_size; i++)
    {
        if (this->values[i] > b->getValue(i))
        {
            allEqualOrBetter = false;
            break;
        }
        if (this->values[i] < b->getValue(i))
            atLeastOneBetter = true;
    }
    return allEqualOrBetter && atLeastOneBetter;
}

void sortOption(Option* options[], const int optionNum)
{
    for (int i = 0; i < optionNum; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (options[j]->isBefore(options[j-1]))
            {
                Option* tmpOpt = options[j-1];
                options[j-1] = options[j];
                options[j] = tmpOpt;
            }
        }
    }
}