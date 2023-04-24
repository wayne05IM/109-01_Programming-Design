#include <iostream>
using namespace std;

class MyVector
{
private:
    int n;
    int* m;

public:
    MyVector();
    MyVector(int dim, int value = 0);
    ~MyVector();
    void print();
};

MyVector::MyVector()
{
    n = 0;
    m = nullptr;
};

MyVector::MyVector(int dim, int value)
{
    n = dim;
    m = new int[n];
    for(int i = 0; i < n; i++)
        m[i] = value;
};

void MyVector::print()
{
    cout << "dim : " << n << endl;
    cout << "vector : " << "(";
    for(int i = 0; i < n - 1; i++)
        cout << m[i] << ",";
    cout << m[n - 1] << ")";
};

MyVector::~MyVector()
{
    delete [] m;
};

int main()
{
    int dim = 0, initVect = 0;
    cin >> dim >> initVect;
    MyVector a(dim, initVect);
    a.print();
    return 0;
}