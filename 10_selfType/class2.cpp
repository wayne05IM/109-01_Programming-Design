#include<iostream>
#include<cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    int id;
    int distOri()
    {
        return (pow(x,2) + pow(y,2));
    }
};

void vectorSort (const Point unsorted[], int sortedIndices [], int len);

int main()
{
    int pointNum = 0;
    cin >> pointNum;

    Point* points = new Point[pointNum];
    for(int i = 0; i < pointNum; i++)
        cin >> points[i].x;
    for(int i = 0; i < pointNum; i++)
        cin >> points[i].y;
    for(int i = 0; i < pointNum; i++)
        points[i].id = i + 1;

    int* sortedIndices = new int[pointNum]();
    vectorSort(points, sortedIndices, pointNum);
    delete [] points;

    for(int i = 0; i < pointNum; i++)
    {
        cout << sortedIndices[i];
        if(i != pointNum - 1)
            cout << " ";
    }

    return 0;
}

void vectorSort (const Point unsorted[], int sortedIndices [], int len)
{
    Point* sorted = new Point[len];

    for(int i = 0; i < len; i++)
        sorted[i] = unsorted[i];
    
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(sorted[j].distOri() < sorted[j - 1].distOri())
            {
                Point temp = sorted[j];
                sorted[j] = sorted[j - 1];
                sorted[j - 1] = temp;
            }
        else
            break;
        }
    }

    for(int i = 0; i < len; i++)
        sortedIndices[i] = sorted[i].id;
}