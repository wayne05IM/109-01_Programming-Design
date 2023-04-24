#include <iostream>
using namespace std;

const int ASMNT_CNT_MAX = 10;
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

int mostHighGrades (int threshold, int asmntCnt , int gradeCnt , int grades[][GRADE_CNT_MAX])
{
    int bestAsmnt = 0;
    int bestHgc = 0;
    for (int i = 0; i < asmntCnt; i++)
    {    
        int hgc = highGradeCnt(threshold, gradeCnt , grades[i]);
        if(hgc > bestHgc)
        {
            bestAsmnt = i + 1;
            bestHgc = hgc;
        }
    }
    return bestAsmnt;
}

int main()
{
    int asmntCnt = 0, gradeCnt = 0, threshold = 0;
    int grades[ASMNT_CNT_MAX][GRADE_CNT_MAX] = {0}; 
    
    cin >> asmntCnt >> gradeCnt >> threshold;
    for (int i = 0; i < asmntCnt; i++)
    {
        for(int j = 0; j < gradeCnt; j++)
            cin >> grades[i][j];
    }
        
    int best = mostHighGrades (threshold, asmntCnt, gradeCnt, grades);
    cout << best;
    return 0;
}