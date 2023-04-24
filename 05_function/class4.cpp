#include <iostream>
using namespace std;

const int GRADE_CNT_MAX = 50;

int highGradeCnt (int threshold, int gradeCnt , int grades[])
{
    int numberOfHighGrades = 0;
    for (int i = 0; i < gradeCnt; i++)
    {    
        if (grades[i] >= threshold)
            numberOfHighGrades ++;
    }
    return numberOfHighGrades;
}

int main()
{
    int threshold = 0, gradeCnt = 0;
    int grades[GRADE_CNT_MAX]; 
    
    cin >> gradeCnt >> threshold;
    for (int i = 0; i < gradeCnt; i++)
        cin >> grades[i];
    
    int numberOfHighGrades = highGradeCnt(threshold, gradeCnt, grades);
    cout << numberOfHighGrades;
    return 0;
}